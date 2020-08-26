/*
 *Implementation of the Reverse Cuthill-Mckee Algorithm in c 
 *
 *Author: Doinakis Michail
 *e-mail: doinakis@ece.auth.gr
 */

#include "../inc/rcm_cilk.h"


void permutationInit(permutation *R,int n){

    R->index = 0;
    R->perm = (int *)calloc(n,sizeof(int));
}

void permutationDelete(permutation *R){

    free(R->perm);
    free(R);
}

void degreeCalculation(int n, node *nodes,int *rows,int *cols,int *total_elements){
    
    // As degree of each node is considered the #neighbors
    for(int i=0; i<n; i++){
        if(rows[i] != cols[i]){
            nodes[rows[i]].degree += 1;
            nodes[cols[i]].degree += 1;
            *total_elements+=2;
        }
    }
}

void minimumNode(int n,int *minNode,node *nodes,queue *Q){

    int min = 0;
    int first_time = 1;
    // Find the node with the minimum degree
    for(int i=0; i<n; i++){
        if(first_time == 1 && nodes[i].inside_perm == false){
            first_time = 0;
            min = i;
        }
        if(nodes[i].degree < nodes[min].degree && nodes[i].inside_perm == false && nodes[min].inside_perm == false){
            min = i;
        }
    }
    *minNode = min;
    nodes[min].inside_q = true;

    queueAdd(Q, nodes[min]);

}

void findAllNeighbors(int n,int nz,int *rows,int *cols,node *nodes,int *total_elements,int **neighbors){

    // Find all the neighbors in advance 
    int *counter = (int *)calloc(n,sizeof(int));
    neighbors[0] = (int *)malloc((*total_elements)*sizeof(int));
    for(int i=1;i<n;i++){
        neighbors[i] = neighbors[i-1] + nodes[i-1].degree;
    }
    for(int i=0;i<nz;i++){
        if(rows[i]!=cols[i]){
            // Because we only have the lower part of the matrix whenever we add a neighbor we add its symmetric too
            neighbors[rows[i]][counter[rows[i]]++] = cols[i];
            neighbors[cols[i]][counter[cols[i]]++] = rows[i];
        }
    }
    free(counter);
}

void findNeighbors(int nz,int numberOfnode,int *rows,int *cols,node *nodes,queue *Q,queue *temp_neighbors,int **neighbors){

    // Counter that holds how many neighbors are found 
    int counter = 0;
    node del;
    // Find the neighbors of the corresponding node
    for(int i=0; i<nodes[numberOfnode].degree; i++){
        // If the nodes are neighbors matrix(numberOfnodes,i) == 1 and the node is not in the Queue or the permutation

        if(nodes[neighbors[numberOfnode][i]].inside_perm == false && nodes[neighbors[numberOfnode][i]].inside_q == false ){
            nodes[neighbors[numberOfnode][i]].inside_q = true;

            // Add the node as a neighbor of numberOfnode
            queueAdd(temp_neighbors,nodes[neighbors[numberOfnode][i]]);  
            counter++;
        }
    }
    // Sort the neighbors acording to their degree and add them in the Q queue in increasing order of degree
    queueSort(temp_neighbors);
    for(int i=0; i<counter; i++){
        queueDel(temp_neighbors,&del);
        queueAdd(Q,del);
    }

}

void Cuthill_Mckee_cilk(int n,int nz,int *rows,int *cols,permutation *R){

    // Initialize an array of n nodes
    node *nodes = nodeInit(n);
    int nodes_added = 0;
    int *minNode = (int *)malloc(sizeof(int));
    *minNode = 0;
    int *total_elements = (int *)malloc(sizeof(int));
    *total_elements = 0;
    int **neighbors =(int **)malloc(n*sizeof(int *));

    // Queue where the nodes wait to be added in the permutation
    queue *Q = queueInit(n);

    // Queue that holds the neighbors of the node added in the permutation
    queue *temp_neighbors = queueInit(n);

    // Node extracted from Q and added in the permutation
    node extracted_node;

    // Calcutation of all the degrees
    degreeCalculation(nz,nodes,rows,cols,total_elements);

    // Find all the neighbors in advance
    findAllNeighbors(n,nz,rows,cols,nodes,total_elements,neighbors);
    
    // Find the node with the minimum degree and its neighbors 
    minimumNode(n,minNode,nodes,Q);

    // While the Q is not empty 
    while(!Q->empty){
        // Extract the first node in the Q
        queueDel(Q,&extracted_node);
        nodes[extracted_node.num].inside_perm = true;

        // Add the node to the permutation
        R->perm[R->index++] = extracted_node.num;
        nodes_added++;
        
        // Find the neighbors of the extracted node and add them in increasing order of degree in the Q
        findNeighbors(nz,extracted_node.num,rows,cols,nodes,Q,temp_neighbors,neighbors);
        if(Q->empty == 1 && nodes_added != n){
            minimumNode(n,minNode,nodes,Q);
        }
    }
    // Deallocate the space used and no longer needed 
    queueDelete(Q);
    queueDelete(temp_neighbors);
    nodeDelete(nodes);
    free(minNode);
    free(neighbors[0]);
    free(neighbors);
    free(total_elements);
    

}
// Reverse the indices in the permutation array

void R_Cuthill_Mckee_cilk(int n,int nz,int *rows,int *cols,permutation *R){

    Cuthill_Mckee_cilk(n,nz,rows,cols,R);
    /* 
        Value to hold how many swaps are going to happen 
        if n is even then the number of swaps needed is floor((n-1)/2)+1
        else is floor(n/2)+1
    */
    int new_n = n;
    new_n = new_n/2;
    
    int temp;
    // Apply the swap
    // #pragma simd
    cilk_for(int i=0; i<new_n; i++){
        temp = R->perm[n-i-1];
        R->perm[n-i-1] = R->perm[i];
        R->perm[i] = temp;

    }

}

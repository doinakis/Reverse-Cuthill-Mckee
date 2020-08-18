#include "rcm.h"



void degreeCalculation(int n, node *nodes,int *matrix){

    // As degree of each node is considered the #neighbors
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            nodes[i].num = i;
            nodes[i].degree += matrix(i,j);
            nodes[i].inside_perm = false;
            nodes[i].inside_q = false;
        }
    }
}

void minimumNode(int n,int *minNode,node *nodes,queue *permutation){
    int min = 0;
    // Find the node with the minimum degree
    for(int i=1; i<n; i++){
        if(nodes[i].degree < nodes[min].degree){
            min = i;
        }
    }
    *minNode = min;
    nodes[min].inside_perm = true;
    // Add the node in the permutation
    queueAdd(permutation,nodes[min]);
}

void findNeighbors(int n,int numberOfnode,int *matrix,node *nodes,queue *Q,queue *neighbors){
    // Counter that holds how many neighbors are found 
    int counter = 0;
    node del;
    // Find the neighbors of the corresponding node
    for(int i=0; i<n; i++){
        // If the nodes are neighbors matrix(numberOfnodes,i) == 1 and the node is not in the Queue or the permutation
        if(matrix(numberOfnode,i) == 1 && nodes[i].inside_q == false && nodes[i].inside_perm == false){
            nodes[i].inside_q = true;
            // Add the node as a neighbor of numberOfnode
            queueAdd(neighbors,nodes[i]);  
            counter++;
        }
    }
    // Sort the neighbors acording to their degree and add them in the Q queue in increasing order of degree
    queueSort(neighbors);
    for(int i=0; i<counter; i++){
        queueDel(neighbors,&del);
        queueAdd(Q,del);
        
    }
}

void Cuthill_Mckee(int n, int *matrix,queue *permutation){
    
    // Initialize an array of n nodes
    node *nodes = nodeInit(n);

    // Pointer to the minNode 
    int *minNode = (int *)malloc(sizeof(int));
    *minNode = 0;
    
    // Queue where the nodes wait to be added in the permutation
    queue *Q = queueInit();

    // Queue that holds the neighbors of the node added in the permutation
    queue *neighbors = queueInit();

    // Node extracted from Q and added in the permutation
    node extracted_node;

    // Calcutation of all the degrees
    degreeCalculation(n,nodes,matrix);

    printf("Degrees: ");
    for(int i=0; i<10; i++){
        printf("%d ",nodes[i].degree);
    }

    // Find the node with the minimum degree and its neighbors 
    minimumNode(n,minNode,nodes,permutation);
    findNeighbors(n,*minNode,matrix,nodes,Q,neighbors);
    // int counter = 0;
    // While the Q is not empty 
    while(!Q->empty){
        // Extract the first node in the Q
        queueDel(Q,&extracted_node);
        // Add the node to the permutation
        queueAdd(permutation,extracted_node);
        // Find the neighbors of the extracted node and add them in increasing order of degree in the Q
        findNeighbors(n,extracted_node.num,matrix,nodes,Q,neighbors);
        // counter++;
    }
    // Deallocate the space used and no longer needed 
    queueDelete(Q);
    queueDelete(neighbors);
    nodeDelete(nodes);
    free(minNode);
}
// Reverse the indices in the permutation array

void R_Cuthill_Mckee(int n, queue *permutation){

    /* Value to hold how many swaps are going to happen 
        if n is even then the number of swaps needed is floor((n-1)/2)+1
        else is floor(n/2)+1
    */
    int new_n = n;
    if(new_n%2 == 0){
        new_n-=1;
    }
    new_n = new_n/2;
    
    node temp;
    // Apply the swap
    for(int i=0; i<=new_n; i++){
        temp = permutation->buf[n-i-1];
        permutation->buf[n-i-1] = permutation->buf[i];
        permutation->buf[i] = temp;

    }
}
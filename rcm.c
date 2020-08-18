#include "rcm.h"



void degreeCalculation(int n, node *nodes,int *matrix){
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

    for(int i=1; i<n; i++){
        if(nodes[i].degree < nodes[min].degree){
            min = i;
        }
    }
    *minNode = min;
    nodes[min].inside_perm = true;
    queueAdd(permutation,nodes[min]);
}

void findNeighbors(int n,int numberOfnode,int *matrix,node *nodes,queue *Q,queue *neighbors){
    
    int counter = 0;
    node del;
    for(int i=0; i<n; i++){
        if(matrix(numberOfnode,i) == 1 && nodes[i].inside_q == false && nodes[i].inside_perm == false){
            nodes[i].inside_q = true;
            queueAdd(neighbors,nodes[i]);  
            counter++;
        }
    }
    queueSort(neighbors);
    for(int i=0;i<counter;i++){
        queueDel(neighbors,&del);
        queueAdd(Q,del);
        
    }
}

void Cuthill_Mckee(int n, int *matrix,queue *permutation){
    node *nodes = nodeInit(n);
    int *minNode = (int *)malloc(sizeof(int));
    *minNode = 0;
    
    queue *Q = queueInit();
    queue *neighbors = queueInit();
    node extracted_node;
    degreeCalculation(n,nodes,matrix);
    printf("Degrees: ");
    for(int i=0; i<10; i++){
        printf("%d ",nodes[i].degree);
    }
    
    minimumNode(n,minNode,nodes,permutation);
    findNeighbors(n,*minNode,matrix,nodes,Q,neighbors);
    int counter = 0;
    while(!Q->empty){
        queueDel(Q,&extracted_node);
        queueAdd(permutation,extracted_node);
        findNeighbors(n,extracted_node.num,matrix,nodes,Q,neighbors);
        counter++;
    }
    queueDelete(Q);
    queueDelete(neighbors);
    nodeDelete(nodes);
    free(minNode);
}
void R_Cuthill_Mckee(int n, queue *permutation){
    int new_n = n;
    if(new_n%2==0){
        new_n-=1;
    }
    new_n = new_n/2;
    node temp;
    for(int i=0; i<=new_n; i++){
        temp = permutation->buf[n-i-1];
        permutation->buf[n-i-1] = permutation->buf[i];
        permutation->buf[i] = temp;

    }
}
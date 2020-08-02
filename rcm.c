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
    
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/times.h>
#include <stdbool.h>
#include "rcm.h"
#include "queue.h"
#include <limits.h>
struct timeval startwtime,endwtime;
double p_time;

int main(void){
    int n = 10;

    int *matrix = (int *)malloc(n*n*sizeof(int));
    node *nodes = (node *)malloc(n*sizeof(node));
    int *minNode = (int *)malloc(sizeof(int));
    queue *permutation = queueInit();
    queue *Q = queueInit();
    queue *neighbors = queueInit();
    node extracted_node;

    int help[10][10] = {
        { 0, 1, 0, 0, 0, 0, 1, 0, 1, 0 },
        { 1, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 1, 0, 0, 1, 0 },
        { 0, 1, 1, 1, 0, 1, 0, 0, 0, 1 },
        { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
        { 1, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
        { 0, 1, 0, 0, 1, 0, 0, 1, 0, 0 },
    };
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix(i,j) = help[i][j];
            printf("%d ",matrix(i,j));
        }
        printf("\n");
    }

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
    printf("The permutation of the matrix is: ");
    for(int i=0; i<10; i++){
        printf("%d ",permutation->buf[i].num);
    }
    queueDelete(permutation);
    queueDelete(Q);
    queueDelete(neighbors);
    free(matrix);
    free(nodes);
    free(minNode);
    // free(extracted_node);
    return 0;
    
}
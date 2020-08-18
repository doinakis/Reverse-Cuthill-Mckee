 
#ifndef RCM_H
#define RCM_H

#include <stdio.h>
#include <stdbool.h>
#include </home/superdonut/Desktop/cilk/cilk.h>
#include </home/superdonut/Desktop/cilk/cilk_api.h>
#include "queue.h"



/*
    degreeCalculation: Calculates the degree of each node
        n: Number of nodes
        degrees: Array with the degrees 
        matrix: Graph given as a matrix
*/
void degreeCalculation(int n, node *nodes,int *matrix);
void minimumNode(int n, int *minNode,node *nodes,queue *permutation);
void findNeighbors(int n,int numberOfnode,int *matrix,node *nodes,queue *Q,queue *neighbors);
void Cuthill_Mckee(int n, int *matrix,queue *permutation);
void R_Cuthill_Mckee(int n, queue *permutation);




#endif

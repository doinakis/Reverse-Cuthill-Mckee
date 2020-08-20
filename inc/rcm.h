 
#ifndef RCM_H
#define RCM_H

#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include <time.h>
#include <sys/time.h>
#include <sys/times.h>

struct timeval starttime,endtime;
double time1;

/*
    degreeCalculation: Calculates the degree of each node
        n: Number of nodes
        degrees: Array with the degrees 
        matrix: Graph given as a matrix
*/
void degreeCalculation(int n, node *nodes,int *matrix);

/*
    minimumNode: Calculates the node with the minimum degree
        n: Number of nodes
        degrees: Array with the degrees
        permutation: Queue with the permutation order
*/
void minimumNode(int n, int *minNode,node *nodes,queue *permutation);

/*
    findNeighbors: Finds the neighbors of the corresponding node
        n: Number of nodes
        numberOfnode: Which nodes neighbors to find 
        nodes: Array with all the nodes 
        Q: Queue containing the nodes to be added in the permutation
        neighbors: Queue with the neighbors 
*/
void findNeighbors(int n,int numberOfnode,int *matrix,node *nodes,queue *Q,queue *neighbors);

/*
    Cuthill_Mckee: Cuthill-McKee serial implementation
        n: Number of nodes 
        matrix: Adjacency matrix of nodes
        permutation: Queue with the permutation
*/
void Cuthill_Mckee(int n,int *matrix,queue *permutation);

/*
    R_Cuthill_Mckee: Reverse Cuthill-Mckee serial implementation
        n: Number of nodes
        permutation: Queue with the permutation
*/
void R_Cuthill_Mckee(int n,int *matrix,queue *permutation);

#endif

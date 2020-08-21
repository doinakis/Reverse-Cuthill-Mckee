 
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
    ----------permutation Stracture----------
  perm: Int array containing the permutation 
  index: The next available spot in the matrix
  
*/
typedef struct{

    int *perm;
    int index;

}permutation;

/*
    permutationInit: Initializes a permutation structure
        R: The permutation to be initialized
*/
void permutationInit(permutation *R);

/*
    permutationDelete: Frees the alocated space for a permutation structure
        R: The permutation to be initialized
*/
void permutationDelete(permutation *R);

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
void minimumNode(int n, int *minNode,node *nodes,permutation *R);

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
void Cuthill_Mckee(int n,int *matrix,permutation *R);

/*
    R_Cuthill_Mckee: Reverse Cuthill-Mckee serial implementation
        n: Number of nodes
        permutation: Queue with the permutation
*/
void R_Cuthill_Mckee(int n,int *matrix,permutation *R);

#endif

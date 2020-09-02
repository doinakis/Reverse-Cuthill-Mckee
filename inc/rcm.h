 
/*
 *Implementation of the Reverse Cuthill-Mckee Algorithm in c 
 *
 *Author: Doinakis Michail
 *e-mail: doinakis@ece.auth.gr
 */

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
        n: The number of nodes in the graph 
*/
void permutationInit(permutation *R,int n);

/*
    permutationDelete: Frees the alocated space for a permutation structure
        R: The permutation to be initialized
*/
void permutationDelete(permutation *R);

/*
    degreeCalculation: Calculates the degree of each node
        n: Number of nodes
        nz: Number of non zero elements 
        nodes: Array with all the nodes
        rows,cols: Adjacency matrices rows[i] is adjacent to cols[i]
        total_elements: The sum the neighbors of all the elements in the graph
*/
void degreeCalculation(int n,int nz,node *nodes,int *rows,int *cols);

/*
    minimumNode: Calculates the node with the minimum degree
        n: Number of nodes
        minNode: The node with the minimum degree
        nodes: Array with all the nodes
        Q: Queue containing the nodes to be added in the permutation
*/
void minimumNode(int n,int *minNode,node *nodes,queue *Q);

/*
    findAllNeighbors: Finds the neighbors of all the nodes in the graph
        n: Number of nodes
        nz: Number non zero elements in the graph
        rows,cols: Adjacency matrices rows[i] is adjacent to cols[i]
        nodes: Array with all the nodes
*/

void findAllNeighbors(int n,int nz,int *rows,int *cols,node *nodes);

/*
    findNeighbors: Finds the neighbors of the corresponding node
        nz: Number non zero elements in the graph
        numberOfnode: Which nodes neighbors to find 
        rows,cols: Adjacency matrices rows[i] is adjacent to cols[i]
        nodes: Array with all the nodes 
        Q: Queue containing the nodes to be added in the permutation
        temp_neighbors: Queue with the neighbors of the corresponding node  
*/
void findNeighbors(int nz,int numberOfnode,int *rows,int *cols,node *nodes,queue *Q,queue *temp_neighbors);

/*
    Cuthill_Mckee: Cuthill-McKee serial implementation
        n: Number of nodes 
        nz: Number non zero elements in the graph
        rows,cols: Adjacency matrices rows[i] is adjacent to cols[i]
        R: Struct with the permutation
*/
void Cuthill_Mckee(int n,int nz,int *rows,int *cols,permutation *R);

/*
    R_Cuthill_Mckee: Reverse Cuthill-Mckee serial implementation
        n: Number of nodes
        nz: Number non zero elements in the graph
        rows,cols: Adjacency matrices rows[i] is adjacent to cols[i]
        R: Struct with the permutation
*/
void R_Cuthill_Mckee(int n,int nz,int *rows,int *cols,permutation *R);

#endif

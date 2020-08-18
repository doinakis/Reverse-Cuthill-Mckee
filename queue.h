#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "globaldefines.h"

/*
    ----------node Stracture----------
  num: The number of the node 
  degree: The degree of the node 
  inside_perm: Variable that shows if the node is added in the permutation
  inside_q: Variable that shows if the node is added in the queue
  
*/
typedef struct{

    int num; 
    int degree;
    bool inside_perm;
    bool inside_q;

}node;

/*
    ----------queue Stracture----------
  buf: Array with nodes 
  head,tail: Head and Tail for the circular queue 
  full,empty: Varibles to check the state of the queue (full or emtpy)
  
*/
typedef struct {
  node *buf;
  long head, tail;
  int full, empty;

} queue;
/*
  queueInit: Initializes an empty queue
*/
queue *queueInit(void);
void queueSort(queue *q);

/*
  queueDelete: Deallocates(deletes) a queue
    q: Queue to be deleted
*/
void queueDelete(queue *q);

/*
  queueAdd: Adds a node in a queue
    q: Queue that the node is added to 
    in: Node to be added 
*/
void queueAdd(queue *q, node in);
/*
  queueDel: Extracts a node from a queue
  queue: Queue that the node is being extracted from 
  out: Node to be extracted
*/
void queueDel(queue *q, node *out);

/*
  nodeInit: Initializes an array of n nodes 
    n: Number of nodes
*/
node *nodeInit(int n);
/*
  nodeDelete: Deallocates the space allocated for the nodes 
    node: The node array to be deallocated
*/
void nodeDelete(node *node);

#endif

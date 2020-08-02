#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "globaldefines.h"

/*
    ----------workFunction Stracture----------
  work: void pointer to function
  arg: void pointer to function arguments
  TasksToExecute: Times this function must be executed
  done: Variable that shows if the execution completed
  times_executed: How many times the function executed
  work_mutex: Mutex variable to update times_executed variable
  execution_complete: Condition variable to show that the function completed its
    executions
  cons_delay: Array that holds the time needed to get the function from the queue
    (its added for testing purposes)
  
*/

typedef struct{

    int num; 
    int degree;
    bool inside_perm;
    bool inside_q;

}node;

typedef struct {
  node *buf;
  long head, tail;
  int full, empty;
//   pthread_mutex_t *mut;
//   pthread_cond_t *notFull, *notEmpty;

} queue;

queue *queueInit(void);
void queueSort(queue *q);
void queueDelete(queue *q);
//change the in and out to node type
void queueAdd(queue *q, node in);
void queueDel(queue *q, node *out);


#endif

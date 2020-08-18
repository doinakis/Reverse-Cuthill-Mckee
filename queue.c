#include "queue.h"


queue *queueInit (void)
{
  queue *q;

  q = (queue *)malloc(sizeof (queue));
  q->buf = (node*)malloc(QUEUESIZE*sizeof(node));
  if (q == NULL) return (NULL);
  q->empty = 1;
  q->full = 0;
  q->head = 0;
  q->tail = 0;

  return (q);
}
void queueSort(queue *q){

  // Sort the queue in increasing order of degree
    node temp;
    for(int i=q->head;i<q->tail; i++){
        for(int j=i+1; j<q->tail;j++){
            if(q->buf[i].degree >= q->buf[j].degree){
                temp = q->buf[i];
                q->buf[i] = q->buf[j];
                q->buf[j] = temp;
               
            }
        }
    }

}

node *nodeInit(int n){

  node *nodes = (node *)malloc(n*sizeof(node));
  for(int i=0;i<n;i++){

    nodes[i].num = 0;
    nodes[i].degree =0;
    nodes[i].inside_perm = false;
    nodes[i].inside_q = false;

  }

  return nodes;
}

void nodeDelete(node *node){
  free(node);
}
void queueDelete(queue *q){

  free(q->buf);
  free(q);

}

//changed the in variable to be type node
void queueAdd(queue *q, node in){

  q->buf[q->tail] = in;
  q->tail++;
  if (q->tail == QUEUESIZE)
    q->tail = 0;
  if (q->tail == q->head)
    q->full = 1;
  q->empty = 0;

  return;
}

//changed the out variable to be type node
void queueDel(queue *q, node *out){

  *out = q->buf[q->head];
  q->head++;
  if (q->head == QUEUESIZE)
    q->head = 0;
  if (q->head == q->tail)
    q->empty = 1;
  q->full = 0;

  return;
}

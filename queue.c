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
//   q->mut = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
//   pthread_mutex_init(q->mut, NULL);

//   q->notFull = (pthread_cond_t *)malloc(sizeof (pthread_cond_t));
//   pthread_cond_init(q->notFull, NULL);
//   q->notEmpty = (pthread_cond_t *)malloc(sizeof (pthread_cond_t));
//   pthread_cond_init(q->notEmpty, NULL);

  return (q);
}
void queueSort(queue *q){
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

void queueDelete(queue *q)
{
//   pthread_mutex_destroy(q->mut);
//   free(q->mut);
//   pthread_cond_destroy(q->notFull);
//   free(q->notFull);
//   pthread_cond_destroy(q->notEmpty);
//   free(q->notEmpty);
  free(q->buf);
  free(q);
}

//changed the in variable to be type node
void queueAdd(queue *q, node in)
{
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
void queueDel(queue *q, node *out)
{
  *out = q->buf[q->head];

  q->head++;
  if (q->head == QUEUESIZE)
    q->head = 0;
  if (q->head == q->tail)
    q->empty = 1;
  q->full = 0;

  return;
}

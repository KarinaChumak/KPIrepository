#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define MAX_SIZE 30



typedef struct queue_s queue_t;

void queue_print(queue_t * self);

int queue_remove(queue_t * self);

void queue_add( queue_t* self, int value);

queue_t * queue_new(void);
int getHead(queue_t * self);
int getTail(queue_t * self);
int getElem(queue_t *self, int i);

void queue_free(queue_t * self);


#endif // QUEUE_H_INCLUDED

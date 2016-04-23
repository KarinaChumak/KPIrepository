#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


struct queue_s{
       int * arr;
       int head;
       int tail;
};

queue_t * queue_new(){
queue_t * newQueue = malloc(sizeof(struct queue_s));
newQueue->arr = malloc(sizeof(int) * MAX_SIZE);
newQueue->head = 0;
newQueue->tail = 0;
return newQueue;
}


void queue_add( queue_t* self, int value){
     self->arr[self->tail] = value;
     self->tail ++;
}

int queue_remove(queue_t * self){
        int value = self->arr[self->head];
       self->head ++;
   return value;
}

int getHead(queue_t * self){
return self->head;
}

int getTail(queue_t * self){
return self->tail;
}

int getElem(queue_t *self, int i){
return self->arr[i];
}

void queue_print(queue_t * self){
     printf("Your queue: ");
for (int i = self->head; i < self->tail; i++){
    printf("%d, ",self->arr[i]);
}
printf("\n");
}

void queue_free(queue_t * self){
free(self->arr);
free(self);
}

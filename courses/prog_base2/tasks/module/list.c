#include "list.h"
#include <stdlib.h>


struct list_s{
    int arr[20];
    int count;
};

list_t * list_new(void){
    list_t * l = malloc(sizeof(struct list_s));
    l->count = 0;
    return l;
}



void list_free(list_t * this){
    free (this);
}

int list_getCount(list_t * this){
    return this->count;
}



int list_positive(list_t * this){
    int n=0;
    for (int i = 0; i <= this->count; i++){
        if (this->arr[i] > 0)
            n++;
    }
    return n;
}



int list_negative(list_t * this){
 int n=0;
    for (int i = 0; i <= this->count; i++){
        if (this->arr[i] < 0)
            n++;
    }
    return n;
}

int list_zeros(list_t * this){
 int n=0;
    for (int i = 0; i <= this->count; i++){
        if (this->arr[i] == 0)
            n++;
    }
    return n;
}


void list_add(list_t * this,int index, int value){
   if ((this->count < index)&&(this->count > 0)) {
       for (int i = this->count - 1; i >= index; i--){
        this->arr[i+1] = this->arr[i];
            }}
     this->arr[index] = value;
     this->count++;

}


void list_delete(list_t * this, int index){
    if ((this->count > index)&&(this->count > 0))
        for (int i = index; i < this->count ; i++){
            this->arr[i]=this->arr[i+1];
        }
        this->count --;
}




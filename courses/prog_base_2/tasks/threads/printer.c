#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mutex.h"
#include "thread.h"
#include "printer.h"

static mutex_t * printer_mu;
static thread_t * printer_thread;


struct printer_s
{
    char * string;
    thread_t * thread;
};


void start()
{
    printer_mu = mutex_new();
    printer_thread =  thread_getCurrentThread();
}




printer_t * printer_new(char * string)
{
    printer_t * self = malloc(sizeof(printer_t));
    self->string = malloc(strlen(string)+1);
    strcpy(self->string,string);
    self->thread = NULL;
    return self;
}


void * loop(void * printer)
{
    printer_t * self = printer;

    while(1)
    {
        mutex_lock(printer_mu);

        if(thread_equals(printer_thread, self->thread))
        {
            mutex_unlock(printer_mu);
            continue;
        }

        for(size_t i =  0; i < 10; i++)
    puts(self->string);
        printer_thread = self->thread;

        mutex_unlock(printer_mu);
    }

    assert(0);
    return NULL;

}



void printer_process(printer_t * self)
{
    thread_t* new_thread;
    mutex_lock(printer_mu);
    new_thread = thread_create_args(loop, self);
    self->thread = new_thread;
    mutex_unlock(printer_mu);
}


void stop()
{
    mutex_free(printer_mu);
    thread_free(printer_thread);
}



void printer_free(printer_t * self)
{
    mutex_lock(printer_mu);
    if(self->thread != NULL)
    {
        thread_terminate(self->thread);
        thread_free(self->thread);
    }

    mutex_unlock(printer_mu);

    free(self->string);
    free(self);
}

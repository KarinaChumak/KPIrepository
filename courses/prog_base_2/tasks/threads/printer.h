#ifndef PRINTER_H_INCLUDED
#define PRINTER_H_INCLUDED


typedef struct printer_s printer_t;

void start();
void stop();
printer_t * printer_new(char * string);
void printer_free(printer_t * self);
void printer_process(printer_t * self);


#endif // PRINTER_H_INCLUDED


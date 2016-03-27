#include "printer.h"

#include <stdio.h>

int main(void){
  printer_t *p1, *p2, *p3;
  start();
  p1 = printer_new("Hadyniak");
  p2 = printer_new("the");
  p3 = printer_new("best");
  printer_process(p1);
  printer_process(p2);
  printer_process(p3);

  getchar();

  printer_free(p1);
  printer_free(p2);
  printer_free(p3);

  stop();
}

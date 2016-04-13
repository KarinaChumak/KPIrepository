#include <stdio.h>
#include <stdlib.h>
#include "designers.h"



int main() {
	FILE * fr = fopen("Designers.json", "r");
    char text[10000];
    char line[100];
    int size = 3;
    designer * d[size];            // create array of structure pointers

    for (int i = 0; i < size; i++){ // fill it
    d[i] = des_create();
    }
    while(fgets(line, 100, fr) != NULL) {  // read file
        strcat(text, line);
    }
	parse(text,d);                         // to parse json file
	for (int i = 0; i < size; i++){       // to print array of structure
    printf("Designer %d:\n",i+1);
	des_print(d[i]);
	}
	for (int i = 0; i < size; i++){
    des_free(d[i]);
    }
	return 0;
}

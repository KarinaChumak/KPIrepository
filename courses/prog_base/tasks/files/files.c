#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fprocess(const char * pread, const char * pwrite){
	FILE* fr = fopen(pread, "r");
	FILE* fw = fopen(pwrite, "w");
	int coord[4];
	char temp[1000];
	for (int i = 1; i <= 17; i++){
		fgets(temp, 1000, fr);
	}
	double d;
	fscanf(fr, "%d %d %d %d %d %d", &coord[0], &coord[1], &coord[2], &coord[3]);
	d = sqrt(pow(coord[0] - coord[2], 2) + pow(coord[1] - coord[3], 2));
	fprintf(fw, "%d ", floor (d));

	fclose(fr);
	fclose(fw);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "queue.h"


typedef int (*cmp_f)(queue_t * self);
typedef void (*react_f)(queue_t * self);

typedef struct dynamic_s {
    HANDLE hLib;
    cmp_f cmp;
    react_f react;
} dynamic_t;

const char * userChoice();
dynamic_t * dynamic_init(const char * dllName);
void dynamic_clean(dynamic_t * dyn);

int main(void) {
    queue_t * q = queue_new();
    const char * dllName = userChoice();
    dynamic_t * dll = dynamic_init(dllName);
    if (NULL == dll) {
        printf("Can't load dynamic!\n");
        return 1;
    }
    if (NULL == dll->cmp) {
        printf("Can't get compare function!\n");
        return 1;
    }
    if (NULL == dll->react) {
        printf("Can't get reaction function!\n");
        return 1;
    }
    printf("Dynamic loaded!");
    srand(time(NULL));

     for(int i = 0; i<MAX_SIZE;i++){
    int a;
     printf("\n>>");
    scanf("%i",&a);
    queue_add(q,a);
    queue_print(q);


    if (dll->cmp(q)){
        dll->react(q);
        }
     }

    queue_free(q);
    dynamic_clean(dll);
    return 0;
}



const char * userChoice() {
    int dllNum = 0;
    while (dllNum < 1 || dllNum > 2) {
        printf("Choose DLL to load:\n1. Lab2DLL1\n2. Lab2DLL2\n> ");
        scanf("%i", &dllNum);
        if (dllNum == 1) {
            return "Lab2Dll1.dll";
        } else if (dllNum == 2) {
            return "Lab2Dll2.dll";
        }
    }
    return NULL;
}

dynamic_t * dynamic_init(const char * dllName) {
    dynamic_t * dyn = malloc(sizeof(struct dynamic_s));
    dyn->hLib = LoadLibrary(dllName);
    dyn->cmp = NULL;
    dyn->react = NULL;
    if (NULL != dyn->hLib) {
        dyn->cmp = (cmp_f)GetProcAddress(dyn->hLib, "compare");
        dyn->react = (react_f)GetProcAddress(dyn->hLib, "reaction");
        return dyn;
    } else {
        return NULL;
    }
}

void dynamic_clean(dynamic_t * dyn) {
    FreeLibrary(dyn->hLib);
    free(dyn);
}


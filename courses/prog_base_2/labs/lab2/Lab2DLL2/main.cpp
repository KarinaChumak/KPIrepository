#include "main.h"
#include <stdio.h>

int compare(queue_t * self){
    int sum =0;
    for (int i = getHead(self) ; i <getTail(self); i++){
     sum +=getElem(self,i);
    }
        return sum;
}

int reaction(queue_t * self){
        if (compare(self)>100){
           for(int i = getHead(self); i < getTail(self); i ++){
             int tmp = getElem(self,getHead(self));
                if(tmp>0){
                queue_add(self, -tmp);
                queue_remove(self);
                queue_print(self);
                }
                else{
                    queue_remove(self);
                    while(compare(self)>50){
                    queue_add(self,tmp);
                   queue_print(self);}
                    return 0;
                }
                }
        printf("Finish");
                }

    return 0;
}


extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // attach to process
        // return FALSE to fail DLL load
        break;

    case DLL_PROCESS_DETACH:
        // detach from process
        break;

    case DLL_THREAD_ATTACH:
        // attach to thread
        break;

    case DLL_THREAD_DETACH:
        // detach from thread
        break;
    }
    return TRUE; // succesful
}

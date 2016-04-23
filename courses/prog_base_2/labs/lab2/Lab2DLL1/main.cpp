#include <stdio.h>
#include "main.h"

int compare(queue_t * self){
if (getElem(self,getTail(self)-1)<0)
    return 1;
}

int reaction(queue_t * self){
       if (compare(self)==1){
        for(int i = getHead(self); i < getTail(self)-1;i++)
            queue_remove(self);
            queue_print(self);
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

#include "OuterLib.h"
#include <dlfcn.h>
#include <stdlib.h>

void LinkInnerLib(int iNo)
{
    void *ptr = NULL;
    void (*fptr)(int);

    ptr = dlopen("./InnerLib.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library");
        return;
    }

    fptr = dlsym(ptr,"Factorial");

    if(fptr == NULL)
    {
        printf("Unable to locate function address\n");
        return;
    }

    fptr(iNo);
    dlclose(ptr);
}

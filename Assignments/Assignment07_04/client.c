#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    void *ptr = NULL;
    void (*fptr)(int);
    int iNo = 0;

    if(argc != 2)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    iNo = atoi(argv[1]);

    ptr = dlopen("./OuterLib.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library");
        return -1;
    }

    fptr = dlsym(ptr,"LinkInnerLib");

    if(fptr == NULL)
    {
        printf("Unable to locate function address\n");
        return -1;
    }

    fptr(iNo);
    dlclose(ptr);
}
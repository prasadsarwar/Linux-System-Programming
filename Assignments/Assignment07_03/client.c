#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int iNo = 0;
    void *ptr1 = NULL;
    void *ptr2 = NULL;

    void (*fptr1)(int);
    void (*fptr2)(int);

    if(argc != 2)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    iNo = atoi(argv[1]);

    ptr1 = dlopen("./primelib.so",RTLD_LAZY);
    ptr2 = dlopen("./perfectlib.so",RTLD_LAZY);

    if((ptr1 == NULL) || (ptr2 == NULL))
    {
        printf("Unable to open liberary\n");
        return -1;
    }

    fptr1 = dlsym(ptr1,"CheckPrime");
    fptr2 = dlsym(ptr2, "CheckPerfect");

    if((fptr1 == NULL) || (fptr2 == NULL))
    {
        printf("Unable to locate function address\n");
        return -1;
    }

    fptr1(iNo);
    fptr2(iNo);

    return 0;
}
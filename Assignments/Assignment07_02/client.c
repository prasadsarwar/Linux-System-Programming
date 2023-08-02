#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    void *ptr = NULL;
    void (*fptr)(char*, char*);

    ptr = dlopen("./library.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"CompareFiles");
    if(fptr == NULL)
    {
        printf("Unable to locate address of function\n");
        return -1;
    }

    fptr(argv[1],argv[2]);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    void *ptr = NULL;
    int(*fptr)(int,int);
    int iRet = 0;
    int iNum1 = 0, iNum2 = 0;

    if(argc != 3)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    iNum1 = atoi(argv[1]);
    iNum2 = atoi(argv[2]);

    ptr = dlopen("./library.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    // Addition

    fptr = dlsym(ptr,"Addition");
    if(fptr == NULL)
    {
        printf("Unable to locate function address\n");
        return -1;
    }
    iRet = fptr(iNum1,iNum2);

    printf("Addition: %d\n",iRet);

    // Subtraction

    fptr = dlsym(ptr,"Subtraction");
    if(fptr == NULL)
    {
        printf("Unable to locate function address\n");
        return -1;
    }
    iRet = fptr(iNum1,iNum2);

    printf("Subtraction: %d\n",iRet);

    // Multiplication

    fptr = dlsym(ptr,"Multiplication");
    if(fptr == NULL)
    {
        printf("Unable to locate function address\n");
        return -1;
    }
    iRet = fptr(iNum1,iNum2);

    printf("Multiplication: %d\n",iRet);

    //Division

    fptr = dlsym(ptr,"Division");
    if(fptr == NULL)
    {
        printf("Unable to locate function address\n");
        return -1;
    }
    iRet = fptr(iNum1,iNum2);

    printf("Division: %d\n",iRet);

    // Modulus

    fptr = dlsym(ptr,"Modulus");
    if(fptr == NULL)
    {
        printf("Unable to locate function address\n");
        return -1;
    }
    iRet = fptr(iNum1,iNum2);

    printf("Modulus: %d\n",iRet);


    return 0;
}
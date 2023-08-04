//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Write a program which creates single thread, it accept 1 value  //
//  from user and it return some value to caller thread             //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void * ThreadProc1(void *ptr)
{
    int iNo = (int*)ptr;
    printf("Parameter from main thread = %d\n", iNo);
    pthread_exit(++iNo);
}

int main()
{
    pthread_t TID1;
    int iRet1 = 0, iValue = 0;
    int iNo = 101;

    iRet1 = pthread_create(&TID1,NULL,ThreadProc1,(int*)iNo);

    if(iRet1 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID1,&iValue);

    printf("Value from Thread : %d\n",iValue);
    
    return 0;
}
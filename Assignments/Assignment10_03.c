//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Write a program which creates single thread, we have to pass    //
//  parameter to that thread from main thread.                      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void * ThreadProc1(void *ptr)
{
    printf("Parameter from main thread = %d\n", (int)ptr);
}

int main()
{
    pthread_t TID1;
    int iRet1 = 0;
    int iNo = 101;

    iRet1 = pthread_create(&TID1,NULL,ThreadProc1,(int*)iNo);

    if(iRet1 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID1,NULL);

    return 0;
}
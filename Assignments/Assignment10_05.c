//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Write a program which is used to get thread id inside its thread//
//  function                                                        //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void * ThreadProc1(void *ptr)
{
    printf("Thread 1 ID: %d\n",pthread_self());
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

    printf("Thread1 created with ID: %d\n",TID1);

    pthread_join(TID1,NULL);
    
    return 0;
}
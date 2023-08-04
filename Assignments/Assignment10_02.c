//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Write a program which creates two thread,                       //
//  First thread prints numbers from 1 to 500                       //
//  other thread prints numbers from 500 to 1                       //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void * ThreadProc1(void *ptr)
{
    int iCnt = 0;

    for(iCnt = 1; iCnt <= 500; iCnt++)
    {
        printf("Thread 1 : %d\n",iCnt);
    }
}

void * ThreadProc2(void *ptr)
{
    int iCnt = 0;

    for(iCnt = 500; iCnt >= 1; iCnt--)
    {
        printf("Thread 2 : %d\n",iCnt);
    }

}

int main()
{
    pthread_t TID1, TID2;
    int iRet1 = 0, iRet2 = 0;

    iRet1 = pthread_create(&TID1,NULL,ThreadProc1,NULL);

    if(iRet1 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    // printf("Thread is created with ID: %d\n",TID1);


    iRet2 = pthread_create(&TID2,NULL,ThreadProc2,NULL);

    if(iRet2 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID: %d\n",TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    return 0;
}
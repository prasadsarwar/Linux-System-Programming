//////////////////////////////////////////////////////////////////////
//                                                                  //
//  write a program which is used to pridict the problem due to     //
//  lack of synchronization                                         //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int iCount = 0;

void * ThreadProc(void *ptr)
{
    int iCnt = 0;

    for(iCnt = 1; iCnt <= 100000; iCnt++)
    {
        iCount++;
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1, TID2;
    int iRet = 0;

    iRet = pthread_create(&TID1,NULL,ThreadProc,NULL);

    if(iRet != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    iRet = pthread_create(&TID2,NULL,ThreadProc,NULL);

    if(iRet != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    printf("iCount = %d\n",iCount);

    return 0;
}
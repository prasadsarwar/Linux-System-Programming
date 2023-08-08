//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Write a program which creates 4 number of threads and our main  //
//  thread waits until all threads terminates.                      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <pthread.h>

void * ThreadProc(void *ptr)
{
    int i = 0;
    printf("ThreadProc : %d started...\n",(int)ptr);

    for(i = 1; i <= 1000;i++);

    printf("ThreadProc : %d completed...\n",(int)ptr);

    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1, TID2, TID3, TID4;
    int iRet = 0, iNo = 1;

    printf("Main thread started....\n");

    iRet = pthread_create(&TID1,NULL,ThreadProc,(int)iNo);

    if(iRet != 0)
    {
        printf("Unable to create thread : %d\n",iNo);
        return -1;
    }
    iNo++;

    iRet = pthread_create(&TID2,NULL,ThreadProc,(int)iNo);

    if(iRet != 0)
    {
        printf("Unable to create thread : %d\n",iNo);
        return -1;
    }
    iNo++;

    iRet = pthread_create(&TID3,NULL,ThreadProc,(int)iNo);

    if(iRet != 0)
    {
        printf("Unable to create thread : %d\n",iNo);
        return -1;
    }
    iNo++;

    iRet = pthread_create(&TID4,NULL,ThreadProc,(int)iNo);

    if(iRet != 0)
    {
        printf("Unable to create thread : %d\n",iNo);
        return -1;
    }

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    pthread_join(TID3,NULL);
    pthread_join(TID4,NULL);

    printf("Main thread completed...\n");

    return 0;

}
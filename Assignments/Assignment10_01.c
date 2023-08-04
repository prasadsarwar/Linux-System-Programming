//////////////////////////////////////////////////////////////////////
//                                                                  //
//  Write a program which is used to create simple thread by using  //
//  pthread library .                                               //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void * ThreadProc(void *ptr)
{
    printf("Inside thread\n");
}

int main()
{
    pthread_t TID;
    int iRet = 0;

    iRet = pthread_create(&TID,NULL,ThreadProc,NULL);

    if(iRet != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID: %d\n",TID);

    pthread_join(TID,NULL);

    return 0;
}
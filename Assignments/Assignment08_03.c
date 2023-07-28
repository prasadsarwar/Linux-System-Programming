//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// write a program which creates 3 different processes internally as        //
// process 2, process 3 and process 4                                       //                                                     //
//                                                                          //
// output:                                                                  //
// Process 2 = 109658 created from parent = 109657                          //
// Process 3 = 109659 created from parent = 109657                          //  
// Parent process id = 109657                                               //  
// Process 4 = 109660 created from parent = 109657                          //                                     //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <sys/wait.h>
#include<unistd.h>

int main()
{
    int iRet1 = 0, iRet2 = 0, iRet3 = 0;

    iRet1 = fork();

    if(iRet1 == 0)
    {
        printf("Process 2 = %d created from parent = %d\n",getpid(),getppid());
    }
    else
    {
        iRet2 = fork();

        if(iRet2 == 0)
        {
            printf("Process 3 = %d created from parent = %d\n",getpid(),getppid());
        }
        else
        {
            iRet3 = fork();

            if(iRet3 == 0)
            {
                printf("Process 4 = %d created from parent = %d\n",getpid(),getppid());
            }
            else
            {
                printf("Parent process id = %d\n",getpid());
            }
        }
    }
}
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// write a program in which parent process waits till its child process     //
// terminates                                                               //
//                                                                          //
// output:                                                                  //
//    Parent process                                                        //
//    Child process                                                         //
//    Child terminated                                                      //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <sys/wait.h>
#include<unistd.h>

int main()
{
    int iRet = 0;

    iRet = fork();

    if(iRet == 0)
    {
        printf("Child process\n");
    }
    else
    {
        printf("parent process\n");
        wait(NULL);
        printf("Child terminated\n");
    }
}
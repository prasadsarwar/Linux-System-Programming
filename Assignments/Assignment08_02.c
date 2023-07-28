//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// write a program which creates three level process hirarchy where         //
// process 1 creates process 2 and it internally creates process 3          //                                                     //
//                                                                          //
// output:                                                                  //
//    Process 1                                                             //
//    Process 2                                                             //
//    Process 3                                                             //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <sys/wait.h>
#include<unistd.h>

int main()
{
    int iRet1 = 0, iRet2 = 0;

    iRet1 = fork();

    if(iRet1 == 0)
    {
        iRet2 = fork();

        if(iRet2 == 0)
        {
            printf("Process 3\n");
        }
        else
        {
            printf("Process 2\n");
        }   
    }
    else
    {
        printf("Process 1\n");
    }
}
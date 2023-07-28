//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// write a program which creates two process as process as process 2 and    //
// process 3 and our parent process terminates till both process terminates //
//                                                                          //
// output:                                                                  //
// Process 2 started...                                                     //
// Parent process waiting for child process to complete..                   //
// Process 3 started...                                                     //
// Process 3 completed...                                                   //
// Process 2 completed...                                                   //
// Both child process completed.. exiting parent process..                  //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <sys/wait.h>
#include<unistd.h>

int main()
{
    int Status = 0;
    int process2 = 0, process3 = 0;

    process2 = fork();

    if (process2 < 0) 
    {
        perror("Unable to Fork for Process 2");
        return 1;
    }
    else if(process2 == 0)
    {
        printf("Process 2 started...\n");
        sleep(3);
        printf("Process 2 completed...\n");
        return 0;
    }

    process3 = fork();

    if (process3 < 0) 
    {
        perror("Unable to Fork for Process 3");
        return 1;
    }
    else if(process3 == 0)
    {
        printf("Process 3 started...\n");
        sleep(3);
        printf("Process 3 completed...\n");
        return 0;
    }

    printf("Parent process waiting for child process to complete..\n");

    waitpid(process2,&Status,0);
    waitpid(process3,&Status,0);

    printf("Both child process completed.. exiting parent process..\n");

    return 0;

}
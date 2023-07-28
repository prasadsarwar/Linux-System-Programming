//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// write a program which is used to yield our processor using appropriate   // 
// system call                                                              //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <sched.h>

int main()
{
    int i = 0, j = 0;

    printf("Yield started\n");

    for(i = 0; i<5; i++)
    {
        for(j = 0; j < 99999999; j++)
        ;
    sched_yield();
    }

    printf("yield finish\n");

    return 0;
}
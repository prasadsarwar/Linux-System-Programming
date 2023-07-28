//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// write a program which is used to print priority of process               //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <sys/resource.h>

int main()
{
    int pid = getpid();
    int priority = getpriority(PRIO_PROCESS,pid);

    printf("priority of process : %d = %d \n",pid,priority);
    

    return 0;
}
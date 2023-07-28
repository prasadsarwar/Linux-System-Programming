//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// write a program which is used to increase priority of process by 5       //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    int pid = getpid();
   
    int current_priority = getpriority(PRIO_PROCESS, pid);

    if (current_priority == -1) 
    {
        perror("Error getting process priority");
        return 1;
    }

    int new_priority = current_priority - 5;
    if (new_priority < PRIO_MIN)
    {
        new_priority = PRIO_MIN;
    }

    if (setpriority(PRIO_PROCESS, pid, new_priority) == -1) {
        perror("Error setting process priority");
        return 1;
    }

    printf("Process priority increased successfully!\n");
    return 0;
}

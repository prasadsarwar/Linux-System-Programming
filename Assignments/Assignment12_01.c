#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int iRet = 0;
    char * arr = "Prasad Sarwar";
    int fd[2];
    char Buff[128];

    pipe(fd);

    iRet = fork();

    if(iRet == 0)
    {
        printf("child Process scheduled\n");

        printf("Writing data into pipe...\n");
        close(fd[0]);
        write(fd[1],arr,strlen(arr));
        printf("Writing complete...\n");
        exit(0);
    }
    else
    {
        printf("Parent Process scheduled\n");
        printf("Waiting for child process to complete...\n");
        close(fd[1]);
        read(fd[0],Buff,sizeof(Buff));
        printf("Data: %s\n",Buff);
        printf("Parent process terminated\n");
    }
    return 0;
}
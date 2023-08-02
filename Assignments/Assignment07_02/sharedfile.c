#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "sharedfile.h"

int CompareFiles(char* Fname1, char* Fname2) 
{
    struct stat sobj1, sobj2;

    int fd1 = 0, fd2 = 0;
    char Buffer1[1024];
    char Buffer2[1024];
    int iRet = 0;


    fd1 = open(Fname1,O_RDONLY);
    fd2 = open(Fname2,O_RDONLY);

    if((fd1 == -1) || (fd2 == -1))
    {
        printf("unable to open file\n");
        return -1;
    }

    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);

    if((sobj1.st_size) != (sobj2.st_size))
    {
        printf("Files are diffrent as sizes are diffrent\n");
        return -1;
    }

    while((iRet = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        iRet = read(fd2,Buffer2,sizeof(Buffer2));

        if(memcmp(Buffer1,Buffer2,iRet) != 0)
        {
            break;
        }
    }

    close(fd1);
    close(fd2);

    if(iRet == 0)
    {
        printf("Both files are equal\n");
    }
    else
    {
        printf("Both files are different\n");
        return -1;
    }

}

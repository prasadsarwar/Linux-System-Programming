//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// write a program which creates hole of size 1kb at end of file            //
//                                                                          //
// Usage : ./exe file_name                                                  //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = 0, Ret = 0;
    int offset = 1024;
    char Buffer[] = "prasad";

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd = open(argv[1],O_WRONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    if(lseek(fd,offset,SEEK_END) == -1)
    {
        printf("Unable to create hole\n");
        return -1;
    }

    write(fd,Buffer,strlen(Buffer));

    close(fd);

    return 0;
}
//////////////////////////////////////////////////////////////////////////
//                                                                      //  
// write a program to accept file name and bytes from user and read     //
// that number of bytes from file.                                      //
//                                                                      //                            
// Usage : ./exe file_name no_of_bytes                                  //                                        
//                                                                      //  
//////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *Buffer = NULL;
    int fd = 0;
    int iRet = 0;

    if(argc != 3)
    {
        printf("insuffucient number of arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    Buffer = (char *)malloc(atoi(argv[2]));

    iRet = read(fd,Buffer,atoi(argv[2]));

    if(iRet == -1)
    {
        printf("Unable to read file\n");
        return -1;
    }

    printf("%s\n",Buffer);

    close(fd);

    return 0;
}
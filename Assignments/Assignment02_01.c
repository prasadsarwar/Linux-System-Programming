//////////////////////////////////////////////////////////////////////////
//                                                                      //  
// write a program to accept file name from user and read whole file    //
//                                                                      //                            
// Usage : ./exe file_name                                              //                                        
//                                                                      //  
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int iRet = 0;
    char Buffer[1024];

    if(argc != 2)
    {
        printf("Insufficiient number of arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer))) != NULL)
    {
        write(1,Buffer,iRet);
    }

    printf("\n");

    close(fd);

    return 0;
}
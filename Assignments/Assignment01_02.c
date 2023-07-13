//////////////////////////////////////////////////////////////////////////
//                                                                      //  
// Write a program which accept file name and mode from user and open   // 
// that file in specified mode                                          //
// Usage : ./exe file_name mode                                         //                                        
//                                                                      //  
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int Mode = 0;

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    if(strcmp(argv[2],"read") == 0)
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"write") == 0)
    {
        Mode = O_WRONLY;
    }
    else
    {
        Mode = O_RDONLY;
    }

    fd = open(argv[1],Mode);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    else
    {
        printf("File opened successfully with fd : %d\n", fd);
    }

    return 0;
}
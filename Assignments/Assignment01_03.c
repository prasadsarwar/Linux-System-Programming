//////////////////////////////////////////////////////////////////////////
//                                                                      //  
// write a program to accept file name and open mode and check whether  //
// your process can access that fille in accepted mode or not           //                            //
// Usage : ./exe file_name mode                                         //                                        
//                                                                      //  
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

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

    fd = access(argv[1],Mode);

    if(fd == -1)
    {
        printf("Unable to open the file in the specified mode.\n");
        return -1;
    }
    else
    {
        printf("File opened successfully in the specified mode with fd %d\n", fd);
    }

    return 0;
}
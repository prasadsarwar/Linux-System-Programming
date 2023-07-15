//////////////////////////////////////////////////////////////////////////
//                                                                      //  
// write a program to accept file name from user and write string in    //
// that file                                                            //
//                                                                      //                            
// Usage : ./exe file_name "string"                                     //                                        
//                                                                      //  
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int iRet = 0;
    char *str = NULL;

    if(argc != 3)
    {
        printf("Insufficiient number of arguments\n");
        return -1;
    }

    str = argv[2];

    fd = open(argv[1],O_WRONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    iRet = write(fd,str,strlen(str));

    if(iRet == -1)  //if((write(fd,str,strlen(str))) < 0)
    {
        printf("Unable to write in file\n");
        return -1;
    }
    
    close(fd);

    return 0;
}
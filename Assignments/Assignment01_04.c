//////////////////////////////////////////////////////////////////////////
//                                                                      //  
// write a program to accept file name and print all information about  //
// that file.                                                           //
//                                                                      //                            
// Usage : ./exe file_name                                              //                                        
//                                                                      //  
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    stat(argv[1], &sobj);

    printf("File name : %s\n",argv[1]);
    printf("Inode number: %d\n",sobj.st_ino);
    printf("File size: %d\n",sobj.st_size);
    printf("Number of links: %d\n",sobj.st_nlink);
    printf("Number of blocks : %d\n",sobj.st_blocks);

    return 0;
}
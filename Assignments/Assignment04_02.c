//////////////////////////////////////////////////////////////////////////
//                                                                      //
// write a program which accept name of directory and create directory  //
// of that name                                                         //
//                                                                      //
// Usage : ./exe directory_name                                         //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;
    int iRet = 0;

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

///////////////////////////////////////////////////
//  optional
    stat(argv[1],&sobj);

    if(S_ISDIR(sobj.st_mode))
    {
        printf("Directory already exist\n");
        return -1;
    }
///////////////////////////////////////////////////
    
    iRet = mkdir(argv[1],0777);

    if(iRet == -1)
    {
        printf("Unable to create directory\n");
        return -1;
    }
    else
    {
        printf("Directory created successfully\n");
    }

    return 0;
}
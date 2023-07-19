//////////////////////////////////////////////////////////////////////////
//                                                                      //
// write a program which accepts directory name from user and write all //
// information of all regular files, and read containts from that file  //
//                                                                      //
// Usage : ./exe directory_name                                         //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/dir.h>
#include <dirent.h>
#include<sys/stat.h>

#pragma pack(1)

struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    int fd = 0, Ret = 0;
    struct FileInfo fobj;
    struct stat sobj;
    struct dirent *entry = NULL;
    DIR *dp = NULL;

    char Fname[30];


    if(argc != 2)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("Combined.txt",0777);
    if(fd == -1)
    {
        printf("Unable to create combined file\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(Fname,"%s/%s",argv[1],entry->d_name);
        stat(Fname,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            strcpy(fobj.FileName,entry->d_name);
            fobj.FileSize = sobj.st_size;

            write(fd,&fobj,sizeof(fobj));
        }
    }

    closedir(fd);

    return 0;
}

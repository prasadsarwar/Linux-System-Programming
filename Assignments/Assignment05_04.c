//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// write a program which accepts directory name from user and combine       //
// all containts of files from that directory into one named as AllCombined //
//                                                                          //
// Usage : ./exe directory_name                                             //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/dir.h>
#include <dirent.h>

#pragma pack(1)

int main(int argc, char *argv[])
{
    int fd = 0, TempFd = 0, Ret = 0;
    struct dirent *entry = NULL;
    DIR *dp = NULL;
    char Fname[30];
    char Buffer[1024];


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

    fd = creat("AllCombined.txt",0777);
    if(fd == -1)
    {
        printf("Unable to create combined file\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(Fname,"%s/%s",argv[1],entry->d_name);

        if((entry->d_type) != DT_REG)
        {
            continue;
        }

        TempFd = open(Fname,O_RDONLY);

        if(TempFd == -1)
        {
            printf("Unable to open file %s\n",Fname);
            continue;
        }
        
        while((Ret = read(TempFd,Buffer,sizeof(Buffer))) != 0)
        {
            write(fd,Buffer,Ret);
            memset(Buffer,0,sizeof(Buffer));
        }
        close(TempFd);
    }

    close(fd);
    closedir(dp);

    return 0;
}

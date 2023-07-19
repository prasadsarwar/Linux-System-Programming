//////////////////////////////////////////////////////////////////////////
//                                                                      //
// write a program which accept directory name from user and copy first //
// 10 bytes from all regular files into newly created file named as     //
// Demo.txt                                                             //
//                                                                      //
// Usage : ./exe directory_name                                         //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/dir.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    int fd = 0;
    char Buffer[10];
    int TempFd = 0, Ret = 0; 
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

    fd = creat("Demo.txt",0777);

    if(fd == 0)
    {
        printf("Unable to create combined file\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        if((entry->d_name) != DT_REG)
        {
            continue;
        }

        sprintf(Fname,"%s/%s",argv[1],entry->d_name);

        TempFd = open(Fname, O_RDONLY);

        if(TempFd == -1)
        {
            printf("Unable to openn file %s\n",entry->d_name);
            continue;
        }

        Ret = read(TempFd,Buffer,sizeof(Buffer));

        if(Ret == -1)
        {
            printf("Unable to read from file %s\n",entry->d_name);
            continue;
        }

        Ret = write(fd,Buffer,sizeof(Buffer));

        if(Ret == -1)
        {
            printf("Unable to write from file %s\n",entry->d_name);
            continue;
        }

        close(TempFd);
    }

    closedir(dp);

    return 0;
}
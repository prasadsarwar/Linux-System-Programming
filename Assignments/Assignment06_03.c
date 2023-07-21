//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// write a program which accepts directory name and file name and create    //
// file in that directory                                                   //
//                                                                          //
// Usage : ./exe directory_name file_name                                                  //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/dir.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    DIR *dp = NULL;
    char Fname[30];

    if(argc != 3)
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

    sprintf(Fname,"%s/%s",argv[1],argv[2]);

    fd = open(Fname, O_RDONLY);

    if(fd != -1)
    {
        printf("File is already present in directory\n");
        return -1;
    }

    fd = creat(Fname,0777);

    if(fd == -1)
    {
        printf("Unable to create file in directory\n");
        return -1;
    }

    close(fd);
    closedir(dp);

    return 0;
}
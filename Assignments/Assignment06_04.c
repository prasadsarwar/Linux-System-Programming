//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// write a program which accepts directory name from user and delete all    //
// such files whoose size is grater than 100 bytes                          //
//                                                                          //
// Usage : ./exe directory_name                                             //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <dirent.h>
#include <sys/dir.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{   
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
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

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(Fname,"%s/%s",argv[1],entry->d_name);

        stat(Fname,&sobj);

        if(sobj.st_size > 100)
        {
            remove(Fname);
            printf("deleted file : %s\n",Fname);
        }
    }

    closedir(dp);

    return 0;
}
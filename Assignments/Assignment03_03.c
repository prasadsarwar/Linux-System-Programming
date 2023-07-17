//////////////////////////////////////////////////////////////////////////
//                                                                      //
// write a program to accept two directory names from user and move all //
// files from source directory to destination directory                 //
//                                                                      //
// Usage : ./exe  source_directory destination_directory                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <dirent.h>
#include <sys/dir.h>

int main(int argc, char *argv[])
{
    DIR *dp1 = NULL, *dp2 = NULL;
    struct dirent *entry = NULL;
    char oldname[30];
    char newname[30];
    
    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    dp1 = opendir(argv[1]);
    dp2 = opendir(argv[2]);

    if((dp1 == NULL) || (dp2 == NULL))
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp1)) != NULL)
    {
        sprintf(oldname,"%s/%s",argv[1],entry->d_name);
        sprintf(newname,"%s/%s",argv[2],entry->d_name);

        rename(oldname,newname);
    }

    closedir(dp1);
    closedir(dp2);

    return 0;
}
//////////////////////////////////////////////////////////////////////////
//                                                                      //
// write a program to accept directory name and file name from user    	//
// and check whether the file is present in that folder or not          //
//                                                                      //
// Usage : ./exe directory_name file_name		                        //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <dirent.h>
#include <sys/dir.h>
#include <string.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    if(argc != 3)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        if((strcmp(argv[2],entry->d_name)) == 0)
        {
            printf("File is present in directory\n");
            break;
        }
    }

    if(entry == NULL)
    {
        printf("No file found...\n");
        return -1;
    }

    closedir(dp);

    return 0;
}
//////////////////////////////////////////////////////////////////////////
//                                                                      //
// write a program to accept directory name from user and print all     //
// file names of that directory                                         //
//                                                                      //
// Usage : ./exe folder_name                                    	    //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

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
		printf("%s\n",entry->d_name);
	}

	closedir(dp);

	return 0;
}
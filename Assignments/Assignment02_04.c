//////////////////////////////////////////////////////////////////////////
//                                                                      //
// write a program to accept directory name from user and print name    //
// of file having largest size	                                        //
//                                                                      //
// Usage : ./exe                                      					//
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
	struct stat sobj;
	int iMax = 0;
	char name[30];
	char MaxFname[30];
	char DirName[20];

	if(argc != 1)
	{
		printf("Insufficient number of arguments\n");
		return -1;
	}

	printf("Enter directory name: \n");
	scanf("%s",&DirName);

	dp = opendir(DirName);

	if(dp == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}

	while((entry = readdir(dp)) != NULL)
	{
		sprintf(name,"%s/%s",DirName,entry->d_name);
		stat(name,&sobj);

		if(S_ISREG(sobj.st_mode))
		{
			if(iMax < sobj.st_size)
			{
				iMax = sobj.st_size;
				strcpy(MaxFname,name);
			}
		}
		
	}
	printf("File : %s has max size of : %d\n",MaxFname, iMax);

	closedir(dp);

	return 0;
}
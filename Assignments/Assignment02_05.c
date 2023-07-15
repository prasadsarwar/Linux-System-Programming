//////////////////////////////////////////////////////////////////////////
//                                                                      //
// write a program to accept directory name from user and print all    	//
// file names and its types from that directory                         //
//                                                                      //
// Usage : ./exe directory_name                                			//
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
	char *Type;

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
		if(entry->d_type == DT_REG)
		{
			Type = "Regular";
		}
		else if(entry->d_type == DT_DIR)
		{
			Type = "Directory";
		}
		else if(entry->d_type == DT_LNK)
		{
			Type = "Symbolic link";
		}
		else 
		{
			Type = "Other";
		}

		printf("%s\t :\t %s\n",entry->d_name, Type);
	}

	closedir(dp);

	return 0;
}
//////////////////////////////////////////////////////////////////////////
//                                                                      //
// write a program to accept two file names from user and copy the    	//
// contents of existing file into newly created file                    //
//                                                                      //
// Usage : ./exe existing_file_name new_file_name                       //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int SourceFd = 0;
	int DestFd = 0;
	char Buffer[1024] = {'\0'};
	int iRet = 0;

	if(argc != 3)
	{
		printf("Insufficient number of arguments\n");
		return -1;
	}

	SourceFd = open(argv[1],O_RDONLY);

	if(SourceFd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}

	DestFd = creat(argv[2],0777);

	if(DestFd == -1)
	{
		printf("Unable to create new file\n");
		close(SourceFd);
		return -1;
	}
	
	while((iRet = read(SourceFd,Buffer,sizeof(Buffer))) != 0)
	{
		write(DestFd,Buffer,iRet);
		memset(Buffer,0,sizeof(Buffer));
	}

	close(SourceFd);
	close(DestFd);

	return 0;
}
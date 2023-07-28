//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// write a program which creates new process which is responsible to write  //
// all file names which are present on desktop in demo file which should    //
// be created newly                                                         //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/dir.h>

int CreateCombinedFile()
{
    int fd = 0, Ret = 0;
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char *DeskPath = "/home/prasadsarwar/Desktop";
    char Fname[20];

    dp = opendir(DeskPath);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("Demo.txt",0777);

    if(fd == -1)
    {
        printf("Unable to create combined file\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        Ret = sprintf(Fname,"%s\n",entry->d_name);
        write(fd,Fname,Ret);
    }
    return 0;
}


int main()
{
    int iRet = 0;
    int process2 = 0;

    process2 = fork();

    if(process2 == 0)
    {
        iRet = CreateCombinedFile();

        if(iRet == 0)
        {
            printf("File with data created successfully\n");
        }
    }
    else
    {
        wait(NULL);
        printf("Child process (PID: %d) completed writing file names to Demo.txt\n", process2);
    }
    

    return 0;
}
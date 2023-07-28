//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// write a program which creates 2 process                                  //
// Process 1 count number of capital letters from demo.txt file             //
// Proccess 2 count number of capital letters from hello.txt file           //
// Both processes writes its count in count.txt file                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int CountCapitalLetters(char Fname[])
{
    int fd = 0, Ret = 0;
    char Buffer[1024];
    int iCnt = 0, iCount = 0;

    fd = open(Fname,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file..\n");
        return -1;
    }

    while((Ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        for(iCnt = 0; iCnt < Ret; iCnt++)
        {
            if((Buffer[iCnt] >= 'A') && (Buffer[iCnt] <= 'Z'))
            {
                iCount++;
            }
        }
        memset(Buffer,0,sizeof(Buffer));
    }

    close(fd);

    return iCount;
}

void WriteCount(char Fname[], int iCount)
{
    int fd = 0;
    char str[30];

    sprintf(str,"%s = %d\n",Fname,iCount);

    fd = open("Count.txt",O_WRONLY | O_APPEND);

    if(fd == -1)
    {
        fd = creat("Count.txt",0777);
    }

    write(fd,str,strlen(str));
}

int main()
{
    int iRet = 0, Status = 0;
    int process1 = 0, process2 = 0;

    process1 = fork();

    if(process1 == 0)
    {
        iRet = CountCapitalLetters("Demo.txt");

        if(iRet != -1)
        {
            WriteCount("Demo.txt",iRet);
        }
    }
    else
    {
        process2 = fork();

        if(process2 == 0)
        {
           iRet = CountCapitalLetters("Hello.txt");

            if(iRet != -1)
            {
                WriteCount("Hello.txt",iRet);
            } 
        }
        else
        {
            printf("both process completed successfully... exiting parent process\n");
        }
    }
    return 0;

}
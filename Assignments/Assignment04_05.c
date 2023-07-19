//////////////////////////////////////////////////////////////////////////
//                                                                      //
// write a program which accept name and position from user and         //
// read 20 bytes from that position                                     //
//                                                                      //
// Usage : ./exe File_name Position                                     //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int ret = 0;
    char Arr[20];

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    lseek(fd,atoi(argv[2]),0);

    ret = read(fd,Arr,20);

    printf("Data from file is \n");
    write(1,Arr,ret);

    close(fd);
    return 0;
}

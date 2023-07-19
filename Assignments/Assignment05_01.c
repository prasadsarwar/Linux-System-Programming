//////////////////////////////////////////////////////////////////////////
//                                                                      //
// write a program which writes structure in file. Structure should     //
// contains information of student                                      //
//                                                                      //
// Usage : ./exe output_File_name                                       //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#pragma pack(1)

struct Student
{
    int RollNo;
    char Name[20];
    float marks;
    int age;
};

int main(int argc, char *argv[])
{
    int fd = 0, Ret = 0;
    struct Student sobj;

    if(argc != 2)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        fd = creat(argv[1],0777);
    }

    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    sobj.RollNo = 01;
    strcpy(sobj.Name, "Prasad");
    sobj.marks = 100;
    sobj.age = 18;

    Ret = write(fd,&sobj,sizeof(sobj));

    if(Ret == -1)
    {
        printf("Unable to write in file\n");
        return -1;
    }

    close(fd);

    return 0;
}

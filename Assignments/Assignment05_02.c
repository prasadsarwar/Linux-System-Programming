//////////////////////////////////////////////////////////////////////////
//                                                                      //
// write a program which accepts file name from user which contains     //
// information about student, we have to read all containts of that file//
//                                                                      //
// Usage : ./exe input_file_name                                        //
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

    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    Ret = read(fd,&sobj,sizeof(sobj));

    if(Ret == -1)
    {
        printf("Unable to read from file\n");
        return -1;
    }

    printf("Roll No %d\n",sobj.RollNo);
    printf("Name %s\n",sobj.Name);
    printf("Marks %f\n",sobj.marks);
    printf("Age %d\n",sobj.age);

    close(fd);

    return 0;
}

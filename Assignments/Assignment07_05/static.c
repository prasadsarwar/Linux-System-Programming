#include <stdio.h>
#include <sys/stat.h>
#include "static.h"

void Stat(char *Fname)
{
    struct stat sobj;

    stat(Fname,&sobj);

    if(sobj.st_ino == 0)
    {
        printf("File not found\n");
        return;
    }

    printf("File name : %s\n",Fname);
    printf("Inode number: %d\n",sobj.st_ino);
    printf("File size: %d\n",sobj.st_size);
    printf("Number of links: %d\n",sobj.st_nlink);
    printf("Number of blocks : %d\n",sobj.st_blocks);

}

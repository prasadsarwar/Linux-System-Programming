#include <stdio.h>
#include "static.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    Stat(argv[1]);
    return 0;
}
#include "Perfect.h"

void CheckPerfect(int iNo)
{   
    int iSum = 0, iCnt = 0;

    for(iCnt = 1; iCnt < iNo; iCnt++)
    {
        if(iNo%iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }

    if(iSum == iNo)
    {
        printf("Perfect number\n");
    }
    else
    {
        printf("Not a perfect number\n");
    }
    
}
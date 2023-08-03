#include "Prime.h"

void CheckPrime(int iNo)
{
    int iCnt = 0;

    for(iCnt = 2; iCnt < iNo; iCnt++)
    {
        if((iNo%iCnt) == 0)
        {
            break;
        }
    }

    if(iCnt == iNo)
    {
        printf("Prime Number\n");
    }
    else
    {
        printf("Composite number\n");
    }
}

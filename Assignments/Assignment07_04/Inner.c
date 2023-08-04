#include "Inner.h"

void Factorial(int iNo)
{
    int Fact = 1;

    while(iNo != 0)
    {
        Fact = Fact * iNo;
        iNo--;
    }

    printf("Factorial = %d\n",Fact);
}
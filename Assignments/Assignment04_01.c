//////////////////////////////////////////////////////////////////////////
//                                                                      //
//write a program which is used to demonstrate concept of IO redirection//
//                                                                      //
// Usage : ./exe < output.txt > input.txt                               //
//                                                                      //
// Input.txt : 10 11                                                    //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int main(int argc, char *argv[])
{
    int iNo1 = 0, iNo2 = 0;
    int iRet = 0;

    scanf("%d",&iNo1);
    scanf("%d",&iNo2);

    iRet = iNo1 + iNo2;

    printf("Addition is : %d\n", iRet);

    return 0;
}
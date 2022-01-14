#include<stdio.h>
#include <stdlib.h>
#include <math.h>

float expo(int x,int n){
    float s = 1;
    int fact =1;
    for (int i = 1; i <= n; i++)
    {.  fact *= i;
        s+=pow(x,i)/fact;
    }
    return s;
}

int main(int argc, char const *argv[])
{
    int n,x;
    n=3;
    x=3;
    printf("the value s ; %f", expo(x,n));
    return 0;
}

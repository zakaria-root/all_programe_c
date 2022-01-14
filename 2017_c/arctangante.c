#include <stdio.h>
#include <stdlib.h>
#include <math.h>
    

int main(){

    float var;
    int n;
    printf("enter the value : ");
    scanf("%f",&var);
    printf("enter the order : ");
    scanf("%d",&n);
    float som =0;
    int p;
    int i =0;
    do
    {
        p = 2*i +1;
        som += (pow(-1,i))*(pow(var,p)) / (p);
        i++;
    }while(p<=2*n + 3);
    printf("the value of the arctanate de %.2f est : %.2f\n",var,som);
    return 0;
}


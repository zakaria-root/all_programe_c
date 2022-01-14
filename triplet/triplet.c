#include<stdio.h>
int main(){
    int Max,a,b,c,nbre=0;
    int a2,b2,c2;// représentent resp a*a, b*b et c*c
    printf("Max = "); scanf("%d",&Max);
    for(a=1;a<Max;a++){
        a2=a*a;
        for(b=a+1;b<=Max;b++){
            b2=b*b;
            c=b+1;
            while((c2=c*c)<a2+b2)c++;
            if(c2==a2+b2){
                nbre++;
                printf("(%4d,%4d,%4d)\n",a,b,c);
            }
        }
    } 
    printf("le nbre de triplet : %d\n",nbre);
    return 0;
}

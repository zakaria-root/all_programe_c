#include<stdio.h>
#include<math.h>
/*
    les socles sont numérotés par : 1,2 et 3
    la fixation de de deux socles i et j impique le troisième
    k=6-(i+j)
*/
void DeplacerDisque(int src,int dest){
    printf("--> triez le disque de %d  --> placer le dans %d\n",src,dest);
}
void DeplacerDisques(int n, int src, int dest){
    if(n>0){
        DeplacerDisques(n-1,src,6-src-dest);
        DeplacerDisque(src,dest);
        DeplacerDisques(n-1,6-src-dest,dest);
    }
}

double getTime(int n){ 
    double puis2=pow(2,n);
    printf("puiss=%f %f %f\n",puis2,pow(2,n));
    return (puis2-1)*60/1.e9;
}

double Second2Year(double sec){
    return sec/(24*3600*365.25);
}
int main(){
    int n;
    printf("entrez n : "); scanf("%d",&n);
    DeplacerDisques(n,1,3);
    double temp25,temp32,temp64;
    temp25=getTime(25);
    temp32=getTime(32);
    temp64=Second2Year(getTime(64));
    printf("temp 25 Dis = %f s\ntemp 32 Dis = %f s\n tem pour 64 Dis = %f An\n"
    ,temp25,temp32,temp64);
    return 0;
}
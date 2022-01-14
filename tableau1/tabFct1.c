#include<stdio.h>
#include<math.h>
#define NMAX 1000
double f(double);
double a,b,pas,X[NMAX],Fx[NMAX];
double x,*p,*q;
int i,N;

int main(){
    printf("a= ");scanf("%lf",&a);
    printf("b= ");scanf("%lf",&b);
    printf("pas= ");scanf("%lf",&pas);
    // nbre de pts
    N=(int)((b-a)/pas+1);
    if(N<=NMAX){
        //calcul des abscisses et leurs ordonnées
        for(i=0,x=a;x<=b;i++,x+=pas){
            X[i]=x;
            Fx[i]=f(x);
        }
        //affichage
        printf("X      F(X)\n");
        for(p=X,q=Fx;p<X+N;p++,q++)
            printf("%12.4f%12.4f\n",*p,*q);
    }
    else{
        puts("pb de saturation memoire");
    }
    return 0;
}

double f(double x){
    return sin(x);
}
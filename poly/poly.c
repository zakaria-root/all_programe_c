// la fonction doit lire les coefficients ai, i variant de n à 0
double evaler(double x,int n){
    double p=0,a;
    int i;
    for(i=n;i>=0;i--){
        printf("entrez le coeff a%d : ",i);
        scanf("%lf",&a);
        if (i!=0)
        p=p*x+a;
        else
        p += a;
    }
    return p;
}

int main(){
    int degre;
    double x,p;
    printf("le degre = "); scanf("%d",&degre);
    printf("var x = "); scanf("%lf",&x);
    p=evaler(x,degre);
    printf("p(%.6f)= %.6f\n",x,p);
    return 0;
}
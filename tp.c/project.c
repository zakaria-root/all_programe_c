#include "statistique.c"
#include<stdio.h>



void tester(){
    double m1;
    double m2;
    double m3;
    double m4;
    int choix;
    
    do
    {
        system("cls");
        printf("choisire le nombre des element que vous voulez saisire : ");
        scanf("%d", &choix);

        if (choix == 0)
        {
        system("erreur!!");
        return;
        }

        switch (choix)
        {
        case 1:
            printf("entrer une valeur : \n");
            scanf("%lf", &m1);
            printf("la moyeen des %d valeurs est : %.2f",choix, moy(1,m1));
            _sleep(2000);
            break;
        case 2:
            printf("entrer une valeur N1 : \n");
            scanf("%lf", &m1);
            printf("entrer une valeur N2 : \n");
            scanf("%lf", &m2);
            printf("la moyeen des %d valeurs est : %.2f",choix, moy(2, m1, m2));
            _sleep(2000);
            break;
        case 3:
            printf("entrer une valeur N1 : \n");
            scanf("%lf", &m1);
            printf("entrer une valeur N2 : \n");
            scanf("%lf", &m2);
            printf("entrer une valeur N3 : \n");
            scanf("%lf", &m3);
            printf("la moyeen des %d valeurs est : %.2f",choix,  moy(2, m1, m2,m3));
            _sleep(2000);
        break;
        case 4:
            printf("entrer une valeur N1: \n");
            scanf("%lf", &m1);
            printf("entrer une valeur N2: \n");
            scanf("%lf", &m2);
            printf("entrer une valeur N3: \n");
            scanf("%lf", &m3);
            printf("entrer une valeur N4: \n");
            scanf("%lf", &m4);
            printf("la moyeen des %d valeurs est : %.2f",choix,  moy(2, m1, m2, m3, m4));
            _sleep(2000);
        break;
        default:
            printf("votre choix est errone !!");
            break;
        }
    } while (1);
    

}


int main(){
    int x;
    printf("hellow world zakaria !!!\n");
    tester();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "polynomes.h"
#include "poly_t.h"

int main()
{
    poly_t p;
    poly_t p1,p2,p3;
    int choix;
    printf("-_-__-_-LE PROGRAME DE POLYNOME-_-_-__-_\n\n");
    printf("\t1/ la some des deux polynomes \n");
    printf("\t2/ le produit des deux polynomes \n");
    printf("\tchoisie un nombre parmit la list: ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
    system("cls");
        printf("saisire la premier polynome :\n");
        p1 = saisirPoly();
        system("cls");
        printf("saisire la desieme polynome :\n");
        p2 = saisirPoly();
        system("cls");
        affichePoly(p1);
        printf("\n");
        affichePoly(p2);
        printf("\n");
        printf("la somme des deux polynome  est ==> ");
        p = somePoly(p1,p2);
        p = formuler(p);
        p3 = trieParDegre(p);
        affichePoly(p3);
    break;
    case 2 :
        system("cls");
        printf("saisire la premier polynome :\n");
        p1 = saisirPoly();
        system("cls");
        printf("saisire la desieme polynome :\n");
        p2 = saisirPoly();
        system("cls");
        affichePoly(p1);
        printf("\n");
        affichePoly(p2);
        printf("\n");
        printf("le produit des deux polynome  est ==> ");
        p = produitpoly(p1,p2);
        p = formuler(p);
        p = trieParDegre(p);
        affichePoly(p);
    break;
    default:
        system("cls");
        printf("ce numero n\'existe pas dans la list");
    break;
    }
   
    return 0;
}


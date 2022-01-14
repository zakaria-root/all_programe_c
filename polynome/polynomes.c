#include "polynomes.h"
#include "poly_t.h"
#include <stdio.h>


poly_t saisirPoly(){

    monome_t m;
    poly_t p;
    p.langeur = 0 ;
    int i=0;
    int d;
    int j;
    double c;
    do
    {
        printf("_saisie le degrer du %d monome :", i+1);
        scanf("%d",&m.d);
        if (m.d>0)
        {
            printf("_saisie le conficiant du %d monome :",i+1);
            scanf("%f",&m.coff);
            if (m.coff != 0)
            {
                j=0;
                    while (j<p.langeur && (m.d != p.tab[j].d))
                    j++;
                    
                    if (j!=p.langeur)
                    {
                    
                        p.tab[j].coff = p.tab[j].coff + m.coff;

                    }else{
                        p.tab[i].coff = m.coff;
                        p.tab[i].d = m.d;
                        i++;
                    p.langeur =  p.langeur + 1;
                    }
            }
            
        }
        
    } while (m.d>0);
    
    return p;
}

void affichePoly(poly_t p){
    int i = 0;
    printf("P(X) = ");
    printf("%.1f X^%1d", p.tab[0].coff,p.tab[0].d);
    for ( i = 1; i < p.langeur; i++)
    {
        (p.tab[i].coff < 0)?
            (
            (p.tab[i].coff != 0)? 
            (printf(" - %.1f X^%1d", p.tab[i].coff*-1,p.tab[i].d))
            :
            // (printf(" - %.1f", p.tab[i].coff*-1))
            (printf(""))
            ):
            ( (p.tab[i].coff != 0)? 
            printf(" + %.1f X^%1d", p.tab[i].coff,p.tab[i].d):
            // printf(" + %.1f", p.tab[i].coff)
            (printf(""))
            );
    }
}

poly_t somePoly(poly_t p1, poly_t p2){
    poly_t p3;
    p3 = p1;
    int i;
    int j;
    for ( i = 0; i < p3.langeur; i++)
    {
        for ( j = 0; j < p2.langeur; j++)
        {
            if (p3.tab[i].d == p2.tab[j].d)
            {
                p3.tab[i].coff += p2.tab[j].coff;
            }
        }
    }
    
    for ( i = 0; i < p2.langeur; i++)
    {
        j=0;
        while (j<p3.langeur && p2.tab[i].d != p3.tab[j].d)
        j++;
        if (j == p3.langeur)
        {
            p3.tab[p3.langeur] = p2.tab[i];
            p3.langeur = p3.langeur + 1;
        }
        
        }
        
        return p3;
    }

poly_t produitpoly(poly_t p1, poly_t p2){

    int i,j;
    int k = 0;
    poly_t p3;
    p3 = p1;
    for ( i = 0; i < p1.langeur; i++)
    {
        for ( j = 0; j < p2.langeur; j++)
        {
        p3.tab[k].coff = p1.tab[i].coff * p2.tab[j].coff;
        p3.tab[k].d = p1.tab[i].d + p2.tab[j].d;
        k++;
        p3.langeur = p3.langeur + 1;
        }
    }
    return p3;
}
poly_t trieParDegre(poly_t p){
    int i,j;
    monome_t temp;
    for ( i = 0; i < p.langeur; i++)
    {
        for ( j = 0; j < p.langeur; j++)
        {
            if (p.tab[j].d > p.tab[i].d)
            {
                temp = p.tab[i];
                p.tab[i] = p.tab[j];
                p.tab[j] = temp;
            }
        }
    }
    return p;
}
poly_t formuler(poly_t p){
    int i,j,k;
    int nbr =0;
    poly_t pf;
    float som;
    for ( i = 0; i < p.langeur; i++)
    {
        j=0;
        som = 0;
        k=0;
        for ( j = 0; j < p.langeur; j++)
        {
            if (p.tab[i].d == p.tab[j].d  && i != j)
            {
            som += p.tab[j].coff;
            p.tab[j].coff = 0;
            }
            p.tab[i].coff += som;
    }
    }
    return p;
}
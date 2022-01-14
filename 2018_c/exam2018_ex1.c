#include <stdio.h>
#include <stdlib.h>
    
    int *CreerElements(int n){
        int *tab = malloc(sizeof(int) * n);
        return tab;
    }
    
    void Saisir(int tab[],int n){
        for (int i = 0; i < n; i++)
        {
            printf("tab[%d] = ",i+1);
            scanf ("%d",&tab[i]);
        }
    }

    void DecalerADroite(int tab[],int n){
        
        int temp  = tab[n-1];
        for (int i = n-1; i>0; i--)
        {
            tab[i]=tab[i-1];
        }
        tab[0] = temp;
    }

    void DecalerAGauche(int tab[],int n){
        int temp  = tab[0];
        for (int i = 0; i<n; i++)
        {
            tab[i]=tab[i+1];
        }
        tab[n-1] = temp;
    }

    void SupprimerUneOccurrence(int tab[],int *n, int var){
        int i = 0;
            while (tab[i] != var && i<*n)
            i++;
            if(i != *n){
                for (int j = i; j < *n; j++)
                {
                    tab[j]=tab[j+1];
                }
                *n = *n -1;
            }else{
                printf("la valeur une occurance de tel valeur \n");
            }
            
        }

    void SupprimerOccurrences(int tab[],int *n, int var){
        int count = 0;
        for ( int i = 0; i < *n; i++)
        {
            if (tab[i + count] == var) count++;
            tab[i] = tab[i+ count];
        }
        *n = *n - count;
    }

    void Afficher(int tab[],int n){
        for (int i = 0; i < n; i++)
        {
            printf("tab[%d] = %d \n",i+1,tab[i]);
        }
    } 

int main(){

    int *tab;
    int n;
    int var;
    printf("donne la taille de tableau : ");
    scanf("%d",&n);
    printf("enter l\'element a chercher : ");
    scanf("%d",&var);

    tab = CreerElements(n);
    Saisir(tab, n);
    printf("affichage avant de decalage \n");
    Afficher(tab, n);
    DecalerAGauche(tab, n);
    printf("affichage apres le decalage a gauche \n");
    Afficher(tab, n);
    DecalerADroite(tab, n);
    printf("affichage apres le decalage a droit \n");
    Afficher(tab, n);
    SupprimerOccurrences(tab, &n,var);
    printf("affichage apres la supresion de tout les occurance \n");
    Afficher(tab, n);
    
    
    
    return 0;
}


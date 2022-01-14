#include <stdio.h>
#include <stdlib.h>
    
    typedef struct 
    {
        int *T;
        int nb;
    }TTableauDyn;

    typedef struct Tnoeud
    {
        int val;
        struct Tnoeud *suive;
    }Tnoeud;

    TTableauDyn AllouerTableau(int n){
        int* t = (int*) calloc(n, sizeof(int));
        TTableauDyn tab;
        tab.T = t;
        tab.nb = n;
        return tab;
    }
    void SaisirTableau(TTableauDyn tab){
        int *p = tab.T;
        for ( ; p < tab.T + tab.nb; p++)
        {
            printf("T[%d] = ",p-tab.T);
            scanf("%d",p);
        }
    }

    Tnoeud *creerNoeud(int val){
        Tnoeud *p = (Tnoeud*) malloc(sizeof(Tnoeud));
        p->val = val;
        p->suive = NULL;
        return p;
    }
    
    Tnoeud* TableauToListe(TTableauDyn tab){
        if (!tab.T)
        {printf("la table est vide \n");
        return NULL;}
        else{
            Tnoeud* list = NULL;
            Tnoeud* queue = list;
            int *p = tab.T;
            
            for (; p < tab.T + tab.nb; p++)
                {
                Tnoeud *q = creerNoeud(*p);
                if (!list)
                    list = q;
                else
                {
                    queue->suive = q;
                    queue = q;
                }
            }
            return list;
        }
        
    }

    int* ListeToTableau(Tnoeud * list){
        if (!list)
        {   
            printf("la list est vide \n");
            return NULL;
        }else{
            int taille =0;
            Tnoeud* q = list;
            
            while (q != NULL){
                taille++;
                q=q->suive;
            }
            
            TTableauDyn tab = AllouerTableau(taille);
            int* p = tab.T; 
            q=list;
            while (q != NULL)
            {   
                *p = q->val;
                q = q->suive;
                p++;
            }
            
        return p;
        }
    }
    void affichageTableau(TTableauDyn tab){
        int *p = tab.T;
        for (; p < tab.T +tab.nb; p++)
        {
            printf("\t%d\t", *p);
        }
    }
    void affichageList(Tnoeud* list){
        Tnoeud *p = list;
    while (list != NULL)
    {
        printf("\t%d\t",p->val);
        p=p->suive;
    }
    
    }
int main(){
    int taille;
    Tnoeud* list =NULL;
    printf("enter la taille de la table : ");
    scanf("%d",&taille);
    TTableauDyn tab;
    tab = AllouerTableau(taille);
    
    SaisirTableau(tab);
    list = TableauToListe(tab);
    affichageList(list);
    
    return 0;
}


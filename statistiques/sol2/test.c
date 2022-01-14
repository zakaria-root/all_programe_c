#include<stdio.h>
#include<stdlib.h>
#include"statistiques.h"


void tester(){
    int choix;
    double val1,val2,val3,val4;
    double moy,ecart;
    do{
        //system("cls");
        printf("Souhaitez-vous tester 1, 2, 3 ou 4 valeurs (entrez 0 pour terminer le programme) : ");
        scanf("%d",&choix);
        switch(choix){
            case 0:
                printf("Fin du test des calculs statistiques\n");
                system("pause");
                return;
            case 1:
                printf("Saisissez la première valeur : ");
                scanf("%lf",&val1);
                moy=getMoyenne(1,val1);
                ecart=getEcart(moy,1,val1);
                printf("Moyenne : %f\n",moy);
                printf("Ecart : %f\n",ecart);
                break;
            case 2:
                printf("Saisissez la premiere valeur : ");
                scanf("%lf",&val1);
                printf("Saisissez la deuxieme valeur : ");
                scanf("%lf",&val2);
                moy=getMoyenne(2,val1,val2);
                ecart=getEcart(moy,2,val1,val2);
                printf("Moyenne : %f\n",moy);
                printf("Ecart : %f\n",ecart);
                break;
            case 3:
                printf("Saisissez la premiere valeur : ");
                scanf("%lf",&val1);
                printf("Saisissez la deuxieme valeur : ");
                scanf("%lf",&val2);
                printf("Saisissez la troisieme valeur : ");
                scanf("%lf",&val3);
                moy=getMoyenne(3,val1,val2,val3);
                ecart=getEcart(moy,3,val1,val2,val3);
                printf("Moyenne : %f\n",moy);
                printf("Ecart : %f\n",ecart);
                break;
            case 4:
                printf("Saisissez la premiere valeur : ");
                scanf("%lf",&val1);
                printf("Saisissez la deuxieme valeur : ");
                scanf("%lf",&val2);
                printf("Saisissez la troisieme valeur : ");
                scanf("%lf",&val3);
                printf("Saisissez la quatrieme valeur : ");
                scanf("%lf",&val4);
                moy=getMoyenne(4,val1,val2,val3,val4);
                ecart=getEcart(moy,4,val1,val2,val3,val4);
                printf("Moyenne : %f\n",moy);
                printf("Ecart : %f\n",ecart);
                break;
            default:
                printf("Désolé, le programme ne peut tester que 1, 2, 3 ou 4 valeurs\n");
            
        }

    }while(1);
}




int main(){
    tester();
    return 0;
}
#include"GestionAbs.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


etudiant_t lireEtudiant(){
	etudiant_t x;
	printf("mtr    : ");scanf("%d",&x.mtr);
	printf("nom    : ");scanf("%s",x.nom);
	printf("prenom : ");scanf("%s",x.prenom);
	return x;	
}

void ecrireEtudiantLigne(etudiant_t x,int nbre){
	int i,cumul=0;
	printf("%4d%15s%15s",x.mtr,x.nom,x.prenom);
	for(i=0;i<nbre;i++){
		printf("%4d",x.lstAbs[i]);
		cumul+=x.lstAbs[i];
	}
	printf("%6d\n",cumul);		
}

void ecrireEtudiantCol(etudiant_t x,int nbre){
	int i,cumul=0;
	printf("Mtr:%4d\nNom:%15s\nPrenom:%15s\nAbsences:|",x.mtr,x.nom,x.prenom);
	for(i=0;i<nbre;i++){
		printf("%4d|",x.lstAbs[i]);
		cumul+=x.lstAbs[i];
	}
	printf("\nCumul : %6d\n",cumul);		
}

listEtudiant_t creerListeEtudiant(int taille){
	listEtudiant_t lstEt;
	lstEt.list=(etudiant_t *)malloc(taille*sizeof(etudiant_t));
	lstEt.n=0;
	lstEt.taille=taille;
	lstEt.nbreSean=0;
	return lstEt;
}	
//listeEtudiant_t ajouterEtudiant(listeEtudiant_t,etdudiant_t);
	//ou bien :
void ajouterEtudiant(listEtudiant_t *ptrLstEt, etudiant_t x){
	//précondition ptrLstEt->n<=ptrLstEt->taille
	if(ptrLstEt->n==ptrLstEt->taille){ //liste sturée => réallocation
		ptrLstEt->list=(etudiant_t *)realloc(ptrLstEt->list,2*ptrLstEt->taille*sizeof(etudiant_t));
		ptrLstEt->taille*=2;
	}
	ptrLstEt->list[ptrLstEt->n]=x;
	(ptrLstEt->n)++;
}
void marquerAbs(listEtudiant_t lstEt){
	int i;
	//precondition lstEt.nbreSean<=NBRE_MAX
	if(lstEt.nbreSean<NBRE_MAX){
		// ajouter l'absence
		for(i=0;i<lstEt.n;i++){
			printf("appel à %s (0 --> Present, 1 --> Absent)?",strcat(strcat(lstEt.list[i].nom," "),lstEt.list[i].prenom));
			scanf("%d",&lstEt.list[i].lstAbs[lstEt.nbreSean]);
		}
		lstEt.nbreSean++;
	}else{
		puts("Nbre de seance maximal atteint, impossible de noter l'absence");
		system("pause");
	}
}
void faireBilanAbs(listEtudiant_t lstEt){
	int i,j;
	printf("%4s%15s%15s","Mtr","Nom","Prenom");
	for(j=0;j<lstEt.nbreSean;j++)
		printf("%3s%d","Sea",j+1);
	printf("%4s\n","Cml");
	for(i=0;i<lstEt.n;i++){
		ecrireEtudiantLigne(lstEt.list[i],lstEt.nbreSean);
	}
}
void faireBilanAbsEt(listEtudiant_t lstEt, int i){
	return;
}

listEtudiant_t file2Mem(const char *fileName,int capacite){
	// voir si le fichier existe déjà
	FILE *pf=fopen(fileName,"rb");
	listEtudiant_t lstEt;
	if(pf){ // le fichier existe bien
		fread(&lstEt.n,sizeof(int),1,pf);
		fread(&lstEt.taille,sizeof(int),1,pf);
		fread(&lstEt.nbreSean,sizeof(int),1,pf);
		lstEt.list=(etudiant_t *)malloc(lstEt.taille*sizeof(etudiant_t));
		fread(lstEt.list,sizeof(etudiant_t),lstEt.taille,pf);
		fclose(pf);
	}else{ //le fichier n'existe pas
		lstEt=creerListeEtudiant(capacite);
	}
	return lstEt;
}
void mem2file(const char *fileName,listEtudiant_t lstEt){
	FILE *pf=fopen(fileName,"wb");
	if(pf){ // le fichier est créé ou recréé
		fwrite(&lstEt.n,sizeof(int),1,pf);
		fwrite(&lstEt.taille,sizeof(int),1,pf);
		fwrite(&lstEt.nbreSean,sizeof(int),1,pf);
		fwrite(lstEt.list,sizeof(etudiant_t),lstEt.taille,pf);
		fclose(pf);
	}else{ //le fichier n'existe pas
		puts("Erreur de creation ou de recreation du fichier");
		system("pause");
	}
}

void menu(listEtudiant_t lstEt){
	int choix;
	etudiant_t x;
	do{
		system("cls");
		puts("Ajouter un etudiant ---->   1");		
		puts("Marquer l'absence   ---->   2");
		puts("Bilan d'absence     ---->   3");
		puts("Arret               ---->   6");
		printf("votre choix ? "); scanf("%d",&choix);
		switch(choix){
			case 1 :
				x=lireEtudiant();
				ajouterEtudiant(&lstEt,x);
				break;
			case 2 :
				marquerAbs(lstEt);
				break;
			case 3:
				faireBilanAbs(lstEt);
				break;
			case 6 : 
				return;
			default :
				puts("mauvais choix, refaire");
				
		}
		system("pause");	
	}while(1);
}
//test => fonction main
int main(int argc,char *argv[]){
	listEtudiant_t glsid1;
	// argc => arg count :  nombre d'arguments de la ligne de cmd
	// argv => arg values : tableau liste des arguments
	glsid1=file2Mem("ListeAbsence.dat",10);
	menu(glsid1);
	mem2file("ListeAbsence.dat",glsid1);
	return 0;
}
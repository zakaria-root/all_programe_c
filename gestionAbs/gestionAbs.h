#ifndef _PRESENCES
	#define _PRESENCES
	#define NBRE_MAX 14
	typedef struct{
		int mtr;
		char nom[20],prenom[20];
		//int nbre;
		int lstAbs[NBRE_MAX];
	}etudiant_t; // c'est un type
	 // type listeEtudiants
	 
	typedef struct{
		etudiant_t *list; //liste dynamique
		int n; // le nombre effectif d'étudiants dans le groupe
		int taille; //la capacité de la liste => n<=taille
		int nbreSean;
	}listEtudiant_t;
	
	etudiant_t lireEtudiant();
	void ecrireEtudiantLigne(etudiant_t,int);
	void ecrireEtudiantCol(etudiant_t,int);
	listEtudiant_t creerListeEtudiant(int ); // crée une liste de capacité taille à l'état vide (n=0)
	//listeEtudiant_t ajouterEtudiant(listeEtudiant_t,etdudiant_t);
	//ou bien :
	void ajouterEtudiant(listEtudiant_t *, etudiant_t);
	void marquerAbs(listEtudiant_t );
	void faireBilanAbs(listEtudiant_t);
	void faireBilanAbsEt(listEtudiant_t, int ); //=> une recherche de l'étudiant
	
	listEtudiant_t file2Mem(const char *,int);
	void mem2file(const char *,listEtudiant_t);
	void menu(listEtudiant_t);
#endif

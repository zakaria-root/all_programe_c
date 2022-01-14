#include<stdlib.h>
#include<stdio.h>
#include "matrice.h"
matrice_t creerMatrice(int n){
	matrice_t m;
	int i;
	m.n=n;
	m.vals=(double **)malloc(sizeof(double *)*n);
	for(i=0;i<n;i++)
		m.vals[i]=(double *)calloc(sizeof(double),n);
		//calloc pour initialiser la mémoire dynamique créée à zero	
	return m;	
}
void scanMatrice(matrice_t mat){
	double *p,**q;
	for(q=mat.vals;q<mat.vals+mat.n;q++)
		for(p=*q;p<*q+mat.n;p++){
			printf("[%d][%d]=",(int)(q-mat.vals),(int)(p-*q));
			scanf("%lf",p);
		}
}
void printMatrice(const matrice_t mat){
	double *p,**q;
	for(q=mat.vals;q<mat.vals+mat.n;q++){
		for(p=*q;p<*q+mat.n;p++)
			printf("%10.2f",*p);
		puts("");
	}
	
}

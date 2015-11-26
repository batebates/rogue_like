#include "../include/struct.h"
#include <stdio.h>
#include <assert.h>
#include "../include/IA.h"

/*Fonctions generant le deplacement prochain d'un monstre agressif*/
/*http://www.maths-algo.fr/algo/exercices/grille_plus_court_chemin.htm*/

/*affiche la grille chemin*/
void afficher_grille(t_cellule grille[N][M]){
	int i,j;
	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<M;j++){
			switch(grille[i][j]){
				case 0:
					printf(" ");
					break;
				case 1:
					printf("X");
					break;
				case 2:printf("P");
					break;
				case 3:printf("M");
					break;
			}
		}
	}
	printf("\n");
}

void afficher_chemin(int grille[N][M]){
	int i,j;
	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<M;j++){
			if(grille[i][j]==-2) printf("X");
			else printf("%d",grille[i][j]);
		}
	}
	printf("\n");
}

/*fonction permutant 2 objets de la grille*/
void permutation(t_cellule grille[N][M],t_coord pos_ini,t_coord pos_arr){
	int tampon=grille[pos_arr.x][pos_arr.y];
	grille[pos_arr.x][pos_arr.y]=grille[pos_ini.x][pos_ini.y];
	grille[pos_ini.x][pos_ini.y]=tampon;
}

/*Affiche la recherche du plus court chemin*/
void recherche_chemin(t_cellule grille[N][M],t_coord *p_depart,t_coord arrive){
	int tab_longueur[N][M];
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(grille[i][j]==0 || grille[i][j]==2) tab_longueur[i][j]=-1;
			else if (grille[i][j]==1) tab_longueur[i][j]=-2;
		}
	}
	tab_longueur[p_depart->x][p_depart->y]=0;
	while(tab_longueur[arrive.x][arrive.y]==-1){
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				if(tab_longueur[i][j]==-1){
					int valeur=0;
					int valeur_min=N*M;
					if(tab_longueur[i-1][j]>=0 && valeur_min>tab_longueur[i-1][j]) 
						valeur_min=tab_longueur[i-1][j];
					if(tab_longueur[i+1][j]>=0 && valeur_min>tab_longueur[i+1][j]) 
						valeur_min=tab_longueur[i+1][j];
					if(tab_longueur[i][j-1]>=0 && valeur_min>tab_longueur[i][j-1]) 
						valeur_min=tab_longueur[i][j-1];
					if(tab_longueur[i][j+1]>=0 && valeur_min>tab_longueur[i][j+1]) 
						valeur_min=tab_longueur[i][j+1];

					if(valeur_min==tab_longueur[i-1][j]) 
						valeur=tab_longueur[i-1][j]+1;
					else if(valeur_min==tab_longueur[i+1][j]) 
						valeur=tab_longueur[i+1][j]+1;
					else if(valeur_min==tab_longueur[i][j-1]) 
						valeur=tab_longueur[i][j-1]+1;
					else if(valeur_min==tab_longueur[i][j+1]) 
						valeur=tab_longueur[i][j+1]+1;
					if(valeur!=0) 
						tab_longueur[i][j]=valeur;
				}
			}
		}	
	}
	afficher_chemin(tab_longueur);	
	/*Recuperation du chemin*/
	i=arrive.x;
	j=arrive.y;
	while(tab_longueur[i][j]!=1){
		/*Recherche des coordonnées de la prochaine coordonnée*/
		if(i-1>=0 && tab_longueur[i-1][j]==tab_longueur[i][j]-1) i--;
		else if(i+1<N && tab_longueur[i+1][j]==tab_longueur[i][j]-1) i++;
		else if(j-1>=0 && tab_longueur[i][j-1]==tab_longueur[i][j]-1) j--;
		else if(j+1<M && tab_longueur[i][j+1]==tab_longueur[i][j]-1) j++;
	}
	arrive.x=i;
	arrive.y=j;
	permutation(grille,*p_depart,arrive);
	p_depart->x=i;
	p_depart->y=j;

}


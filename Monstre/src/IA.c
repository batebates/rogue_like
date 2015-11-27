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
int valeur_presente(int grille[N][M],int valeur){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(grille[i][j]==valeur) return 1;
		}
	}
	return 0;
}
int chemin_possible(t_cellule grille[N][M],t_coord a,t_coord b){
	int grille_zone[N][M];
	int i,j,k;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(grille[i][j]==0) grille_zone[i][j]=-1;
			else grille_zone[i][j]=0;
		}
	}
	grille_zone[a.x][a.x]=97;
	grille_zone[b.x][b.x]=98;
	while(k<N*M){
		k++;
		if(!valeur_presente(grille_zone,-1))break;
		printf("je boucle");
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				if(grille_zone[i][j]==-1 && !(i==a.x && j==a.y) && !(i==b.x && j==b.y)){
					if(grille_zone[i-1][j]==97) 
						grille_zone[i][j]=97;
					else if(grille_zone[i+1][j]==97) 
						grille_zone[i][j]=97;
					else if(grille_zone[i][j-1]==97) 
						grille_zone[i][j]=97;
					else if(grille_zone[i][j+1]==97) 
						grille_zone[i][j]=97;
					else if(grille_zone[i-1][j]==98) 
						grille_zone[i][j]=98;
					else if(grille_zone[i+1][j]==98) 
						grille_zone[i][j]=98;
					else if(grille_zone[i][j-1]==98) 
						grille_zone[i][j]=98;
					else if(grille_zone[i][j+1]==98) 
						grille_zone[i][j]=98;
				}
				
			}
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(grille_zone[i][j]+grille_zone[i+1][j]==97+98) return 1;
			else if(grille_zone[i][j]+grille_zone[i-1][j]==97+98) return 1;
			else if(grille_zone[i][j]+grille_zone[i][j+1]==97+98) return 1;
			else if(grille_zone[i][j]+grille_zone[i][j-1]==97+98) return 1;
		}
	}
	return 0;
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
void recherche_chemin(t_cellule grille[N][M],t_coord depart,t_coord arrive){
	int tab_longueur[N][M];
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(grille[i][j]==0 || grille[i][j]==2) tab_longueur[i][j]=-1;
			else if (grille[i][j]==1) tab_longueur[i][j]=-2;
		}
	}
	tab_longueur[depart.x][depart.y]=0;
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
	permutation(grille,depart,arrive);
}
void generation_mob_suivante(t_cellule grille[N][M],t_coord personnage){
	t_coord coordonnee;
	for(coordonnee.x=0;coordonnee.x<N;coordonnee.x++){
		for(coordonnee.y=0;coordonnee.y<M;coordonnee.y++){
			if(grille[coordonnee.x][coordonnee.y]==3 && chemin_possible(grille,personnage,coordonnee)){
				recherche_chemin(grille,coordonnee,personnage);
			}
		}
	}
}


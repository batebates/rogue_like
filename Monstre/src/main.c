
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../include/IA.h"
#include "../include/struct.h"


int main(){
	t_cellule grille[N][M]={{1,1,1,1,1,1,1},
				{1,2,1,0,0,0,1},
				{1,0,0,0,0,0,1},
				{1,1,1,1,0,0,1},
				{1,3,1,0,0,3,1},
				{1,0,0,0,1,0,1},
				{1,1,1,1,1,1,1}};
	t_coord perso={1,1};
	afficher_grille(grille);
	int k;
	for(k=0;k<5;k++){
		generation_mob_suivante(grille,perso);
		afficher_grille(grille);	
		printf("\n");
	}
	return 0;
}

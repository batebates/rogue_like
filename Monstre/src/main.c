
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../include/IA.h"
#include "../include/struct.h"


int main(){
	t_cellule grille[N][M]={{1,1,1,1,1,1,1},
				{1,2,1,0,0,0,1},
				{1,0,0,0,1,0,1},
				{1,1,1,1,1,0,1},
				{1,3,1,0,0,3,1},
				{1,0,0,0,1,0,1},
				{1,1,1,1,1,1,1}};
	t_coord perso={1,1};
	while(grille[perso.x][perso.y]!=3){
			afficher_grille(grille);
			generation_mob_suivante(grille,perso);
			printf("\n");
			sleep(1);
			system("clear");
		}
	return 0;
}

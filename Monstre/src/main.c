
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../include/IA.h"
#include "../include/struct.h"


int main(){
	t_cellule grille[N][M]={{1,1,1,1,1,1,1},
				{1,3,1,0,0,0,1},
				{1,0,0,0,1,0,1},
				{1,1,1,1,1,0,1},
				{1,2,1,0,0,0,1},
				{1,0,0,0,1,0,1},
				{1,1,1,1,1,1,1}};
	t_coord dep={1,1};
	t_coord arr={4,1};
	while(dep.x!=arr.x || dep.y!=arr.y){
        	afficher_grille(grille);
		recherche_chemin(grille,&dep,arr);
        	printf("\n");
        	sleep(1);
        	system("clear");
    	}
	return 0;
}

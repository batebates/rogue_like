
#include<stdio.h>
#include "../include/IA.h"
#include "../include/struct.h"


int main(){
	t_cellule grille[N][M]={{1,1,1,1,1,1,1},
				{1,2,1,0,0,1,1},
				{1,0,0,0,0,0,1},
				{1,1,1,1,1,0,1},
				{1,0,0,0,0,0,1},
				{1,0,0,1,0,0,1},
				{1,1,1,1,1,1,1}};
	t_coord dep={1,1};
	t_coord arr={5,1};
	recherche_chemin(grille,dep,arr);
	return 0;
}

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#include "map.h"
#include "couleur.h"

#define N 30
#define M 80



int main(void){
	char matrice[N][M];
	
	init_matrice(matrice);
	
	afficher_matrice(matrice);
	
}

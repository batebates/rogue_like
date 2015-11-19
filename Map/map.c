#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define N 30
#define M 80
#include "couleur.h"

/*****************************************************************/
/*fonction init_matrice*/
void init_matrice(char matrice[N][M]){
	//declaration
	int i,j;
	for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
           matrice[i][j]='X';
        }
    }
}

/*****************************************************************/
/*fonction afficher_matrice */
void afficher_matrice(char matrice[N][M]){
    //declaration
    int i;
    int j;
   	int a;
	
	
	//couleur('0');

   	printf("\t");
    //ligne du dessus
   	for(i=0;i<N;i++){
        printf("+");
        couleur(30);
        for(a=0;a<M;a++){
            printf("-+");
            couleur(30);
        }
        printf("\n\t|");
        for(j=0;j<M;j++){
            printf("%c|",matrice[i][j]);
            couleur(37);
        }
        printf("\n\t");
        couleur(30);
    }
    //ligne du bas
    printf("+");
    for(a=0;a<M;a++){
        printf("-+");
        couleur(30);
    }
    printf("\n");
    
    couleur(0);
}

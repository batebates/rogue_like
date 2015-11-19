#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define N 30
#define M 80

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

   	printf("\t");
    //ligne du dessus
   	for(i=0;i<N;i++){
        printf("+");
        for(a=0;a<M;a++){
            printf("-+");
        }
        printf("\n\t|");
        for(j=0;j<M;j++){
            printf("%c|",matrice[i][j]);
        }
        printf("\n\t");
    }
    //ligne du bas
    printf("+");
    for(a=0;a<M;a++){
        printf("-+");
    }
    printf("\n");
}

int main(void){
	char matrice[N][M];
	init_matrice(matrice);
	afficher_matrice(matrice);


}

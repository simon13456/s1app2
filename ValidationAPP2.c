#include <stdio.h>
#define rangee 3
#define colonne 3
#define carre 3
#define iteration 100
void AdditionMat(int a[rangee][colonne],int b[rangee][colonne]);
void MultiMat(int a[rangee][colonne],int b[rangee][colonne]);
double sinus(float angle);
float pwr(float base,int ala);
long double factoriel(int nombre);
int main(int argc, char **argv)
{
	printf("%f",sinus(0.5));
	return 0;
}
void AdditionMat(int a[rangee][colonne],int b[rangee][colonne]){
	int c [rangee][colonne];
	for(int i=0;i<carre;i++){
		for(int j=0;j<carre;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	for(int i=0;i<carre;i++){
		printf("|");
		for(int j=0;j<carre;j++){
			printf(" %d",c[i][j]);
		}
		printf("|\n");
	}
}
void MultiMat(int a[carre][carre],int b[carre][carre]){
	int temp=0;
	int c[carre][carre];
	for (int i=0; i < 3; i++){
		for (int j=0; j < 3; j++) {
			for (int k=0; k < 3; k++) {
				temp+=a[i][k]*b[k][j];
			}
			c[i][j]=temp;
			temp=0;
		}
	}
	for(int i=0;i<carre;i++){
		printf("|");
		for(int j=0;j<carre;j++){
			printf(" %d",c[i][j]);
		}
		printf("|\n");
	}
}
double sinus(float angle){
	double reponse=angle;
	int j=3;
	for(int i=2;i<iteration; i++){
		if((i%2)==0){
			reponse-= (pwr(angle,j))/(factoriel(j));
		}
		else{
			reponse+=(pwr(angle,j))/(factoriel(j));
		}
		j+=2;
	}
	return reponse;

}
float pwr(float base,int ala){
	int reponse=base;
	for(int i=1;i<ala; i++){
			reponse*=base;
	}
	return reponse;
}
long double factoriel(int nombre){
	long double reponse = 1;
	for(int i=1; i<=nombre; i++){
		reponse*=i;
	}
	return reponse;
}

#include <stdio.h>
#define rangee 3
#define colonne 3
#define carre 3
#define iteration 10
#define termes 5
#define pi 3.1415

void AdditionMat(int a[rangee][colonne],int b[rangee][colonne]);
void MultiMat(int a[rangee][colonne],int b[rangee][colonne]);
double sinus(float angle);
float pwr(float base,int ala);
long double factoriel(int nombre);
int rechcaractere(char caractere, char tableaucaractere[]);
int palindrome(char mot[]);
double cosinus(double angle);

int main(int argc, char **argv)
{
	printf("La recherche du caractere %c dans le mot anticonstitutionellement est a la position : %d\n", 'n', rechcaractere('n', "anticonstitutionnellement"));
	printf("La recherche du caractere %c dans le mot bonjour est a la position : %d\n", 'e', rechcaractere('e', "bonjour"));
	printf("La recherche du caractere %c dans le mot bonjour est a la position : %d\n", 'r', rechcaractere('r', "bonjour"));
	printf("La recherche du caractere %c dans le mot allocommentcava est a la position : %d\n\n", 'a', rechcaractere('a', "allocommentcava"));
	
	printf("Le calcul du sinus avec l'angle en radian  %d est de : %.4f\n", 1, sinus(1));
	printf("Le calcul du sinus avec l'angle en radian  %d est de : %f\n", 0, sinus(0));
	printf("Le calcul du sinus avec l'angle en radian  %.4f est de : %.4f\n", (pi/4), sinus((pi/4)));
	printf("Le calcul du sinus avec l'angle en radian  %.4f est de : %.4f\n", (pi/2), sinus((pi/2)));
	
	return 0;
}

int rechcaractere(char caractere, char tableaucaractere[])
{	
	int i = 0;
	int longueur_mot = 0;
	
	while (tableaucaractere[i] != '\0')
	{
		longueur_mot++;
		i++;
	}
			
	for (int j=0; j < longueur_mot; j++)
		if (tableaucaractere[j] == caractere)
		{
			return j;
		}
		
	return -1;
}

int palindrome(char mot[])
{
	
	int i = 0;
	int longueur_mot = 0;
	
	while (mot[i] != '\0')
	{
		longueur_mot++;
		i++;
	}
	
	for (int j=0; j <= longueur_mot; j++){
		if (mot[j] == mot[longueur_mot - 1])
		{
			longueur_mot--;
		}
		else
		{
			return 0;
		}
	}
	return 1;	
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

double cosinus(double angle)
{
	double somme = 1;
	int j = 2;
	
	for (int i = 2; i < termes; i++){
		if ((i%2)==0)
			{
				somme -= (pwr(angle,j))/(factoriel(j));
			}
		else
			{
				somme += (pwr(angle,j))/(factoriel(j));
			}
		j+=2;
	}
		
	return somme;
}

float pwr(float base,int ala){
	float reponse=base;
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

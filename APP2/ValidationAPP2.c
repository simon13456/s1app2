/********
Fichier: Validation APP2
Auteurs: Simon Leroux LERS0601
		 Benjamin Gélinas GELB2602
Date: 06/10/2020
Description: Fonctions faisant des opérations mathématiques sans aucune librairie
********/
#include <stdio.h>
#define rangee 3
#define colonne 2
#define carre 3
#define iteration 10
#define termes 5
#define pi 3.1415

void AdditionMat(int a[rangee][colonne],int b[rangee][colonne],int c[rangee][colonne]);
void MultiMat(int a[carre][carre],int b[carre][carre],int c[carre][carre];);
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
	
	int a[rangee][colonne]={{1,2},{3,4},{5,6}};
	int b[rangee][colonne]={{6,5},{4,3},{2,1}};
	int c[rangee][colonne];
	printf("\n L'addition des matrice a et b donne : \n" );
	AdditionMat(a,b,c);
	
	for(int i=0;i<rangee;i++){
		printf("|");
		for(int j=0;j<colonne;j++){
			printf(" %d",c[i][j]);
		}
		printf("|\n");
	}
	return 0;
}
/***************
 * Description:Fonction permetant de trouver l'index d'un caractère dans un tableau de caractères
 * Précondition:
 * Postcondition:
 * **************/
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
/***************
 * Description:Fonction permetant de déterminer si un tableau de caractères est un palindrome
 * Précondition:
 * Postcondition:
 * **************/
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
/***************
 * Description:Fonction permetant d'additionner deux matrices
 * Précondition:
 * Postcondition:
 * **************/
void AdditionMat(int a[rangee][colonne],int b[rangee][colonne],int c[rangee][colonne]){
	for(int i=0;i<rangee;i++){
		for(int j=0;j<colonne;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
}
/***************
 * Description:Fonction permetant d'additionner deux matrice
 * Précondition:
 * Postcondition:
 * **************/
void MultiMat(int a[carre][carre],int b[carre][carre],int c[carre][carre]){
	int temp=0;	
	for (int i=0; i < 3; i++){
		for (int j=0; j < 3; j++) {
			for (int k=0; k < 3; k++) {
				temp+=a[i][k]*b[k][j];
			}
			c[i][j] = temp;
			temp=0;
		}
	}
}
/***************
 * Description:Fonction Permetant de trouver le sinus d'un angle en radian
 * Précondition:
 * Postcondition:
 * **************/
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
/***************
 * Description:Fonction permetant de trouver le cosinus d'un angle en radian
 * Précondition:
 * Postcondition:
 * **************/
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
/***************
 * Description:Fonction permetant de trouver la puissance d'un nombre
 * Précondition:
 * Postcondition:
 * **************/
float pwr(float base,int ala){
	float reponse=base;
	for(int i=1;i<ala; i++){
			reponse*=base;
	}
	return reponse;
}
/***************
 * Description:Fonction permetant de trouver la factoriel d'un nombre
 * Précondition:
 * Postcondition:
 * **************/
long double factoriel(int nombre){
	long double reponse = 1;
	for(int i=1; i<=nombre; i++){
		reponse*=i;
	}
	return reponse;
}

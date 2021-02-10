/*
 * cosinus.c
 * 
 * Copyright 2020 benge <benge@LAPTOP-JGM2CQ2H>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


/********
Fichier: cosinus
Auteurs: Benjamin Gelinas gelb2602
		 Simon Leroux lers0601
Date: 06 octobre 2020
********/

#include <stdio.h>
#define iteration 10
#define termes 10
#define pi 3.1415

double cosinus(double angle);
float pwr(float base,int ala);
long double factoriel(int nombre);

int main(int argc, char **argv)
{
	printf("Le calcul du cosinus avec l'angle en radian  %.4f est de : %.4f\n", 0.0, cosinus(0));
	printf("Le calcul du cosinus avec l'angle en radian  %.4f est de : %.4f\n", pi, cosinus(pi));
	printf("Le calcul du cosinus avec l'angle en radian  %.4f est de : %.4f\n", (pi/6), cosinus(pi/6));
	printf("Le calcul du cosinus avec l'angle en radian  %.4f est de : %.4f\n", (pi/8), cosinus(pi/8));
	
	return 0;
}

/***************
 * Description:Fonction Permetant de trouver le cosinus d'un angle en radian
 * Précondition: L'angle est en radian
 * Postcondition: La valeur est entre -1 et 1
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
 * Précondition: La base et l'exposant sont des reelles
 * Postcondition: La reponse est un reelle
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
 * Précondition: Le nombre est un entier
 * Postcondition: La reponse est un entier
 * **************/
long double factoriel(int nombre){
	long double reponse = 1;
	for(int i=1; i<=nombre; i++){
		reponse*=i;
	}
	return reponse;
}



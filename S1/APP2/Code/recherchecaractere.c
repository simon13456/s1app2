/*
 * recherchecaractere.c
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
Fichier: recherchecaractere
Auteurs: Benjamin Gelinas gelb2602
		 Simon Leroux lers0601
Date: 06 octobre 2020
********/

#include <stdio.h>

int rechcaractere(char caractere, char tableaucaractere[]);


int main(int argc, char **argv)
{
	printf("La recherche du caractere %c dans le mot salut est a la position : %d\n", 's', rechcaractere('s', "salut"));
	printf("La recherche du caractere %c dans le mot Benjamin est a la position : %d\n", 'b', rechcaractere('b', "Benjamin"));
	printf("La recherche du caractere %c dans le mot simon est a la position : %d\n", 'n', rechcaractere('n', "simon"));
	printf("La recherche du caractere %c dans le mot jardin est a la position : %d\n\n", 'z', rechcaractere('z', "jardin"));
	
	return 0;
}

/***************
 * Description:Fonction permetant de trouver l'index d'un caractère dans un tableau de caractères
 * Précondition: Un mot en minuscule qui est un tableau de caractere et un caractere en minuscule
 * Postcondition: La position du caractere etant un entier dans le mot si le caractere est dans le mot
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

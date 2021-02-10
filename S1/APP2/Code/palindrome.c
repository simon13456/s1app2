/*
 * palindrome.c
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
Fichier: palindrome
Auteurs: Benjamin Gelinas gelb2602
		 Simon Leroux lers0601
Date: 06 octobre 2020
********/

#include <stdio.h>

int palindrome(char mot[]);

int main(int argc, char **argv)
{
	printf("Le mot kayak est-il un palindrome? : %d\n", palindrome("kayak"));
	printf("Le mot service est-il un palindrome? : %d\n", palindrome("service"));
	printf("Le mot Laval est-il un palindrome? : %d\n", palindrome("Laval"));
	printf("Le mot pavillon est-il un palindrome? : %d\n", palindrome("pavillon"));

	return 0;
}

/***************
 * Description:Fonction permetant de déterminer si un tableau de caractères est un palindrome
 * Précondition: Le mot doit etre en minuscule 
 * Postcondition: La reponse sera soit 0 ou 1
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

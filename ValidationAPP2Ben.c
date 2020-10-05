/*
 * ValidationAPP2.c
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


#include <stdio.h>
const int termes = 6;
const float pi = 3.1416;

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

int factorielle(double x)
{
	int facto = 1;
	
	for (int i = 1; i <= x; i++)
		facto *= i;
		
	return facto;
}

double exposant(double x, int power)
{	
	double expo = x;
	
	for (int i = 1; i < power; i++)
		expo *= x;
		
	return expo;
}

double cosinus(double x)
{
	double somme = 1;
	int j = 2;
	
	for (int i = 2; i < termes; i++){
		if ((i%2)==0)
			{
				somme -= (exposant(x,j))/(factorielle(j));
			}
		else
			{
				somme += (exposant(x,j))/(factorielle(j));
			}
		j+=2;
	}
		
	return somme;
}

int main()
{		
	return 0;
}


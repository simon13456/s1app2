/*
 * fonctioncos.c
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
const int pi = 3.1416;

int factorielle(int x)
{
	int facto = 1;
	
	for (int i = 1; i <= termes; i++)
		if (i%2==0)
		facto = facto * i;
		
	return facto;
}

int exposant(int x)
{	
	int expo = 1;
	
	for (int i = 1; i <= termes; i++)
		if (i%2==0)
		expo = expo  * x;
		
	return expo;
}

int sommationcos(int x)
{
	int somme = 1;
	
	for (int i = 2; i <= termes; i++)
		for (int j = 0; i%2==0; j++)
			if (j%2==0)
			{
				somme = somme - (exposant(x)/factorielle(x));
			}
			else
			{
				somme = somme + (exposant(x)/factorielle(x));
			}
	return somme;
}

int main()
{
	int x;
	float c;
	
	printf("Entre la valeur de l'angle en radian pour le calcul du cosinus.\n");
	scanf("%d", &x);
	if (x < 0)
	{
		printf("La valeur de x ne peut etre en dessous de 0");
		return 0;
	}
	else if (x > 2*pi)
	{
		printf("La valeur de x ne peut etre plus grand que 2*Pi");
		return 0;
	}
	else
	{
	c = sommationcos(x);
	printf("La valeur du calcul de cosinus est de %f.", c);
	}	
}
		 
		


		

/*
 * addition.c
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
Fichier: addition
Auteurs: Benjamin Gelinas gelb2602
		 Simon Leroux lers0601
Date: 06 octobre 2020
********/

#include <stdio.h>
#define rangee 2
#define colonne 3
#define carre 3

void AdditionMat(int a[rangee][colonne],int b[rangee][colonne],int c[rangee][colonne]);

int main(int argc, char **argv)
{
	
	int a[rangee][colonne]={{1,1,1},{1,1,1}};
	int b[rangee][colonne]={{1,1,1},{1,1,1}};
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
	int d[rangee][colonne]={{2,3,4},{5,6,7}};
	int e[rangee][colonne]={{6,5,4},{3,2,1}};
	printf("\n L'addition des matrice a et b donne : \n" );
	AdditionMat(d,e,c);
	for(int i=0;i<rangee;i++){
		printf("|");
		for(int j=0;j<colonne;j++){
			printf(" %d",c[i][j]);
		}
		printf("|\n");
	}
	int f[rangee][colonne]={{-1,-2,-3},{-4,-5,-6}};
	int g[rangee][colonne]={{-6,-5,-4},{-3,-2,-1}};
	printf("\n L'addition des matrice a et b donne : \n" );
	AdditionMat(f,g,c);
	for(int i=0;i<rangee;i++){
		printf("|");
		for(int j=0;j<colonne;j++){
			printf(" %d",c[i][j]);
		}
		printf("|\n");
	}
	int h[rangee][colonne]={{0,0,0},{0,0,0}};
	int i[rangee][colonne]={{0,0,0},{0,0,0}};
	printf("\n L'addition des matrice a et b donne : \n" );
	AdditionMat(h,i,c);
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
 * Description:Fonction permetant d'additionner deux matrices
 * Précondition: Deux matrice de meme taille
 * Postcondition: Une matrice de taille 3 rangees par 2 colonnes
 * **************/
 
void AdditionMat(int a[rangee][colonne],int b[rangee][colonne],int c[rangee][colonne]){
	for(int i=0;i<rangee;i++){
		for(int j=0;j<colonne;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
}

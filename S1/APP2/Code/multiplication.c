/*
 * multiplication.c
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
Fichier: multiplication
Auteurs: Benjamin Gelinas gelb2602
		 Simon Leroux lers0601
Date: 06 octobre 2020
********/

#include <stdio.h>
#define carre 3

void MultiMat(int a[carre][carre],int b[carre][carre],int c[carre][carre];);

int main(int argc, char **argv)
{
	
	int a[carre][carre]={{0,0,0},{0,0,0},{0,0,0}};
	int b[carre][carre]={{0,0,0},{0,0,0},{0,0,0}};
	int c[carre][carre];
	printf("\n La multiplication des matrices a et b donne : \n" );
	MultiMat(a,b,c);
	
	for(int i=0;i<carre;i++){
		printf("|");
		for(int j=0;j<carre;j++){
			printf(" %d",c[i][j]);
		}
		printf("|\n");
	}
	
	int d[carre][carre]={{1,2,3},{4,5,6},{7,8,9}};
	int e[carre][carre]={{1,2,3},{4,5,6},{7,8,9}};
	int f[carre][carre];
	printf("\n La multiplication des matrices a et b donne : \n" );
	MultiMat(d,e,f);
	
	for(int i=0;i<carre;i++){
		printf("|");
		for(int j=0;j<carre;j++){
			printf(" %d",f[i][j]);
		}
		printf("|\n");
	}
	
	int h[carre][carre]={{5,5,5},{5,5,5},{5,5,5}};
	int v[carre][carre]={{5,5,5},{5,5,5},{5,5,5}};
	int z[carre][carre];
	printf("\n La multiplication des matrices a et b donne : \n" );
	MultiMat(h,v,z);
	
	for(int i=0;i<carre;i++){
		printf("|");
		for(int j=0;j<carre;j++){
			printf(" %d",z[i][j]);
		}
		printf("|\n");
	}
	
	int k[carre][carre]={{-1,-2,-3},{-4,-5,-6},{-7,-8,-9}};
	int l[carre][carre]={{1,2,3},{4,5,6},{7,8,9}};
	int m[carre][carre];
	printf("\n La multiplication des matrices a et b donne : \n" );
	MultiMat(k,l,m);
	
	for(int i=0;i<carre;i++){
		printf("|");
		for(int j=0;j<carre;j++){
			printf(" %d",m[i][j]);
		}
		printf("|\n");
	}
	return 0;
}

/***************
 * Description:Fonction permetant de multiplier deux matrices carrees
 * Précondition: Deux matrices carree de meme taille
 * Postcondition: Une matrice carree
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


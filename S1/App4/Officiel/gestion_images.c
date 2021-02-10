/********
Fichier: gestion_images.c
Auteurs: Simon Leroux lers0601
*		 Benjamin Gélinas gelb2602
Date: 5 novembre 2020
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include "bibliotheque_images.h"
#include "AutoValidation.h"


int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];




int main(){
	AutoValidation();
	return 0;
}

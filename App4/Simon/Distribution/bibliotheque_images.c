/********
Fichier: bibliotheque_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include "bibliotheque_images.h"

int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int *p_maxval, struct MetaData *p_metadonnees){
	FILE *fichier;
	char type[2]; 
	fichier= fopen(nom_fichier,"r");
	fscanf(fichier,"%s %s %s", p_metadonnees->auteur,p_metadonnees->dateCreation,p_metadonnees->lieuCreation);
	fscanf(fichier,"%s",type);
	fscanf(fichier,"%d %d", p_lignes,p_colonnes);
	fscanf(fichier, "%d",p_maxval);
	for(int i=0; i< *p_lignes ; i++){
			for(int j=0; j<*p_colonnes; j++){
				fscanf(fichier, "%d ",&matrice[i][j]);
			}
	}
	fclose(fichier);
    return OK;
}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR],int lignes, int colonnes,int maxval, struct MetaData metadonnees){
	FILE *fichier;
	
	fichier= fopen(nom_fichier,"w");
	
	fprintf(fichier, "#%s %s %s.\n",metadonnees.auteur,metadonnees.dateCreation,metadonnees.lieuCreation);
	fprintf(fichier, "P3\n");
	fprintf(fichier, "%d %d\n", lignes,colonnes);
	fprintf(fichier, "%d\n",maxval);
	for(int i=0; i<lignes; i++){
			for(int j=0; j<colonnes; j++){
				fprintf(fichier, "%d ",matrice[i][j]);
			}
			fprintf(fichier, "\n");
	}
	fclose(fichier);
    return OK;
}
int pgm_couleur_preponderante(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval){
	int couleur[maxval],valMax=0;
	for(int i=0; i<lignes; i++){
		for(int j=0; j<colonnes; j++){
			couleur[matrice[i][j]]++;
		}
	}
	valMax=matrice[0][0];
	
	for(int i=0; i<lignes; i++){
		if(couleur[i]>valMax){
			 valMax=couleur[i];
		}	
	}
	return valMax;
}
int pgm_copier(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2){
	return OK;
}

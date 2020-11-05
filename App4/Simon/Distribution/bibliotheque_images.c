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
	if(fichier== NULL){
		return ERREUR_FICHIER;
	}
	if(fgetc(fichier)=='#'){
		int p=0;
		char c;
		while((c=fgetc(fichier))!=';'){
			p_metadonnees->auteur[p] = c;
			p++;
			
		}
		p=0;
		fgetc(fichier);
		while((c=fgetc(fichier))!=';'){
			p_metadonnees->dateCreation[p] = c;
			p++;
		}
		p=0;
		fgetc(fichier);
		while((c=fgetc(fichier))!='.'){
			p_metadonnees->lieuCreation[p] = c;
			p++;
		}
		p=0;
	}
	fscanf(fichier,"%s",type);
	if(type[0]!='P'||type[1]!='2'){
		return ERREUR_FORMAT;
	}
	fscanf(fichier,"%d %d", *p_lignes,*p_colonnes);
	if((*p_lignes>MAX_HAUTEUR)||(*p_colonnes<MAX_LARGEUR)){
		return ERREUR_TAILLE;
	}
	fscanf(fichier, "%d",*p_maxval);
	if(*p_maxval>MAX_VALEUR){
		return ERREUR;
	}
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
	fprintf(fichier, "#%s; %s; %s.\n",metadonnees.auteur,metadonnees.dateCreation,metadonnees.lieuCreation);
	fprintf(fichier, "P2\n");
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
int pgm_couleur_preponderante(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes){
	int histogramme[MAX_VALEUR+1],valMax=0,pos=0;
	pgm_creer_histogramme(matrice,lignes,colonnes,histogramme);
	valMax=histogramme[0];
	for(int i=0; i<lignes; i++){
		if(histogramme[i]>valMax){
			 valMax=histogramme[i];
			 pos=i;
		}	
	}
	return pos;
}
int pgm_creer_histogramme(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int histogramme[MAX_VALEUR+1]){
	for(int i=0; i<lignes; i++){
		for(int j=0; j<colonnes; j++){
			histogramme[matrice[i][j]]++;
		}
	}
	return OK;
}
int ppm_lire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int *p_maxval, struct MetaData *p_metadonnees){
	FILE *fichier;
	char type[2]; 
	fichier= fopen(nom_fichier,"r");
	if(fgetc(fichier)=='#'){
		int p=0;
		char c;
		while((c=fgetc(fichier))!=';'){
			p_metadonnees->auteur[p] = c;
			p++;
		}
		p=0;
		fgetc(fichier);
		while((c=fgetc(fichier))!=';'){
			p_metadonnees->dateCreation[p] = c;
			p++;
		}
		p=0;
		fgetc(fichier);
		while((c=fgetc(fichier))!='.'){
			p_metadonnees->lieuCreation[p] = c;
			p++;
		}
		p=0;
	}
	fscanf(fichier,"%s",type);
	if(type[0]!='P'||type[1]!='3'){
		return ERREUR_FORMAT;
	}
	fscanf(fichier,"%d %d", p_lignes,p_colonnes);
	if((*p_lignes>MAX_HAUTEUR)||(*p_colonnes<MAX_LARGEUR)){
		return ERREUR_TAILLE;
	}
	fscanf(fichier, "%d",p_maxval);
	if(*p_maxval>MAX_VALEUR){
		return ERREUR;
	}
	for(int i=0; i< *p_lignes ; i++){
			for(int j=0; j<*p_colonnes; j++){
				fscanf(fichier, "%d ",&matrice[i][j].valeurR);
				fscanf(fichier, "%d ",&matrice[i][j].valeurG);
				fscanf(fichier, "%d ",&matrice[i][j].valeurB);
			}
	}
	fclose(fichier);
    return OK;
}
int ppm_ecrire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, struct MetaData metadonnees){
	FILE *fichier;
	fichier= fopen(nom_fichier,"w");
	fprintf(fichier, "#%s; %s; %s.\n",metadonnees.auteur,metadonnees.dateCreation,metadonnees.lieuCreation);
	fprintf(fichier, "P3\n");
	fprintf(fichier, "%d %d\n", lignes,colonnes);
	fprintf(fichier, "%d\n",maxval);
	for(int i=0; i<lignes; i++){
			for(int j=0; j<colonnes; j++){
				fprintf(fichier, "%d ",matrice[i][j].valeurR);
				fprintf(fichier, "%d ",matrice[i][j].valeurG);
				fprintf(fichier, "%d ",matrice[i][j].valeurB);
			}
			fprintf(fichier,"\n");
	}
	fclose(fichier);
    return OK;
}
int ppm_copier(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2){
		if(lignes1!=*p_lignes2||colonnes1!=*p_colonnes2){
				return ERREUR_TAILLE;
		}
		*p_lignes2=lignes1;
		*p_colonnes2=colonnes1;
		for(int i=0; i<lignes1; i++){
			for(int j=0; j<colonnes1; j++){
				matrice2[i][j]=matrice1[i][j];
			}
		}
}

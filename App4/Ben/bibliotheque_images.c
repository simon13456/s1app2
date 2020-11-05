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

int pgm_eclaircir_noircir(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, int valeur){
	
	for (int i=0; i<lignes; i++)
	{
		for (int j=0; j<colonnes; j++)
		{
			if (matrice[i][j]+valeur > maxval){
				matrice[i][j]=maxval;
			}
			else if (matrice[i][j]+valeur < 0){
				matrice[i][j]=0;
			}
			else{
				matrice[i][j]+=valeur;
			}
		}
	}
	return OK;
}

int pgm_creer_negatif(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval){
	
	int valeurPixelini;
	int valeurPixelfinale;
	
	for (int i=0; i<lignes; i++){
		for(int j=0; j<colonnes; j++){
			
			valeurPixelini = matrice[i][j];
			valeurPixelfinale = maxval - valeurPixelini;
			valeurPixelini = valeurPixelfinale;
		}
	}
	return OK;
}

int pgm_extraire(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int lignes2, int colonnes2, int *p_lignes, int *p_colonnes){
	
	int largeur;
	int longueur;
	int temp[MAX_HAUTEUR][MAX_LARGEUR];
	
	largeur = lignes2 - lignes1;
	longueur = colonnes2 - colonnes1;
	
	*p_lignes = largeur;
	*p_colonnes = longueur;
	
	for (int i=0; i<*p_lignes; i++){
		for (int j=0; j<*p_colonnes; j++){
			temp[MAX_HAUTEUR][MAX_LARGEUR] = temp[i][j];
			temp[i][j] = matrice[i][j];
			matrice[i][j] = temp[MAX_HAUTEUR][MAX_LARGEUR];
		}
	}
	
	return OK;
}

int pgm_sont_identiques(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2){
		
	if ((lignes1 != lignes2) || (colonnes1 != colonnes2))
			return DIFFERENTES;
	
	for (int i=0; i<lignes1; i++){
		for (int j=0; j<colonnes1; j++){
			if (matrice1[i][j] != matrice2[i][j]){
				return DIFFERENTES;
		}
	}
}					
	return IDENTIQUES;
}

int pgm_pivoter90(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens){
	
	if (sens == SENS_HORAIRE){
		for (int i=0; i<(*p_lignes/2); i++){
			for (int j=i; j<(*p_colonnes-i-1); j++){
				int temp = matrice[i][j];	
				matrice[i][j] = matrice[*p_colonnes-1-j][i];
				matrice[*p_colonnes-1-j][i] = matrice[*p_lignes-1-i][*p_colonnes-1-j];
				matrice[*p_lignes-1-i][*p_colonnes-1-j] = matrice[j][*p_lignes-1-i]; 
				matrice[j][*p_lignes-1-i] = temp; 	
			}
		}
	}
				
	else if (sens == SENS_ANTIHORAIRE){
		for (int i=0; i<(*p_lignes/2); i++){
			for (int j=i; j<(*p_colonnes-i-1); j++){
				int temp = matrice[i][j];
				matrice[i][j] = matrice[j][*p_lignes-1-i];
				matrice[j][*p_lignes-1-i] = matrice[*p_lignes-1-i][*p_colonnes-1-j];
				matrice[*p_lignes-1-i][*p_colonnes-1-j] = matrice[*p_colonnes-1-j][i]; 
				matrice[*p_colonnes-1-j][i] = temp;
			}
		}
	}	
	return OK;
}

int ppm_sont_identiques(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2){
	
	if (lignes1 != lignes2 || colonnes1 != colonnes2){
		return DIFFERENTES;
	}
	
	for (int i=0; i<lignes1; i++){
		for (int j=0; j<colonnes1; j++){
			if (matrice1[i][j].valeurR != matrice2[i][j].valeurR)
			{
				return DIFFERENTES;
			}
			else if (matrice1[i][j].valeurG != matrice2[i][j].valeurG)
			{
				return DIFFERENTES;
			}
			else if (matrice1[i][j].valeurB != matrice2[i][j].valeurB)
			{
				return DIFFERENTES;
			}
		}
	}
	return IDENTIQUES;
}

int ppm_pivoter90(struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens){
		
		
	struct RGB temp[MAX_HAUTEUR][MAX_LARGEUR];	
		
	if (sens == SENS_HORAIRE){
		for (int i=0; i<(*p_lignes/2); i++){
			for (int j=i; j<(*p_colonnes-i-1); j++){
				temp[i][j].valeurR = matrice[i][j].valeurR;	
				matrice[i][j].valeurR = matrice[*p_colonnes-1-j][i].valeurR;
				matrice[*p_colonnes-1-j][i].valeurR = matrice[*p_lignes-1-i][*p_colonnes-1-j].valeurR;
				matrice[*p_lignes-1-i][*p_colonnes-1-j].valeurR = matrice[j][*p_lignes-1-i].valeurR; 
				matrice[j][*p_lignes-1-i].valeurR = temp[i][j].valeurR;
				
				temp[i][j].valeurG = matrice[i][j].valeurG;	
				matrice[i][j].valeurG = matrice[*p_colonnes-1-j][i].valeurG;
				matrice[*p_colonnes-1-j][i].valeurG = matrice[*p_lignes-1-i][*p_colonnes-1-j].valeurG;
				matrice[*p_lignes-1-i][*p_colonnes-1-j].valeurG = matrice[j][*p_lignes-1-i].valeurG; 
				matrice[j][*p_lignes-1-i].valeurG = temp[i][j].valeurG;
				
				temp[i][j].valeurB = matrice[i][j].valeurB;	
				matrice[i][j].valeurB = matrice[*p_colonnes-1-j][i].valeurB;
				matrice[*p_colonnes-1-j][i].valeurB = matrice[*p_lignes-1-i][*p_colonnes-1-j].valeurB;
				matrice[*p_lignes-1-i][*p_colonnes-1-j].valeurB = matrice[j][*p_lignes-1-i].valeurB; 
				matrice[j][*p_lignes-1-i].valeurB = temp[i][j].valeurB; 	
			}
		}
	}
				
	else if (sens == SENS_ANTIHORAIRE){
		for (int i=0; i<(*p_lignes/2); i++){
			for (int j=i; j<(*p_colonnes-i-1); j++){
				temp[i][j].valeurR = matrice[i][j].valeurR;	
				matrice[i][j].valeurR = matrice[j][*p_lignes-1-i].valeurR;
				matrice[j][*p_lignes-1-i].valeurR = matrice[*p_lignes-1-i][*p_colonnes-1-j].valeurR;
				matrice[*p_lignes-1-i][*p_colonnes-1-j].valeurR = matrice[*p_colonnes-1-j][i].valeurR; 
				matrice[*p_colonnes-1-j][i].valeurR = temp[i][j].valeurR;
				
				temp[i][j].valeurG = matrice[i][j].valeurG;	
				matrice[i][j].valeurG = matrice[j][*p_lignes-1-i].valeurR;
				matrice[j][*p_lignes-1-i].valeurR = matrice[*p_lignes-1-i][*p_colonnes-1-j].valeurR;
				matrice[*p_lignes-1-i][*p_colonnes-1-j].valeurR = matrice[*p_colonnes-1-j][i].valeurR; 
				matrice[*p_colonnes-1-j][i].valeurR = temp[i][j].valeurR;
				
				temp[i][j].valeurR = matrice[i][j].valeurR;	
				matrice[i][j].valeurR = matrice[j][*p_lignes-1-i].valeurR;
				matrice[j][*p_lignes-1-i].valeurR = matrice[*p_lignes-1-i][*p_colonnes-1-j].valeurR;
				matrice[*p_lignes-1-i][*p_colonnes-1-j].valeurR = matrice[*p_colonnes-1-j][i].valeurR; 
				matrice[*p_colonnes-1-j][i].valeurR = temp[i][j].valeurR;
			}
		}
	}	
	return OK;
}


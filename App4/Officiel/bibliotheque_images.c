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
	char type[10]; 
	int col,lig,max;
	fichier= fopen(nom_fichier,"r");
	//si c'est pas existant
	if(fichier== NULL){
		return ERREUR_FICHIER;
	}
	char c='b';
	if((c=fgetc(fichier))=='#'){
		int p=0;
		
		while((c=fgetc(fichier))!=';' && c!='\n'&& c!='\0'){
			p_metadonnees->auteur[p] = c;
			p++;
		}
		p_metadonnees->auteur[p]='\0';
		p=0;
		while((c=fgetc(fichier))!=';'&& c!='\n'&&c!='\0'){
			p_metadonnees->dateCreation[p] = c;
			p++;
			
		}
		p_metadonnees->dateCreation[p]='\0';
		p=0;
		while((c=fgetc(fichier))!='.'&& c!='\n'&&c!='\0'){
			p_metadonnees->lieuCreation[p] = c;
			p++;
		}
		p_metadonnees->lieuCreation[p]='\0';
	}
	fscanf(fichier,"%s",type);
	if((c!='P'||type[0]!='2')&&(type[0]!='P'||type[1]!='2')){
		return ERREUR_FORMAT;
	}
	fscanf(fichier,"%d %d",p_colonnes,p_lignes);
	if((*p_lignes>MAX_HAUTEUR)||(*p_colonnes>MAX_LARGEUR)){
		return ERREUR_TAILLE;
	}
	fscanf(fichier, "%d",p_maxval);
	if(*p_maxval>MAX_VALEUR){
		return ERREUR_TAILLE;
	}
	for(int i=0; i< *p_lignes ; i++){
			for(int j=0; j<*p_colonnes; j++){
				fscanf(fichier, "%d",&matrice[i][j]);
			}
	}
	fclose(fichier);
    return OK;
}
int ppm_lire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int *p_maxval, struct MetaData *p_metadonnees){
	FILE *fichier;
	char type[10]; 
	int col,lig,max;
	fichier= fopen(nom_fichier,"r");
	//si c'est pas existant
	if(fichier== NULL){
		return ERREUR_FICHIER;
	}
	char c='b';
	if((c=fgetc(fichier))=='#'){
		int p=0;
		
		while((c=fgetc(fichier))!=';' && c!='\n'&& c!='\0'){
			p_metadonnees->auteur[p] = c;
			p++;
		}
		p_metadonnees->auteur[p]='\0';
		p=0;
		while((c=fgetc(fichier))!=';'&& c!='\n'&&c!='\0'){
			p_metadonnees->dateCreation[p] = c;
			p++;
			
		}
		p_metadonnees->dateCreation[p]='\0';
		p=0;
		while((c=fgetc(fichier))!='.'&& c!='\n'&&c!='\0'){
			p_metadonnees->lieuCreation[p] = c;
			p++;
		}
		p_metadonnees->lieuCreation[p]='\0';
	}
	fscanf(fichier,"%s",type);
	if((c!='P'||type[0]!='3')&&(type[0]!='P'||type[1]!='3')){
		return ERREUR_FORMAT;
	}
	fscanf(fichier,"%d %d",p_colonnes,p_lignes);
	if((*p_lignes>MAX_HAUTEUR)||(*p_colonnes>MAX_LARGEUR)){
		return ERREUR_TAILLE;
	}
	fscanf(fichier, "%d",p_maxval);
	if(*p_maxval>MAX_VALEUR){
		return ERREUR_TAILLE;
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
int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR],int lignes, int colonnes,int maxval, struct MetaData metadonnees){
	FILE *fichier;
	fichier= fopen(nom_fichier,"w");
	fprintf(fichier, "#%s;%s;%s\n",metadonnees.auteur,metadonnees.dateCreation,metadonnees.lieuCreation);
	fprintf(fichier, "P2\n");
	fprintf(fichier, "%d %d\n", colonnes,lignes);
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
int ppm_ecrire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, struct MetaData metadonnees){
	FILE *fichier;
	fichier= fopen(nom_fichier,"w");
	fprintf(fichier, "#%s;%s;%s\n",metadonnees.auteur,metadonnees.dateCreation,metadonnees.lieuCreation);
	fprintf(fichier, "P3\n");
	fprintf(fichier, "%d %d\n", colonnes,lignes);
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

int ppm_copier(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2){
		*p_lignes2=lignes1;
		*p_colonnes2=colonnes1;
		for(int i=0; i<lignes1; i++){
			for(int j=0; j<colonnes1; j++){
				matrice2[i][j].valeurR=matrice1[i][j].valeurR;
				matrice2[i][j].valeurG=matrice1[i][j].valeurG;
				matrice2[i][j].valeurB=matrice1[i][j].valeurB;
			}
		}
		return OK;
}
int pgm_copier(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2){
		*p_lignes2=lignes1;
		*p_colonnes2=colonnes1;
		for(int i=0; i<lignes1; i++){
			for(int j=0; j<colonnes1; j++){
				matrice2[i][j]=matrice1[i][j];
			}
		}
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
			matrice[i][j]=valeurPixelfinale;
		}
	}
	return OK;
}

int pgm_extraire(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int lignes2, int colonnes2, int *p_lignes, int *p_colonnes){
	
	int largeur;
	int hauteur;
	int temp[MAX_HAUTEUR][MAX_LARGEUR];
	if (lignes1>*p_lignes||lignes2>*p_lignes||colonnes1>*p_colonnes||colonnes2>*p_colonnes||lignes1>lignes2||colonnes1>colonnes2||(lignes2-lignes1+1)>*p_lignes||(colonnes2-colonnes1+1)>*p_colonnes)
	{
		return ERREUR_TAILLE;
	}
	*p_lignes = lignes2 - lignes1+1;
	*p_colonnes = colonnes2 - colonnes1+1;
	int k=0,f=0;
	for (int i=lignes1; i<=lignes2; i++){
		for (int j=colonnes1; j<=colonnes2; j++){
			matrice[f][k] = matrice[i][j];
			k++;
		}
		f++;
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

int ppm_pivoter90(struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens){
	struct RGB transpos[MAX_HAUTEUR][MAX_LARGEUR];
	int tempCol;
	
	tempCol=*p_colonnes;
	*p_colonnes=*p_lignes;
	*p_lignes=tempCol;
	
	if (sens == SENS_HORAIRE){
		for (int i=0; i<*p_lignes; i++){
			for (int j=0; j<*p_colonnes; j++){
				 	transpos[i][j].valeurR=matrice[*p_colonnes-j-1][i].valeurR;
					transpos[i][j].valeurG=matrice[*p_colonnes-j-1][i].valeurG;
					transpos[i][j].valeurB=matrice[*p_colonnes-j-1][i].valeurB;
			}
		}
	}else if (sens == SENS_ANTIHORAIRE){
		for (int i=0; i<*p_lignes; i++){
			for (int j=0; j<*p_colonnes; j++){
				transpos[i][j].valeurR=matrice[j][*p_lignes-i-1].valeurR;
				transpos[i][j].valeurG=matrice[j][*p_lignes-i-1].valeurG;
				transpos[i][j].valeurB=matrice[j][*p_lignes-i-1].valeurB;
			}
		}
	}else{
		return ERREUR;
	}
	
	for (int i=0; i<*p_lignes; i++){
			for (int j=0; j<*p_colonnes; j++){
				matrice[i][j].valeurR=transpos[i][j].valeurR;
				matrice[i][j].valeurG=transpos[i][j].valeurG;
				matrice[i][j].valeurB=transpos[i][j].valeurB;
		}
	}
	
	return OK;
}
int pgm_pivoter90(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens){
	int transpos[MAX_HAUTEUR][MAX_LARGEUR];
	int tempCol;
	
	tempCol=*p_colonnes;
	*p_colonnes=*p_lignes;
	*p_lignes=tempCol;
	
	if (sens == SENS_HORAIRE){
		for (int i=0; i<*p_lignes; i++){
			for (int j=0; j<*p_colonnes; j++){
				 	transpos[i][j]=matrice[*p_colonnes-j-1][i];
			}
		}
	}else if (sens == SENS_ANTIHORAIRE){
		for (int i=0; i<*p_lignes; i++){
			for (int j=0; j<*p_colonnes; j++){
				transpos[i][j]=matrice[j][*p_lignes-i-1];
			}
		}
	}else{
		return ERREUR;
	}
	
	for (int i=0; i<*p_lignes; i++){
			for (int j=0; j<*p_colonnes; j++){
				matrice[i][j]=transpos[i][j];
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



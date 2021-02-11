/*
*   La classe MonInterface teste l'interface usager VisiTest (librairie).
*   
*   $Author: bruc2001 $
*   $Date: 2018-02-13 08:54:36 -0500 (mar., 13 févr. 2018) $
*   $Revision: 108 $
*   $Id: MonInterface.h 108 2018-02-13 13:54:36Z bruc2001 $
*
*   Copyright 2016 Département de génie électrique et génie informatique
*                  Université de Sherbrooke  
*/
#ifndef MONINTERFACE_H
#define MONINTERFACE_H

#include "VisiTest.h"
#include "CommunicationFPGA.h"
#include "Vecteur.h"
#include "Pile.h"
#include "file.h"
class MonInterface : public VisiTest
{
public:
	MonInterface(const char *theName);
	void setArchive(const DonneesTest& data);
	void setArchive(const int num, const int total);
	void resetArchive();

	virtual void sauvegarder(char* nomFichier);

	void setTest(const DonneesTest& data);
	void resetTest();

	void message(const char* msg);
public slots:
	 void testSuivant();
	 void demarrer();
	 void arreter();
	 void vider();
	 void modeFile();
	 void modePile();

	 void premier();
	 void dernier();
	 void precedent();
	 void suivant();
private:
	CommunicationFPGA Com;
	DonneesTest donnee;
	Pile <DonneesTest>pile;
	File <DonneesTest>file;
	bool sauvegarde = false;
};

#endif // MONINTERFACE_H
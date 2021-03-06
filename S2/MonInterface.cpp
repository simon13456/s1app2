/*
*   Voir fichier d'entête pour informations.
*   
*   $Author: bruc2001 $
*   $Date: 2018-02-13 08:54:36 -0500 (mar., 13 févr. 2018) $
*   $Revision: 108 $
*   $Id: MonInterface.cpp 108 2018-02-13 13:54:36Z bruc2001 $
*
*   Copyright 2013 Département de génie électrique et génie informatique
*                  Université de Sherbrooke  
*/
#include <QStyleFactory>
#include "MonInterface.h"

MonInterface::MonInterface(const char * theName) : VisiTest(theName)
{
	donnee.typeTest = 1;
	donnee.registreSW = 1;
	donnee.retourSW = 1;

	donnee.registreLD = 1;
	donnee.valeurLD = 1;

	donnee.etatLD = 1;
	donnee.etatSW = 1;

	resetTest();
	resetArchive();
}

void MonInterface::setArchive(const DonneesTest& data)
{
}

void MonInterface::setArchive(const int num, const int total)
{
}

void MonInterface::resetArchive()
{
}

void MonInterface::sauvegarder(char* nomFichier)
{

}

void MonInterface::setTest(const DonneesTest& data)
{
}

void MonInterface::resetTest()
{
}

void MonInterface::message(const char* msg)
{
}

void MonInterface::demarrer()
{
	sauvegarde = true;
}

void MonInterface::arreter()
{
	sauvegarde = false;
}

void MonInterface::vider()
{
}

void MonInterface::modeFile()
{
}

void MonInterface::modePile()
{
}

void MonInterface::premier()
{
}

void MonInterface::dernier()
{
}

void MonInterface::precedent()
{
}

void MonInterface::suivant()
{
}

void MonInterface::testSuivant()
{
	setTest(donnee);
	setArchive(donnee);
	setArchive(donnee.typeTest, donnee.registreSW);
   
   if(donnee.etatLD > 0x80)
	{
		donnee.typeTest = 1;

		donnee.registreSW = 1;
		donnee.retourSW = 1;

		donnee.registreLD = 1;
		donnee.valeurLD = 1;

		donnee.etatLD = 1;
		donnee.etatSW = 1;
	}
	else
	{
		donnee.typeTest++;
		
		donnee.registreSW++;
		donnee.retourSW <<= 1;

		donnee.registreLD++;
		donnee.valeurLD <<= 1;

		donnee.etatLD <<= 1;
		donnee.etatSW <<= 1;
	}

   message("bye");
}

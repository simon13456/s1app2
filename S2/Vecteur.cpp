#include "Vecteur.h"
template<typename Var>
Vecteur<Var>::Vecteur::Vecteur()
{
	taille = 0;
	tab = new Var * [0];
}
template<typename Var>
Vecteur<Var>::Vecteur::~Vecteur()
{
	viderTab();
}
template<typename Var>
inline void Vecteur<Var>::viderTab()
{
	for (int i = 0; i < taille; i++) {
		moinsUn();
	}
}

template<typename Var>
int Vecteur<Var>::taille()
{
	return taille;
}

template<typename Var>
bool Vecteur<Var>::estVide()
{
	if (!taille == 0) {
		return false;
	}
	return true;
}

template<typename Var>
void Vecteur<Var>::pushback(Var* valeur)
{
	plusUn();
	tab[taille] = valeur;
}

template<typename Var>
Var* Vecteur<Var>::pop(int index,bool kill)
{
	if (kill)
	{
		Var temp;
		temp = tab[index];
		tab[index] = nullptr;
		compresser();
		return temp;
	}
	else
	{
		return tab[index];
	}
}
template<typename Var>
Var* Vecteur<Var>::pop(int index)
{
	return tab[index];
}

template<typename Var>
void Vecteur<Var>::plusUn()
{
	Var** temptab = new Var * [taille+1];
	for (int i = 0; i < taille - 1; i++) {
		temptab[i] = tab[i];
	}

	taille++;
	delete tab;
	tab = temptab;
}

template<typename Var>
void Vecteur<Var>::moinsUn()
{
	Var** temptab = new Var * [taille - 1];
	tab[taille - 1] = nullptr;
	for (int i = 0; i < taille - 2; i++) {
		temptab[i] = tab[i];
	}
	taille--;
	delete tab;
	tab = temptab;
}

template<typename Var>
void Vecteur<Var>::compresser()
{
	int nouvelleTaille = 0;
	for (int i = 0; i < taille; i++) {
		if (tab[i]!= nullptr)
		{
			nouvelleTaille++;
		}
	}
	int destination = 0;
	Var** temptab = new Var * [nouvelleTaille];
	for (int i = 0; i < taille - 1; i++) {
		if (tab[i] != nullptr)
		{
			temptab[destination] = tab[i];
			destination++;
		}
	}
	delete tab;
	tab = temptab;
}

#pragma once
#pragma once
#include "Vecteur.h"
template<typename Var>
class File
{
public:
	File();
	~File();
	void viderTab();
	int taille();
	Var pop();
	void add(Var valeur);
private:
	int index = 0;
	Vecteur<Var> tab;
};

template<typename Var>
inline File<Var>::File()
{
}

template<typename Var>
inline File<Var>::~File()
{
}

template<typename Var>
inline void File<Var>::viderTab()
{
	tab.viderTab;
}

template<typename Var>
inline int File<Var>::taille()
{
	return tab.taille();
}

template<typename Var>
inline Var File<Var>::pop()
{
	return tab.pop(1, true);
}

template<typename Var>
inline void File<Var>::add(Var valeur)
{
	tab+=valeur;
}
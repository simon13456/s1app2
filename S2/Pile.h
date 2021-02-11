#pragma once
#include "Vecteur.h"
template<typename Var>
class Pile 
{
public:
	Pile();
	~Pile();
	void viderTab();
	int taille();
	Var pop();
	void add(Var valeur);
private:
	int index = 0;
	Vecteur<Var> tab;
};

template<typename Var>
inline Pile<Var>::Pile()
{
}

template<typename Var>
inline Pile<Var>::~Pile()
{
}

template<typename Var>
inline void Pile<Var>::viderTab()
{
	tab.viderTab();
}

template<typename Var>
inline int Pile<Var>::taille()
{
	return tab.taille();
}

template<typename Var>
inline Var Pile<Var>::pop()
{
	return tab.pop(tab.taille()-1,true);
}

template<typename Var>
inline void Pile<Var>::add(Var valeur)
{
	tab.pushback(valeur);
}

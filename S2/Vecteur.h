#pragma once
template <typename Var>
class Vecteur
{
	/*
	friend ostream& operator<<  <Var>(ostream & out, Vecteur c)
	{
		for (int i = 0; i < c.taille()-1; i++)
		{
			out << tab[i];
		}
	};
	*/
public:
	Vecteur();;
	~Vecteur();
	void viderTab();
	int taille();
	bool estVide();
	void pushback(Var valeur);
	Var pop(int index, bool kill);
	Var pop(int index);
	void operator+=(Var valeur)
	{
		pushback(valeur);
	};
	void operator--()
	{
		itemCourant--;
	}; 
	void operator++()
	{
		itemCourant++;
	};
	Var* operator[](int i)
	{
		return tab[i];
	};
protected:
	void plusUn();
	void moinsUn();
	void compresser();

	int itemCourant = 0;
	int tailleTab;
	Var* tab;
};
template<typename Var>
Vecteur<Var>::Vecteur::Vecteur()
{
	tailleTab = 0;
	tab = new Var [0];
}
template<typename Var>
Vecteur<Var>::Vecteur::~Vecteur()
{
	viderTab();
}
template<typename Var>
inline void Vecteur<Var>::viderTab()
{
	for (int i = 0; i < tailleTab; i++) {
		moinsUn();
	}
}

template<typename Var>
int Vecteur<Var>::taille()
{
	return tailleTab;
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
void Vecteur<Var>::pushback(Var valeur)
{
	plusUn();
	tab[tailleTab] = valeur;
}

template<typename Var>
Var Vecteur<Var>::pop(int index, bool kill)
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
Var Vecteur<Var>::pop(int index)
{
	return tab[index];
}

template<typename Var>
void Vecteur<Var>::plusUn()
{
	Var* temptab = new Var  [tailleTab + 1];
	for (int i = 0; i < tailleTab - 1; i++) {
		temptab[i] = tab[i];
	}
	tailleTab++;
	delete tab;
	tab = temptab;
}

template<typename Var>
void Vecteur<Var>::moinsUn()
{
	Var* temptab = new Var  [tailleTab - 1];
	for (int i = 0; i < tailleTab - 2; i++) {
		temptab[i] = tab[i];
	}
	tailleTab--;
	delete tab;
	tab = temptab;
}

template<typename Var>
void Vecteur<Var>::compresser()
{
	int nouvelleTaille = 0;
	for (int i = 0; i < tailleTab; i++) {
		if (tab[i] != nullptr)
		{
			nouvelleTaille++;
		}
	}
	int destination = 0;
	Var* temptab = new Var  [nouvelleTaille];
	for (int i = 0; i < tailleTab - 1; i++) {
		if (tab[i] != nullptr)
		{
			temptab[destination] = tab[i];
			destination++;
		}
	}
	delete tab;
	tab = temptab;
}

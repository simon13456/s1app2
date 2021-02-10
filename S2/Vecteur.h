#pragma once
template <typename Var>
class Vecteur
{
public:
	Vecteur();
	~Vecteur();
	void viderTab();
	int taille();
	bool estVide();
	void pushback(Var* valeur);
	Var* pop(int index, bool kill);
	Var* pop(int index);
protected:
	void plusUn();
	void moinsUn();
	void compresser();

	int tailleTab;
	Var** tab;
};


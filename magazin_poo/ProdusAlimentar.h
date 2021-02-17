#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "Produs.h"
class ProdusAlimentar :public Produs
{
private:
	string marca;
public:

	ProdusAlimentar();

	ProdusAlimentar(int idProdus, string numeProdus, int cantitate, double pret, string categorie, string marca);

	ProdusAlimentar(const ProdusAlimentar& p);

	~ProdusAlimentar();

	ProdusAlimentar& operator=(const ProdusAlimentar& p);

	string getMarca();

	void setMarca(string marca);

	double reducere(double procentaj);

	friend istream& operator>>(istream& in, ProdusAlimentar& pa);

	friend ostream& operator<<(ostream& out, ProdusAlimentar& pa);

	void afisare();

	void scriereFisBinar(ofstream& out);

	void citireFisBinar(ifstream& in);

	void afisareText(ofstream& out);
};




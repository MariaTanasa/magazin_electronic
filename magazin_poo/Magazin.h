#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "Produs.h"
using namespace std;
class Magazin
{
private:
	int nrProduse;
	Produs** produse;
public:

	Magazin();

	Magazin(int nrProduse, Produs** produse);

	Magazin(const Magazin& pr);

	~Magazin();

	Magazin& operator=(const Magazin& m);

	int getNrProduse();

	void setNrProduse(int nrProduse);

	Produs** getProduse();

	void setProduse(Produs** produse, int nrProduse);

	void adaugareProduse(Produs* p);

	friend ostream& operator<<(ostream& out, Magazin& m);

	void afisare();

	void stergereProduse(Produs* p, int idProdus);

	void adaugareProduseInBinar(Produs** produse);

	void citireProduseDinBinar();

	Produs* cautareId(Produs** produse, int id);

	void modificarePret(int id, double procentaj);

	Produs& operator[](int id);

	void operator()(double marire, int id);

	Produs* getProdus(Magazin m, int id);

};

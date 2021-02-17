#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "Produs.h"
class ProdusElectronic : public Produs
{
private:
	int garantie;
public:

	ProdusElectronic();

	ProdusElectronic(int idProdus, string numeProdus, int cantitate, double pret, string categorie, int garantie);

	ProdusElectronic(const ProdusElectronic& p);

	~ProdusElectronic();

	ProdusElectronic& operator=(const ProdusElectronic& p);

	int getGarantie();

	void setGarantie(int garantie);

	void afisare();

	friend istream& operator>>(istream& in, ProdusElectronic& pe);

	friend ostream& operator<<(ostream& out, ProdusElectronic& pe);

	void scriereFisBinar(ofstream& out);

	void citireFisBinar(ifstream& in);

	double reducere(double procentaj);

	void afisareText(ofstream& out);

};
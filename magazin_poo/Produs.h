#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include "ExceptiePret.h"
#include "InterfataProdus.h"
#include "ExceptieIdProdus.h"


using namespace std;

class Produs :InterfataProdus
{
private:
	int idProdus;
	string numeProdus;
	int cantitate;
	double pret;
	string subcategorie;
public:
	Produs();

	Produs(int idProdus, string numeProdus, int cantitate, double pret, string subcategorie);

	Produs(const Produs& produs);

	~Produs();

	Produs& operator=(const Produs& produs);

	int getIdProdus();

	void setIdProdus(int idProdus);

	string getNumeProdus();

	void setNumeProdus(string numeProdus);

	int getCantitate();

	void setCantitate(int cantitate);

	double getPret();

	void setPret(double pret);

	string getSubcategorie();

	void setSubcategorie(string subcategorie);

	friend istream& operator>>(istream& in, Produs& p);

	friend ostream& operator<<(ostream& out, Produs& p);

	friend ofstream& operator<<(ofstream& out, Produs& p);

	virtual void afisare();

	void scriereFisBinar(ofstream& out);

	void citireFisBinar(ifstream& in);

	double reducere(double procentaj);

	virtual void afisareText(ofstream& out);

	bool operator==(Produs& prod);

};

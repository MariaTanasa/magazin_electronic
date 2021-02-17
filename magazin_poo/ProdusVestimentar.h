#pragma once
#include<string>
#include<vector>

#include "Produs.h"
class ProdusVestimentar : public Produs
{
private:
	string material;
public:

	ProdusVestimentar();

	ProdusVestimentar(int idProdus, string numeProdus, int cantitate, double pret, string categorie, string material);

	ProdusVestimentar(const ProdusVestimentar& p);

	~ProdusVestimentar();

	ProdusVestimentar& operator=(const ProdusVestimentar& p);

	string getMaterial();

	void setMaterial(string material);

	friend istream& operator>>(istream& in, ProdusVestimentar& pv);

	friend ostream& operator<<(ostream& out, ProdusVestimentar& pv);

	void scriereFisBinar(ofstream& out);

	void citireFisBinar(ifstream& in);

	void afisare();

	double reducere(double procentaj);

	void afisareText(ofstream& out);

};
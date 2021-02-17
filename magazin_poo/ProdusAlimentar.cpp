#include "ProdusAlimentar.h"
#include<string>
#include<iostream>

ProdusAlimentar::ProdusAlimentar()
{
	marca = " ";
}

ProdusAlimentar::ProdusAlimentar(int idProdus, string numeProdus, int cantitate, double pret, string categorie, string marca)
	:Produs(idProdus, numeProdus, cantitate, pret, categorie)
{
	this->marca = marca;
}

ProdusAlimentar::ProdusAlimentar(const ProdusAlimentar& p) : Produs(p)
{
	this->marca = p.marca;

}

ProdusAlimentar::~ProdusAlimentar()
{
}

ProdusAlimentar& ProdusAlimentar::operator=(const ProdusAlimentar& p)
{
	if (this != &p) {
		Produs::operator=(p);
		this->marca = p.marca;
	}
	return *this;
}

string ProdusAlimentar::getMarca()
{
	return marca;
}

void ProdusAlimentar::setMarca(string marca)
{
	if (!marca.empty()) {
		this->marca = marca;
	}
	else throw new exception("Error: Marca nu a fost initilizata.");

}

double ProdusAlimentar::reducere(double procentaj)
{
	double x = Produs::getPret() - 4 * procentaj / 100 * Produs::getPret();
	Produs::setPret(x);
	return Produs::getPret();
}


void ProdusAlimentar::afisare()
{
	Produs::afisare();
	cout << "\nMarca produsului alimentar este: " << marca << endl;
}

void ProdusAlimentar::scriereFisBinar(ofstream& out)
{
	Produs::scriereFisBinar(out);

	int l = marca.size() + 1;
	out.write((char*)&l, sizeof(l));
	out.write(marca.c_str(), l);
}

void ProdusAlimentar::citireFisBinar(ifstream& in)
{
	Produs::citireFisBinar(in);
	int l = 0;
	in.read((char*)&l, sizeof(l));
	char aux[100];
	in.read(aux, l);
	marca = aux;
}

void ProdusAlimentar::afisareText(ofstream& out)
{
	Produs::afisareText(out);
	out << "Marca produsului alimentar este: " << marca << endl << endl;

}

istream& operator>>(istream& in, ProdusAlimentar& pa)
{
	in >> (Produs&)pa;
	cout << "Marca produsului alimentar este: ";
	getline(in, pa.marca);

	return in;
}

ostream& operator<<(ostream& out, ProdusAlimentar& pa)
{
	out << (Produs&)pa;
	out << "Marca produsului alimentar este: " << pa.marca << endl;
	return out;
}

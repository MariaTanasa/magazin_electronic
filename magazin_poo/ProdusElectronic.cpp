#include "ProdusElectronic.h"
#include<string>

ProdusElectronic::ProdusElectronic()
{
	garantie = 0;
}

ProdusElectronic::ProdusElectronic(int idProdus, string numeProdus, int cantitate, double pret, string categorie, int garantie)
	:Produs(idProdus, numeProdus, cantitate, pret, categorie)
{
	this->garantie = garantie;
}

int ProdusElectronic::getGarantie()
{
	return garantie;
}

ProdusElectronic::~ProdusElectronic()
{
}

ProdusElectronic::ProdusElectronic(const ProdusElectronic& p) : Produs(p)
{
	this->garantie = p.garantie;

}


void ProdusElectronic::setGarantie(int garantie)
{
	if (garantie > 0) {
		this->garantie = garantie;
	}
	else throw new exception("Error: Garantia trebuie sa fie un numar pozitiv.");
}

void ProdusElectronic::afisare()
{
	Produs::afisare();
	cout << "\nGarantia produsului (nr de luni): " << garantie << endl;

}

ProdusElectronic& ProdusElectronic::operator=(const ProdusElectronic& p)
{
	if (this != &p) {
		Produs::operator=(p);
		this->garantie = p.garantie;
	}
	return *this;
}

void ProdusElectronic::scriereFisBinar(ofstream& out)
{
	Produs::scriereFisBinar(out);

	out.write((char*)&garantie, sizeof(garantie));

}

void ProdusElectronic::citireFisBinar(ifstream& in)
{
	Produs::citireFisBinar(in);

	in.read((char*)&garantie, sizeof(garantie));
}

double ProdusElectronic::reducere(double procentaj)
{
	double x = Produs::getPret() - 2 * procentaj / 100 * Produs::getPret();
	Produs::setPret(x);
	return Produs::getPret();
}

void ProdusElectronic::afisareText(ofstream& out)
{
	Produs::afisareText(out);
	out << "Garantia produsului (nr de luni): " << garantie << endl << endl;
}

istream& operator>>(istream& in, ProdusElectronic& pe)
{
	in >> (Produs&)pe;
	cout << "Garantia produsului (nr de luni): "; in >> pe.garantie;

	return in;
}

ostream& operator<<(ostream& out, ProdusElectronic& pe)
{
	out << (Produs&)pe;
	out << "Garantia produsului (nr de luni): " << pe.garantie << endl;
	return out;
}
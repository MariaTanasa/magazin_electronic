#include "Produs.h"
#include<string>


Produs::Produs()
{
	idProdus = 0;
	numeProdus = " ";
	cantitate = 0;
	pret = 0.0;
	subcategorie = " ";
}

Produs::Produs(int idProdus, string numeProdus, int cantitate, double pret, string subcategorie)
{
	if (idProdus >= 0) {
		this->idProdus = idProdus;
	}
	else throw new ExceptieIdProdus();
	if (!numeProdus.empty()) {
		this->numeProdus = numeProdus;
	}
	else throw new exception("Error: Numele produsului nu a fost initializat.");
	if (cantitate >= 0) {
		this->cantitate = cantitate;
	}
	else throw new exception("Error: Cantitatea din stoc trebuie sa fie pozitiva.");
	if (pret > 0) {
		this->pret = pret;
	}
	else throw new ExceptiePret();
	if (!subcategorie.empty()) {
		this->subcategorie = subcategorie;
	}
	else throw new exception("Error: Subcategoria nu a fost initializata.");
}

Produs::~Produs()
{
}

Produs::Produs(const Produs& produs)
{
	this->idProdus = produs.idProdus;
	this->numeProdus = produs.numeProdus;
	this->cantitate = produs.cantitate;
	this->pret = produs.pret;
	this->subcategorie = produs.subcategorie;
}

Produs& Produs::operator=(const Produs& produs)
{
	if (this != &produs) {
		this->idProdus = produs.idProdus;
		this->numeProdus = produs.numeProdus;
		this->cantitate = produs.cantitate;
		this->pret = produs.pret;
		this->subcategorie = produs.subcategorie;
	}
	return *this;
}

int Produs::getIdProdus()
{
	return idProdus;
}

void Produs::setIdProdus(int idProdus)
{
	if (idProdus >= 0) {
		this->idProdus = idProdus;
	}
	else throw new ExceptieIdProdus();
}

string Produs::getNumeProdus()
{
	return numeProdus;
}

void Produs::setNumeProdus(string numeProdus)
{
	if (!numeProdus.empty()) {
		this->numeProdus = numeProdus;
	}
	else throw new exception("Error: Numele produsului nu a fost initializat.");
}

int Produs::getCantitate()
{
	return cantitate;
}

void Produs::setCantitate(int cantitate)
{
	if (cantitate >= 0) {
		this->cantitate = cantitate;
	}
	else throw new exception("Error: Cantitatea din stoc trebuie sa fie pozitiva.");
}

double Produs::getPret()
{
	return pret;
}

void Produs::setPret(double pret)
{
	if (pret > 0) {
		this->pret = pret;
	}
	else throw new ExceptiePret();
}

string Produs::getSubcategorie()
{
	return subcategorie;
}

void Produs::setSubcategorie(string subcategorie)
{
	if (!subcategorie.empty()) {
		this->subcategorie = subcategorie;
	}
	else throw new exception("Error: Subcategoria nu a fost initializata.");
}

void Produs::afisare()
{
	cout << "\nId produs: " << idProdus;
	cout << "\nNume produs: " << numeProdus;
	cout << "\nCantitate: " << cantitate;
	cout << "\nPret produs: " << pret;
	cout << "\nSubcategorie: " << subcategorie;
}

void Produs::scriereFisBinar(ofstream& out)
{
	out.write((char*)&idProdus, sizeof(idProdus));

	int l1, l2;
	l1 = numeProdus.size() + 1;
	out.write((char*)&l1, sizeof(l1));
	out.write(numeProdus.c_str(), l1);

	out.write((char*)&cantitate, sizeof(cantitate));

	out.write((char*)&pret, sizeof(pret));

	l2 = subcategorie.size() + 1;
	out.write((char*)&l2, sizeof(l2));

	out.write(subcategorie.c_str(), l2);
}

void Produs::citireFisBinar(ifstream& in)
{
	in.read((char*)&idProdus, sizeof(idProdus));

	int l1 = 0;
	in.read((char*)&l1, sizeof(l1));
	char aux1[100];
	in.read(aux1, l1);
	numeProdus = aux1;

	in.read((char*)&cantitate, sizeof(cantitate));

	in.read((char*)&pret, sizeof(pret));

	int l2 = 0;
	in.read((char*)&l2, sizeof(l2));
	char aux2[100];
	in.read(aux2, l2);
	subcategorie = aux2;

}

double Produs::reducere(double procentaj)
{
	pret = pret - procentaj / 100 * pret;
	return pret;
}

void Produs::afisareText(ofstream& out)
{
	out << "Id produs: " << idProdus << endl;
	out << "Nume produs: " << numeProdus << endl;
	out << "Cantitate: " << cantitate << endl;
	out << "Pret produs: " << pret << endl;
	out << "Subcategorie: " << subcategorie << endl;
}

bool Produs::operator==(Produs& prod)
{
	return prod.getIdProdus() == idProdus;
}

istream& operator>>(istream& in, Produs& p)
{
	cout << "Id-ul produsului: "; in >> p.idProdus;
	if (p.idProdus < 0) throw new ExceptieIdProdus();

	cout << "Nume produs: ";
	getchar();
	getline(in, p.numeProdus);

	cout << "Cantitate: "; in >> p.cantitate;

	cout << "Pret produs: "; in >> p.pret;
	if (p.pret < 0) throw new ExceptiePret();

	cout << "Subcategorie: ";
	getchar();
	getline(in, p.subcategorie);

	return in;
}

ostream& operator<<(ostream& out, Produs& p)
{
	out << "\nId produs: " << p.idProdus << endl;
	out << "Nume produs: " << p.numeProdus << endl;
	out << "Cantitate: " << p.cantitate << endl;
	out << "Pret produs: " << p.pret << endl;
	out << "Subcategorie: " << p.subcategorie << endl;

	return out;
}

ofstream& operator<<(ofstream& out, Produs& p)
{
	out << p.idProdus << endl;
	out << p.numeProdus << endl;
	out << p.cantitate << endl;
	out << p.pret << endl;
	out << p.subcategorie << endl;
	return out;
}
#include "ProdusVestimentar.h"
#include<string>

ProdusVestimentar::ProdusVestimentar()
{
	material = " ";
}

ProdusVestimentar::ProdusVestimentar(int idProdus, string numeProdus, int cantitate, double pret, string categorie, string material)
	:Produs(idProdus, numeProdus, cantitate, pret, categorie)
{
	this->material = material;
}

ProdusVestimentar::ProdusVestimentar(const ProdusVestimentar& p) : Produs(p)
{
	this->material = p.material;
}

ProdusVestimentar::~ProdusVestimentar()
{
}

ProdusVestimentar& ProdusVestimentar::operator=(const ProdusVestimentar& p)
{
	if (this != &p) {
		Produs::operator=(p);
		this->material = p.material;
	}
	return *this;
}

string ProdusVestimentar::getMaterial()
{
	return material;
}

void ProdusVestimentar::setMaterial(string material)
{
	if (!material.empty()) {
		this->material = material;
	}
	else throw new exception("Error: Materialul nu a fost initializat.");
}

void ProdusVestimentar::scriereFisBinar(ofstream& out)
{
	Produs::scriereFisBinar(out);

	int l = material.size() + 1;
	out.write((char*)&l, sizeof(l));
	out.write(material.c_str(), l);
}

void ProdusVestimentar::citireFisBinar(ifstream& in)
{
	Produs::citireFisBinar(in);
	int l = 0;
	in.read((char*)&l, sizeof(l));
	char aux[100];
	in.read(aux, l);
	material = aux;
}

void ProdusVestimentar::afisare()
{
	Produs::afisare();
	cout << "\nMaterial: " << material << endl;

}

double ProdusVestimentar::reducere(double procentaj)
{
	double x = Produs::getPret() - 3 * procentaj / 100 * Produs::getPret();
	Produs::setPret(x);
	return Produs::getPret();
}

void ProdusVestimentar::afisareText(ofstream& out)
{
	Produs::afisareText(out);
	out << "Material: " << material << endl << endl;
}

istream& operator>>(istream& in, ProdusVestimentar& pv)
{
	in >> (Produs&)pv;
	cout << "Material: ";
	getline(in, pv.material);

	return in;
}

ostream& operator<<(ostream& out, ProdusVestimentar& pv)
{
	out << (Produs&)pv;
	out << "Material: " << pv.material << endl;
	return out;
}
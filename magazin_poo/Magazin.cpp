#include "Magazin.h"

Magazin::Magazin()
{
	nrProduse = 0;
	produse = nullptr;
}

Magazin::Magazin(int nrProduse, Produs** produse)
{
	if (nrProduse < 0) throw new exception("Error: Nr de produse trebuie sa fie pozitiv.");
	else {
		this->nrProduse = nrProduse;
	}
	if (produse != nullptr) {
		this->produse = new Produs * [nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->produse[i] = produse[i];
		}
	}
	else throw new exception("Error: Vectorul de produse e gol.");

}

Magazin::Magazin(const Magazin& pr)
{
	this->nrProduse = pr.nrProduse;
	this->produse = new Produs * [pr.nrProduse];
	for (int i = 0; i < pr.nrProduse; i++) {
		this->produse[i] = pr.produse[i];
	}
}

Magazin::~Magazin()
{
	if (produse != nullptr) {
		delete[] produse;
	}
}

Magazin& Magazin::operator=(const Magazin& m)
{
	if (this != &m) {
		this->produse = new Produs * [m.nrProduse];
		for (int i = 0; i < m.nrProduse; i++) {
			this->produse[i] = m.produse[i];
		}
	}
	return *this;
}

Produs** Magazin::getProduse()
{
	return produse;
}

void Magazin::setProduse(Produs** produse, int nrProduse)
{
	if (produse != nullptr) {
		this->nrProduse = nrProduse;
		delete[] produse;

		this->produse = new Produs * [nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->produse[i] = produse[i];
		}
	}
	else throw new exception("Error: Vectorul de produse e gol.");

}

int Magazin::getNrProduse()
{
	return nrProduse;
}

void Magazin::setNrProduse(int nrProduse)
{
	if (nrProduse < 0) throw new exception("Error: Nr de produse trebui sa fie pozitiv.");
	else {
		this->nrProduse = nrProduse;
	}
}

void Magazin::adaugareProduse(Produs* p)
{
	if (p != nullptr) {
		Produs** aux = new Produs * [nrProduse + 1];
		for (int i = 0; i < nrProduse; i++) {
			aux[i] = produse[i];
		}
		delete[] produse;
		aux[nrProduse++] = p;
		produse = aux;
	}
	else {
		cout << "Este nullptr";
	}
}

void Magazin::afisare()
{
	cout << "\n\nMagazinul are " << nrProduse << " produse.";
	cout << "\nProdusele sunt urmatoarele: " << endl;
	for (int i = 0; i < nrProduse; i++) {
		produse[i]->afisare();
	}
}

Produs* Magazin::cautareId(Produs** produse, int id)
{
	int ok = 0;
	for (int i = 0; i < nrProduse && ok; i++) {
		if (produse[i]->getIdProdus() == id) {
			ok = 1;
			return produse[i];
		}
	}

}
void Magazin::modificarePret(int id, double procentaj)
{
	for (int i = 0; i < nrProduse; i++) {
		if (produse[i]->getIdProdus() == id) {
			produse[i]->reducere(procentaj);
			produse[i]->afisare();
		}
	}

	cout << "\nReducerea a fost aplicata." << endl;
}
void Magazin::stergereProduse(Produs* p, int idProdus)
{
	if (p != nullptr) {
		Produs** aux = new Produs * [nrProduse - 1];
		int nr = 0;
		for (int i = 0; i < nrProduse; i++) {
			if (produse[i]->getIdProdus() != idProdus) {
				aux[nr] = produse[i];
				nr++;
			}
		}
		delete[] produse;
		nrProduse--;
		produse = aux;
	}
	else {
		cout << "Este nullptr";
	}

}

void Magazin::adaugareProduseInBinar(Produs** produse)
{
	ofstream fisBinarOut("produse.dat", ios::out | ios::binary);
	if (fisBinarOut.is_open()) {
		for (int i = 0; i < nrProduse; i++) {
			produse[i]->scriereFisBinar(fisBinarOut);

		}
		fisBinarOut.close();
	}
	else {
		cout << "Fisierul produse.dat nu a putut fi deschis pentru citire.\n";
	}
}

void Magazin::citireProduseDinBinar()
{
	ifstream fisBinarIn("produse.dat", ios::in | ios::binary);
	if (fisBinarIn.is_open()) {
		for (int i = 0; i < nrProduse; i++) {
			cout << "----------------------------------" << endl;
			produse[i]->citireFisBinar(fisBinarIn);
			produse[i]->afisare();

		}
		fisBinarIn.close();
	}
	else {
		cout << "Fisierul produse.dat nu a putut fi deschis pentru citire.\n";
	}
}
Produs& Magazin::operator[](int id)
{
	for (int i = 0; i < nrProduse; i++) {
		if (id == produse[i]->getIdProdus()) {
			return *produse[i];
		}
	}
}

void Magazin::operator()(double marire, int id)
{
	for (int i = 0; i < nrProduse; i++) {
		if (id == produse[i]->getIdProdus()) {
			produse[i]->setPret(produse[i]->getPret() + marire);
		}
	}
}

Produs* Magazin::getProdus(Magazin m, int id)
{
	for (int i = 0; i < nrProduse; i++) {
		if (id == m.produse[i]->getIdProdus()) {
			return produse[i];
		}
	}
}

ostream& operator<<(ostream& out, Magazin& m)
{
	out << "\nMagazinul are " << m.nrProduse << " produse.";
	out << "\nProdusele sunt urmatoarele: " << endl;
	for (int i = 0; i < m.nrProduse; i++) {
		cout << *m.produse[i];
	}
	return out;
}
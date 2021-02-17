#include "Client.h"


Client::Client()
{
	numeClient = " ";
	email = " ";
	adresa = " ";
	nrTelefon = " ";
	nrProdCos = 0;
	cos = nullptr;
}

Client::Client(string numeClient, string email, string adresa, string nrTelefon)
{

	if (!numeClient.empty()) {
		this->numeClient = numeClient;
	}
	else throw new exception("Error: Numele clientului nu a fost initializat.");
	if (!email.empty()) {
		this->email = email;
	}
	else throw new exception("Error: Adresa de email nu a fost initializata.");
	if (!adresa.empty()) {
		this->adresa = adresa;
	}
	else throw new exception("Error: Adresa nu a fost initializata.");

	if (!nrTelefon.empty()) {
		this->nrTelefon = nrTelefon;
	}
	else throw new exception("Error: Nr. de telefon nu este initializat.");
}


Client::Client(string numeClient, string email, string adresa, string nrTelefon, int nrProdCos, Produs** cos)
{
	if (!numeClient.empty()) {
		this->numeClient = numeClient;
	}
	else throw new exception("Error: Numele clientului nu a fost initializat.");
	if (!email.empty()) {
		this->email = email;
	}
	else throw new exception("Error: Adresa de email nu a fost initializata.");
	if (!adresa.empty()) {
		this->adresa = adresa;
	}
	else throw new exception("Error: Adresa nu a fost initializata.");

	if (!nrTelefon.empty()) {
		this->nrTelefon = nrTelefon;
	}
	else throw new exception("Error: Nr. de telefon nu este initializat.");
	if (nrProdCos >= 0) {
		this->nrProdCos = nrProdCos;
	}
	else throw new exception("Error: Nr de produse din cos trebuie sa fie un numar pozitiv.");
	if (cos != nullptr) {
		this->cos = new Produs * [nrProdCos];
		for (int i = 0; i < nrProdCos; i++) {
			this->cos[i] = cos[i];
		}
	}
	else throw new exception("Error: Cosul de produse e gol.");

}

Client::Client(const Client& client)
{
	this->numeClient = client.numeClient;
	this->email = client.email;
	this->adresa = client.adresa;
	this->nrTelefon = client.nrTelefon;
	this->nrProdCos = client.nrProdCos;
	this->cos = new Produs * [client.nrProdCos];
	for (int i = 0; i < client.nrProdCos; i++) {
		this->cos[i] = client.cos[i];
	}
}

Client& Client::operator=(const Client& client)
{
	if (this != &client) {
		this->numeClient = client.numeClient;
		this->email = client.email;
		this->adresa = client.adresa;
		this->nrTelefon = client.nrTelefon;
		this->nrProdCos = client.nrProdCos;
		this->cos = new Produs * [client.nrProdCos];
		for (int i = 0; i < client.nrProdCos; i++) {
			this->cos[i] = client.cos[i];
		}
	}
	return *this;
}


Client::~Client()
{
	if (cos != nullptr) {
		delete[] cos;
	}
}

string Client::getNumeClient()
{
	return numeClient;
}

void Client::setNumeClient(string numeClient)
{
	if (!numeClient.empty()) {
		this->numeClient = numeClient;
	}
	else throw new exception("Error: Numele clientului nu a fost initializat.");
}

string Client::getEmail()
{
	return email;
}

void Client::setEmail(string email)
{
	if (!email.empty()) {
		this->email = email;
	}
	else throw new exception("Error: Adresa de email nu a fost initializata.");
}

string Client::getAdresa()
{
	return adresa;
}

void Client::setAdresa(string adresa)
{
	if (!adresa.empty()) {
		this->adresa = adresa;
	}
	else throw new exception("Error: Adresa nu a fost initializata.");
}

string Client::getNrTelefon()
{
	return nrTelefon;
}

void Client::setNrTelefon(string nrTelefon)
{
	if (!nrTelefon.empty()) {
		this->nrTelefon = nrTelefon;
	}
	else throw new exception("Error: Nr. de telefon nu este initializat.");
}

int Client::getNrProdCos()
{
	return nrProdCos;
}

void Client::setNrProdCos(int nrProdCos)
{
	if (nrProdCos >= 0) {
		this->nrProdCos = nrProdCos;
	}
	else throw new exception("Error: Nr de produse din cos trebuie sa fie un numar pozitiv.");
}

Produs** Client::getProduseCos()
{
	return cos;
}

void Client::setProduseCos(Produs** cos, int nrProdCos)
{
	if (cos != nullptr) {
		this->nrProdCos = nrProdCos;
		delete[] cos;

		this->cos = new Produs * [nrProdCos];
		for (int i = 0; i < nrProdCos; i++) {
			this->cos[i] = cos[i];
		}
	}
	else throw new exception("Error: Cosul cu produse e gol.");
}

void Client::adaugaProduseInCos(Magazin m, int id)
{
	Produs** aux = new Produs * [nrProdCos + 1];
	for (int i = 0; i < nrProdCos; i++) {
		aux[i] = cos[i];
	}
	delete[] cos;
	aux[nrProdCos++] = m.getProdus(m, id);
	cos = aux;
}

void Client::stergeProduseDinCos(Produs* p, int idProdus)
{
	if (p != nullptr) {
		Produs** aux = new Produs * [nrProdCos - 1];
		int nr = 0;
		for (int i = 0; i < nrProdCos; i++) {
			if (cos[i]->getIdProdus() != idProdus) {
				aux[nr] = cos[i];
				nr++;
			}
		}
		delete[] cos;
		nrProdCos--;
		cos = aux;
	}
}

void Client::afisare()
{
	cout << "\nCosul contine " << nrProdCos << " produse." << endl;
	for (int i = 0; i < nrProdCos; i++) {
		cos[i]->afisare();
	}
}

Produs* Client::cautareId(Produs** cos, int id)
{
	int ok = 0;
	for (int i = 0; i < nrProdCos && ok; i++) {
		if (cos[i]->getIdProdus() == id) {
			ok = 1;
			return cos[i];
		}
	}
}

void Client::scriereDateClientInBinar(ofstream& out)
{
	out.write((char*)&idClient, sizeof(idClient));

	int l1 = numeClient.size() + 1;
	out.write((char*)&l1, sizeof(l1));
	out.write(numeClient.c_str(), l1);

	int l2 = email.size() + 1;
	out.write((char*)&l2, sizeof(l2));
	out.write(email.c_str(), l2);

	int l3 = adresa.size() + 1;
	out.write((char*)&l3, sizeof(l3));
	out.write(adresa.c_str(), l3);

	int l4 = nrTelefon.size() + 1;
	out.write((char*)&l4, sizeof(l4));
	out.write(nrTelefon.c_str(), l4);
}

void Client::citireDateClientDinBinar(ifstream& in)
{
	int dim1 = 0, dim2 = 0, dim3 = 0, dim4 = 0;
	char aux[150];

	in.read((char*)&idClient, sizeof(idClient));

	in.read((char*)&dim1, sizeof(dim1));
	in.read(aux, dim1);
	numeClient = aux;

	in.read((char*)&dim2, sizeof(dim2));
	in.read(aux, dim2);
	email = aux;

	in.read((char*)&dim3, sizeof(dim3));
	in.read(aux, dim3);
	adresa = aux;

	in.read((char*)&dim4, sizeof(dim4));
	in.read(aux, dim4);
	nrTelefon = aux;

}

void Client::adaugareComandaInBinar(Client& c, Produs** cos)
{
	ofstream fisBinarOut("comanda.dat", ios::out | ios::binary | ios::app);
	if (fisBinarOut.is_open()) {
		c.scriereDateClientInBinar(fisBinarOut);
		for (int i = 0; i < nrProdCos; i++) {
			cos[i]->scriereFisBinar(fisBinarOut);
		}
		cout << "\nComanda dumneavoastra a fost trimisa." << endl;
		fisBinarOut.close();
	}
	else {
		cout << "Fisierul comanda.dat nu a putut fi deschis pentru citire.\n";
	}

}

void Client::citireComandaDinBinarPeRand(Client& c)
{
	ifstream fisBinarIn("comanda.dat", ios::in | ios::binary);
	if (fisBinarIn.is_open()) {
		c.citireDateClientDinBinar(fisBinarIn);
		cout << c;
		for (int i = 0; i < nrProdCos; i++) {
			cout << "----------------------------------" << endl;
			cos[i]->citireFisBinar(fisBinarIn);
			cos[i]->afisare();
		}
		cout << "\nComanda a fost citita cu succes!\n";
		fisBinarIn.close();
	}
	else {
		cout << "Fisierul produse.dat nu a putut fi deschis pentru citire.\n";
	}
}

void Client::citireComandaDinBinar(Client& c, list<int>listaNrComenzi)
{
	list<int>::iterator itrLista;

	ifstream fisBinarIn("comanda.dat", ios::in | ios::binary);
	if (fisBinarIn.is_open()) {
		for (itrLista = listaNrComenzi.begin(); itrLista != listaNrComenzi.end(); itrLista++) {
			cout << endl;
			c.citireDateClientDinBinar(fisBinarIn);
			cout << c;
			for (int i = 0; i < *itrLista; i++) {
				cout << "----------------------------------" << endl;
				cos[i]->citireFisBinar(fisBinarIn);
				cos[i]->afisare();
			}
		}
		fisBinarIn.close();
	}
	else {
		cout << "Fisierul produse.dat nu a putut fi deschis pentru citire.\n";
	}
}


void Client::adaugareComandaInText(Client& c, Produs** cos, int nrProdCos)
{
	ofstream fisTextOut("comanda.txt");
	if (fisTextOut.is_open()) {
		fisTextOut << c;
		for (int i = 0; i < nrProdCos; i++) {
			cos[i]->afisareText(fisTextOut);
		}
		fisTextOut.close();
	}
	else {
		cout << "Fisierul comanda.txt nu a putut fi deschis pentru scriere.\n";
	}
}

void Client::adaugareComenziTotaleInText(Client& c, Produs** cos, int nrProdCos)
{
	ofstream fisTextOut("comenziMagazin.txt", ios::app);
	if (fisTextOut.is_open()) {
		fisTextOut << c;
		for (int i = 0; i < nrProdCos; i++) {
			cos[i]->afisareText(fisTextOut);
		}
		fisTextOut.close();
	}
	else {
		cout << "Fisierul comenziMagazin.txt nu a putut fi deschis pentru scriere.\n";
	}
}

void Client::stergereProdTotale(Produs** cos)
{

	if (cos != nullptr) {
		Produs** aux = nullptr;
		cos = aux;
		nrProdCos = 0;
	}
}

bool Client::operator==(Client& c)
{
	if (this == &c) {
		return true;
	}
	else {
		bool validare =
			this->numeClient == c.numeClient &&
			this->email == c.email &&
			this->adresa == c.adresa &&
			this->nrTelefon == c.nrTelefon;
		return validare;
	}
}

Produs* Client::getProdusCos(Client c, int index)
{
	for (int i = 0; i < nrProdCos; i++) {
		if (index == i) {
			return cos[i];
		}
	}
}

istream& operator>>(istream& in, Client& c)
{
	cout << "Nume client: ";
	getchar();
	getline(in, c.numeClient);
	cout << "Email: "; in >> c.email;
	cout << "Adresa: ";
	//in.ignore();
	getchar();
	getline(in, c.adresa);
	cout << "Numar de telefon: "; in >> c.nrTelefon;
	return in;
}

ostream& operator<<(ostream& out, Client& c)
{
	out << "Nume client: " << c.numeClient << endl;
	out << "Email client: " << c.email << endl;
	out << "Adresa client: " << c.adresa << endl;
	out << "Numar de telefon: " << c.nrTelefon << endl;
	return out;
}

ofstream& operator<<(ofstream& out, Client& c)
{
	out << "Id client: " << c.idClient << endl;
	out << "Nume client: " << c.numeClient << endl;
	out << "Email client: " << c.email << endl;
	out << "Adresa client: " << c.adresa << endl;
	out << "Nr telefon: " << c.nrTelefon << endl << endl;
	return out;
}

ifstream& operator>>(ifstream& in, Client& c)
{
	in >> c.idClient;
	in.ignore();
	getline(in, c.numeClient);
	getline(in, c.email);
	getline(in, c.adresa);
	getline(in, c.nrTelefon);

	return in;
}
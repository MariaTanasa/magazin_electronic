#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include"Produs.h";
#include"Magazin.h";

using namespace std;

class Client
{
private:
	string numeClient;
	string email;
	string adresa;
	string nrTelefon;
	int nrProdCos;
	Produs** cos;
public:
	static int idClient;

	Client();

	Client(string numeClient, string email, string adresa, string nrTelefon);

	Client(string numeClient, string email, string adresa, string nrTelefon, int nrProdCos, Produs** cos);

	Client(const Client& client);

	Client& operator=(const Client& client);

	~Client();

	string getNumeClient();

	void setNumeClient(string numeClient);

	string getEmail();

	void setEmail(string email);

	string getAdresa();

	void setAdresa(string adresa);

	string getNrTelefon();

	void setNrTelefon(string nrTelefon);

	int getNrProdCos();

	void setNrProdCos(int nrProdCos);

	Produs** getProduseCos();

	void setProduseCos(Produs** cos, int nrProdCos);

	void adaugaProduseInCos(Magazin m, int id);

	void stergeProduseDinCos(Produs* p, int idProdus);

	void afisare();

	Produs* cautareId(Produs** cos, int id);

	friend istream& operator>>(istream& in, Client& c);

	friend ostream& operator<<(ostream& out, Client& c);

	friend ofstream& operator<<(ofstream& out, Client& c);

	friend ifstream& operator>>(ifstream& in, Client& c);

	void scriereDateClientInBinar(ofstream& out);

	void citireDateClientDinBinar(ifstream& in);

	void adaugareComandaInBinar(Client& c, Produs** cos);

	void citireComandaDinBinarPeRand(Client& c);

	void citireComandaDinBinar(Client& c, list<int>listaNrComenzi);

	void adaugareComandaInText(Client& c, Produs** cos, int nrProdCos);

	void adaugareComenziTotaleInText(Client& c, Produs** cos, int nrProdCos);

	void stergereProdTotale(Produs** cos);

	bool operator==(Client& c);

	Produs* getProdusCos(Client c, int index);

};
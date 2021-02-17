#include<iostream>
#include<string>
#include <map>
#include <list>
#include<fstream>
#include "Produs.h"
#include "ProdusAlimentar.h"
#include "ProdusElectronic.h"
#include "ProdusVestimentar.h"
#include "Client.h"
#include "Magazin.h"
#include "ExceptiePret.h"
#include "ExceptieIdProdus.h"

using namespace std;

int Client::idClient = 1;

int main() {

	Magazin m;
	Client c;
	Produs p1;
	Produs* pp1;
	pp1 = &p1;
	ProdusAlimentar pa1;
	ProdusAlimentar* ppa1;
	ProdusElectronic pe1;
	ProdusElectronic* ppe1;
	ProdusVestimentar pv1;
	ProdusVestimentar* ppv1;

	map<int, Client> mapClienti;
	map<int, Client>::iterator itr;

	list<int>listaNrComenzi;
	list<int>::iterator itrLista;

	int exit1 = 1, exit2 = 1, exit3 = 1, exit4 = 1, alegere, categ, id, nrProd, nr, tipUtilizator = 0;
	int idLogare, nrComenzi = 0, ok = 0, ok2 = 0, aux;
	double modificare;

	while (exit1 != 0) {
		exit2 = 1;
		cout << "\n====================================\n";
		cout << "\n\tMAGAZIN ONLINE  \n";
		cout << "\n=====================================\n";
		cout << "\n\t  1. MAGAZIN";
		cout << "\n\t  2. CLIENT";
		cout << "\n\t  3. EXIT";
		cout << "\n\n Tastati in functie de ce doriti sa faceti: ";
		cin >> alegere;
		switch (alegere) {
		case 1: {
			while (exit2 != 0) {
				exit3 = 1;
				cout << "\n====================================\n";
				cout << "\n\t  1.  ADAUGA PRODUSE ";
				cout << "\n\t  2.  EDITEAZA PRODUSE";
				cout << "\n\t  3.  STERGE PRODUSE";
				cout << "\n\t  4.  PRELUCRARE COMENZI";
				cout << "\n\t  5.  REALIZARE RAPORT COMENZI";
				cout << "\n\t  6.  VIZUALIZEAZA STAREA MAGAZINULUI";
				cout << "\n\t  7.  EXIT";
				cout << "\n\n Tastati ce doriti sa faceti: ";
				cin >> alegere;
				switch (alegere) {
				case 1:
				{  	while (exit3 != 0) {
					cout << "\n\t Categoriile disponibile sunt: ";
					cout << "\n\t  1.  PROD. ALIMENTARE ";
					cout << "\n\t  2.  PROD. ELECTRONICE";
					cout << "\n\t  3.  PROD. VESTIMENTARE";
					cout << "\n\t  4.  EXIT";
					cout << "\n\t Alegeti categoria in care doriti sa adaugati: ";
					int categ;
					cin >> categ;
					switch (categ) {
					case 1: {
						ProdusAlimentar* ppa1 = new ProdusAlimentar();
						try {
							cin >> *ppa1;
						}
						catch (ExceptieIdProdus* e) {
							cout << e->what() << "\nEroarea nu e fatala.Programul poate continua.";//prima exceptie custom pe idProdus
						}
						catch (ExceptiePret* e) {
							cout << e->what() << "Eroarea nu e fatala.Programul poate continua.";//a doua exceptie custom pe pret
						}

						if (m[ppa1->getIdProdus()].getIdProdus() == ppa1->getIdProdus()) { //verificam daca id-ul introdus exista deja in magazin
							cout << "\nIntrodu alt id. Produsul cu acest id deja exista.";//folosind supraincarcarea operatorului index
							cout << "\nProdusul nu a fost adaugat in magazin!" << endl;

						}
						else {
							m.adaugareProduse(ppa1);
						}
						m.afisare();
						break;
					}
					case 2: {
						ProdusElectronic* ppe1 = new ProdusElectronic();
						try {
							cin >> *ppe1;
						}
						catch (ExceptieIdProdus* e) {
							cout << e->what() << "\nEroarea nu e fatala.Programul poate continua.";
						}
						catch (ExceptiePret* e) {
							cout << e->what() << "Eroarea nu e fatala.Programul poate continua.";
						}

						if (m[ppe1->getIdProdus()].getIdProdus() == ppe1->getIdProdus()) {
							cout << "\nIntrodu alt id. Produsul cu acest id deja exista.";
							cout << "\nProdusul nu a fost adaugat in magazin!" << endl;

						}
						else {
							m.adaugareProduse(ppe1);
						}
						m.afisare();
						break;
					}
					case 3: {
						ProdusVestimentar* ppv1 = new ProdusVestimentar;
						try {
							cin >> *ppv1;
						}
						catch (ExceptieIdProdus* e) {
							cout << e->what() << "\nEroarea nu e fatala.Programul poate continua.";
						}
						catch (ExceptiePret* e) {
							cout << e->what() << "Eroarea nu e fatala.Programul poate continua.";
						}
						if (m[ppv1->getIdProdus()].getIdProdus() == ppv1->getIdProdus()) {
							cout << "\nIntrodu alt id. Produsul cu acest id deja exista.";
							cout << "\nProdusul nu a fost adaugat in magazin!" << endl;

						}
						else {
							m.adaugareProduse(ppv1);
						}
						m.afisare();
						break;
					}
					case 4: {
						exit3 = 0;
						break;
					}
					}
				}
				break;
				}
				case 2: {
					while (exit3 != 0) {
						exit4 = 1;
						cout << "\n\t  1.  APLICATI REDUCERI PRODUSELOR ";
						cout << "\n\t  2.  CRESTETI PRETUL PRODUSELOR ";
						cout << "\n\t  3.  EDITATI PRODUSUL COMPLET ";
						cout << "\n\t  4.  EXIT ";
						cout << "\n\tAlegeti ce doriti sa faceti: ";
						cin >> alegere;
						switch (alegere) {
						case 1: {
							cout << "\nCate produse doriti sa modificati? ";
							cin >> nr;
							for (int i = 0; i < nr; i++) {
								cout << "\nIntroduceti id-ul produsului pe care doriti sa-l editati: ";
								cin >> id;
								cout << "\nIntroduceti procentajul reducerii aplicate acestuia: ";
								cin >> modificare;
								m.modificarePret(id, modificare); //editare folosind clasa de tip interfata
							}
							break;
						}
						case 2: {
							cout << "\nCate produse doriti sa modificati? ";
							cin >> nr;
							for (int i = 0; i < nr; i++) {
								cout << "\nIntroduceti id-ul produsului pe care doriti sa-l editati: ";
								cin >> id;
								cout << "\nIntroduceti pretul cu care mariti: ";
								cin >> modificare;
								m(modificare, id); //editare folosind supraincarcarea operatorului()
								m.afisare();
							}
							break;
						}
						case 3: {
							while (exit4 != 0) {
								cout << "\n\t  1.  PROD. ALIMENTARE ";
								cout << "\n\t  2.  PROD. ELECTRONICE";
								cout << "\n\t  3.  PROD. VESTIMENTARE";
								cout << "\n\t  4.  EXIT";
								cout << "\n\t Alegeti categoria in care doriti sa editati: ";
								cin >> categ;
								switch (categ) {
								case 1: {
									cout << "\nIntroduceti id-ul produsului pe care doriti sa-l editati: ";
									cin >> id;
									Produs* pid = m.cautareId(m.getProduse(), id);
									ProdusAlimentar* ppa1 = new ProdusAlimentar();
									try {
										cin >> *ppa1;
									}
									catch (ExceptieIdProdus* e) {
										cout << e->what() << "\nEroarea nu e fatala.Programul poate continua.";
									}
									catch (ExceptiePret* e) {
										cout << e->what() << "Eroarea nu e fatala.Programul poate continua.";
									}
									if (m[ppa1->getIdProdus()].getIdProdus() == ppa1->getIdProdus()) { //verificam daca id-ul introdus exista deja in magazin
										cout << "\nIntrodu alt id. Produsul cu acest id deja exista.";//folosind supraincarcarea operatorului index
										cout << "\nProdusul nu a fost adaugat in magazin!" << endl;
									}
									else {
										m.stergereProduse(pid, id);
										m.adaugareProduse(ppa1);
									}

									break;
								}
								case 2: {
									cout << "\nIntroduceti id-ul produsului pe care doriti sa-l editati: ";
									cin >> id;
									Produs* pid = m.cautareId(m.getProduse(), id);
									ProdusElectronic* ppe1 = new ProdusElectronic();
									try {
										cin >> *ppe1;
									}
									catch (ExceptieIdProdus* e) {
										cout << e->what() << "\nEroarea nu e fatala.Programul poate continua.";
									}
									catch (ExceptiePret* e) {
										cout << e->what() << "Eroarea nu e fatala.Programul poate continua.";
									}
									if (m[ppe1->getIdProdus()].getIdProdus() == ppe1->getIdProdus()) {
										cout << "\nIntrodu alt id. Produsul cu acest id deja exista.";
										cout << "\nProdusul nu a fost adaugat in magazin!" << endl;

									}
									else {
										m.stergereProduse(pid, id);
										m.adaugareProduse(ppe1);
									}
									break;
								}
								case 3: {
									cout << "\nIntroduceti id-ul produsului pe care doriti sa-l editati: ";
									cin >> id;
									Produs* pid = m.cautareId(m.getProduse(), id);
									ProdusVestimentar* ppv1 = new ProdusVestimentar();
									try {
										cin >> *ppv1;
									}
									catch (ExceptieIdProdus* e) {
										cout << e->what() << "\nEroarea nu e fatala.Programul poate continua.";
									}
									catch (ExceptiePret* e) {
										cout << e->what() << "Eroarea nu e fatala.Programul poate continua.";
									}
									if (m[ppv1->getIdProdus()].getIdProdus() == ppv1->getIdProdus()) {
										cout << "\nIntrodu alt id. Produsul cu acest id deja exista.";
										cout << "\nProdusul nu a fost adaugat in magazin!" << endl;

									}
									else {
										m.stergereProduse(pid, id);
										m.adaugareProduse(ppv1);
									}
									break;
								}
								case 4: {
									exit4 = 0;
									break;
								}
								}
							}
							break;
						}
						case 4: {
							exit3 = 0;
							break;
						}
						}
					}
					break;
				}
				case 3: {
					cout << "\nCate produse doriti sa stergeti? ";
					cin >> nrProd;
					for (int i = 0; i < nrProd; i++) {
						cout << "\nIntroduceti id-ul produsului pe care doriti sa-l stergeti: ";
						cin >> id;
						Produs* pid = m.cautareId(m.getProduse(), id);//caut in vectorul de produse dupa id produsul ce trebuie sters
						m.stergereProduse(pid, id);
					}
					m.afisare();
					break;
				}
				case 4: {
					if (nrComenzi > 0 && ok2) {
						cout << "\nPentru a vedea lista de comenzi prelucrate deschideti fisierul comenziMagazin.txt\n";
						cout << "\nProdusele au fost prelucrate!\n";
					}
					else {
						cout << "\nNu au fost trimise comenzi.";
					}
					break;

				}
				case 5: {
					if (nrComenzi > 0 && ok2) {
						cout << "\nRaportul comenzilor de pana acum se gaseste in fisierul comenziMagazin.txt.\nDeschideti fisierul pentru a vedea comenzile.\n";
					}
					else {
						cout << "\nMagazinul inca nu are comenzi.\n";
					}

					break;
				}
				case 6: {
					m.afisare();
					/*m.citireProduseDinBinar();*/
					break;
				}
				case 7: {
					m.adaugareProduseInBinar(m.getProduse());
					exit2 = 0;
					break;
				}

				}
			}
			break;
		}
		case 2: {
			if (Client::idClient == 1) {
				cout << "\n\tBINE ATI VENIT!\n";
			}
			else {
				cout << "\n\t  1.  UTILIZATOR EXISTENT";
				cout << "\n\t  2.  UTILIZATOR NOU";
				cout << "\n\tALEGETI TIPUL DE UTILIZATOR: ";
				cin >> tipUtilizator;
				if (tipUtilizator == 1) {
					cout << "\nIntroduceti id-ul care vi s-a dat la prima logare pentru a localiza datele dumneavoastra: ";
					cin >> idLogare;
				}
			}
			while (exit2 != 0) {
				exit3 = 1;
				cout << "\n====================================\n";
				cout << "\n\t  1.  VIZUALIZEAZA PRODUSELE DIN MAGAZIN ";
				cout << "\n\t  2.  SELECTEAZA SI INTRODU PRODUSELE IN COS";
				cout << "\n\t  3.  STERGE PRODUSE DIN COS";
				cout << "\n\t  4.  COMPLETEAZA DATE PERSONALE";
				cout << "\n\t  5.  TRIMITE COMANDA";
				cout << "\n\t  6.  RAPORT PRIVIND COMANDA";
				cout << "\n\t  7.  EXIT";
				cout << "\n\n Tastati ce doriti sa faceti: ";
				cin >> alegere;
				switch (alegere) {
				case 1: {
					if (m.getNrProduse() > 0) {
						m.afisare();
					}
					else {
						cout << "\nMagazinul nu are produse disponibile.\n";
					}
					break;
				}
				case 2: {
					if (m.getNrProduse() > 0) {
						c.afisare();
						cout << "\nCate produse doriti sa introduceti in cos? ";
						cin >> nrProd;

						if (nrProd > m.getNrProduse()) { //in cazul in care clientul introduce un nr mai mare de produse decat cele existenta in magazin
							aux = m.getNrProduse();		//adaugam in cos toate produsele din magazin
							cout << "\nIn magazin sunt doar " << m.getNrProduse() << " produse.";
						}
						else {
							aux = nrProd;
						}
						while (aux) {
							cout << "\nIntroduceti id-ul produsului pe care doriti sa-l adaugati(un id se introduce o singura data): ";
							cin >> id;
							c.adaugaProduseInCos(m, id);
							aux--;
						}
						c.afisare();
					}
					else {
						cout << "\nMagazinul nu are produse disponibile.\n";
					}

					break;
				}
				case 3: {
					cout << "\nCate produse doriti sa stergeti din cos? "; //in cazul in care clientul introduce un nr mai mare de produse decat cele existenta in cos
					cin >> nrProd;										  //ii stergem toate produsele din cos
					if (nrProd > c.getNrProdCos()) {
						aux = c.getNrProdCos();
						cout << "\nIn cos sunt doar " << c.getNrProdCos() << " produse.";
					}
					else {
						aux = nrProd;
					}
					while (aux) {
						cout << "\nIntroduceti id-ul produsului pe care doriti sa-l stergeti (un id se introduce o singura data): ";
						cin >> id;
						Produs* pid = c.cautareId(c.getProduseCos(), id);
						c.stergeProduseDinCos(pid, id);
						aux--;
					}
					c.afisare();
					break;
				}
				case 4: {
					if (tipUtilizator == 1) { //daca utilizatorul s-a relogat luam datele introduse la prima logare in map 
						cout << "\nDatele dumneavoastra au fost retinute la prima logare.";
						cout << "\nDatele dumneavoastra sunt:\n";
						for (itr = mapClienti.begin(); itr != mapClienti.end(); itr++) {
							if (idLogare == itr->first) {
								cout << itr->second;
							}
						}
					}
					else { //daca este client nou trebuie sa introduca datele pentru a putea da comanda

						cout << "\nIntroduceti urmatoarele date despre dumneavoastra:" << endl;
						cin >> c;
						if (Client::idClient == 1) { //introducem datele primului client in map
							mapClienti.insert(pair<int, Client>(Client::idClient, c));
							cout << "\nId-ul dumneavoastra este: " << Client::idClient;
							cout << "\nRetineti id-ul!. Veti avea nevoie de el cand doriti sa va relogati.";
							Client::idClient++;

						}
						else {//pentru urmatorii clienti noi verificam daca exista deja datele stocate in map
							int bec = 0;
							while (bec == 0) {
								bec = 1;
								for (itr = mapClienti.begin(); itr != mapClienti.end(); itr++) {
									if (c == itr->second) { //folosim supraincarcarea operatorului == din Client
										cout << "\nAceste date exista deja in magazin!\n";
										bec = 0;
									}
								}
								if (bec == 0) {
									cin >> c;
								}
							}
							mapClienti.insert(pair<int, Client>(Client::idClient, c));
							cout << "\nId-ul dumneavoastra este: " << Client::idClient;
							cout << "\nRetineti id-ul!. Veti avea nevoie de el cand doriti sa va relogati.\n";
							Client::idClient++;
						}
					}
					break;
				}
				case 5: {
					if (c.getNumeClient().length() >= 2) { //verificam daca a introdus o lungime valida de nume
						//bifurcam in functie de tipul de client (nou, vechi)
						if (tipUtilizator == 1) { //daca avem client vechi luam datele corespunzatoare din map si le introducem in fisierele txt si binare
							if (c.getProduseCos() != nullptr && c.getNrProdCos() > 0) { //daca este gol cosul nu poate trimite comanda
								for (itr = mapClienti.begin(); itr != mapClienti.end(); itr++) {
									if (idLogare == itr->first) {
										Client::idClient--;
										c.adaugareComandaInText(itr->second, c.getProduseCos(), c.getNrProdCos());
										c.adaugareComenziTotaleInText(itr->second, c.getProduseCos(), c.getNrProdCos());
										c.adaugareComandaInBinar(itr->second, c.getProduseCos());
										Client::idClient++;
										nrComenzi++;
										ok = 1;
										ok2 = 1;

										listaNrComenzi.push_back(c.getNrProdCos());//pun in lista nr de produse comandate de fiecare client

										c.stergereProdTotale(c.getProduseCos());//golim cosul
									}
								}
							}
							else {
								cout << "\nCosul dumneavoastra este gol!\nIntroduceti intai produse in cos.\n";
							}
						}
						else {
							if (c.getProduseCos() != nullptr && c.getNrProdCos() > 0) { //daca este gol cosul nu poate trimite comanda
								c.adaugareComandaInBinar(c, c.getProduseCos());
								nrComenzi++;
								ok = 1;
								ok2 = 1;
								Client::idClient--;
								c.adaugareComandaInText(c, c.getProduseCos(), c.getNrProdCos());
								c.adaugareComenziTotaleInText(c, c.getProduseCos(), c.getNrProdCos());
								Client::idClient++;

								listaNrComenzi.push_back(c.getNrProdCos());//pun in lista nr de produse comandate de fiecare client

								c.stergereProdTotale(c.getProduseCos()); //golesc cosul dupa ce se trimite comanda
							}
							else {
								cout << "\nCosul dumneavoastra este gol!\nIntroduceti intai produse in cos.\n";
							}
						}
					}
					else { //clientul trebuie sa-si introduca datele pentru a trimite comanda
						cout << "\nNu ati introdus datele despre dumneavoastra.\nInainte de a finaliza comanda trebuie sa va introduceti datele.";
					}

					break;
				}
				case 6: {
					if (nrComenzi > 0 && ok) { //verificam daca utilizatorul curent a trimis o comanda sau doar si-a introdus datele
						cout << "\nRaportul comenzii date de dumneavoastra se gaseste in fisierul comanda.txt.\nDeschideti fisierul pentru a vedea detaliile comenzii.\n";

					}
					else {
						cout << "\nNu ati trimis o comanda.\n";
					}
					break;

				}
				case 7: {
					c.stergereProdTotale(c.getProduseCos()); //la delogare cosul se sterge indiferent de tipul de client
					ok = 0;
					exit2 = 0;
					break;
				}
				}
			}
			break;
		}
		case 3: {
			exit1 = 0;
			break;
		}

		}
	}

}

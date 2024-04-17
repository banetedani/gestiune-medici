#include <iostream>
#include"Spital.h"
#include"Doctor.h"
using namespace std;

int main()
{
	Spital spital;
	spital.citesteDinFisier("doctori.csv");

	int optiune;
	do {
		cout << "\nMeniu:\n1.Afiseaza doctorii dupa specializare\n2.Cauta doctori\n3.Adauga doctor\n4.Sterge doctor\n5.Iesire din program\nIntroduceti una din optiuni: ";
		cin >> optiune;

		switch (optiune) {
		case 1: {
			string specializare;
			cout << "Introduceti specializarea: ";
			cin >> specializare;
			spital.afisareDoctoriPeSpecializare(specializare);
			break;
		}
		case 2: {
			string cuvant;
			cout << "Introduceti numele :";
			cin >> cuvant;
			spital.cautaDoctori(cuvant);
			break;
		}
		case 3: {
			Doctor doctorNou;
			cout << "Introduceti numele, prenumele, specializarea,experienta (ani si luni): ";
			cin >> doctorNou.nume >> doctorNou.prenume >> doctorNou.specializare >> doctorNou.aniExperienta >> doctorNou.luniExperienta;
			spital.adaugaDoctor(doctorNou);
			spital.updateFisier("doctori.csv");
			cout << "Doctor adaugat cu succes." << endl;
			break;
		}
		case 4: {
			string nume, prenume;
			cout << "Introduceti numele si prenumele doctorului pe care doriti sa il stergeti: " << endl;
			cin >> nume >> prenume;
			spital.stergereDoctor(nume, prenume);
			spital.updateFisier("doctori.csv");
			cout << "Doctrorul a fost sters cu succes." << endl;
			break;
		}
		case 5: {
			cout << "Iesire din program ." << endl;
			break;
		default:
			cout << "Alegere invalida. Alegeti din nou." << endl;
		}
		}
	} while (optiune != 5);
	return 0;

}

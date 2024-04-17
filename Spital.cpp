#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include <sstream>
#include"Doctor.h"
#include"Spital.h"

using namespace std;

void Spital::citesteDinFisier(string numeFisier) {
    ifstream fisier(numeFisier);
    if (!fisier.is_open()) {
        cout << "Eroare la incercarea de a deschide fisierul." << endl;
        return;
    }

    doctori.clear();
    Doctor doc;
    string linie;
    while (getline(fisier, linie)) {
        istringstream iss(linie);
        getline(iss, doc.nume, ',');
        getline(iss, doc.prenume, ',');
        getline(iss, doc.specializare, ',');
        iss >> doc.aniExperienta;
        iss.ignore();
        iss >> doc.luniExperienta;
        iss.ignore();

        doctori.push_back(doc);
    }
    fisier.close();
}

void Spital::afisareDoctoriPeSpecializare( string specializare) {
    vector<Doctor> filtrareDoctori;
    for ( auto doc : doctori) {
        if (doc.specializare == specializare) {
            filtrareDoctori.push_back(doc);
        }
    }

    sort(filtrareDoctori.begin(), filtrareDoctori.end(), []( Doctor a,  Doctor b) {
        if (a.aniExperienta != b.aniExperienta)
            return a.aniExperienta > b.aniExperienta;
        return a.luniExperienta > b.luniExperienta;
        });

    cout << "Doctori cu specializarea " << specializare << ":" << endl;
    for ( auto doc : filtrareDoctori) {
        doc.afiseaza();
    }
}

void Spital::cautaDoctori( string cuvant) {
    cout << "Rezultatele cautarii pentru cuvantul '" << cuvant << "':" << endl;
    for ( auto doc : doctori) {
        if (doc.nume.find(cuvant) != string::npos ||
            doc.prenume.find(cuvant) != string::npos ||
            doc.specializare.find(cuvant) != string::npos) {
            doc.afiseaza();
        }
    }
}

void Spital::adaugaDoctor( Doctor doctorAdaugat) {
    doctori.push_back(doctorAdaugat);
}

void Spital::stergereDoctor(  string nume,   string prenume) {
    doctori.erase(remove_if(doctori.begin(), doctori.end(), [&]( Doctor doc) {
        return doc.nume == nume && doc.prenume == prenume ;
        }), doctori.end());
}

void Spital::updateFisier( string numefolder) {
    ofstream folder(numefolder);
    if (!folder.is_open()) {
        cout << "Eroare la incercarea de a deschide folderul pentru scriere!" << endl;
        return;
    }

    for ( auto doc : doctori) {
        folder << doc.nume << " , " << doc.prenume << " , " << doc.specializare << " , " << doc.aniExperienta << " , " << doc.luniExperienta << endl;
    }
    folder.close();
}
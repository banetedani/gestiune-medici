#pragma once
#include<vector>
#include<string>
#include"Doctor.h"
using namespace std;

class Spital {
	private:
		vector<Doctor> doctori;
    public:
        void citesteDinFisier( string numeFisier);
        void afisareDoctoriPeSpecializare( string specializare);
        void cautaDoctori( string cuvant);
        void adaugaDoctor( Doctor doctorAdaugat);
        void stergereDoctor( string nume,  string prenume);
        void updateFisier( string numefolder);
};
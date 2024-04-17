#pragma once
#include <string>
using namespace std;

class Doctor {
public:
    string nume;
    string prenume;
    string specializare;
    int aniExperienta;
    int luniExperienta;
	void afiseaza();
};
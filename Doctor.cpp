#include<iostream>
#include<string>
#include"Doctor.h"
using namespace std;

    void Doctor::afiseaza() {
        cout << "Dr. " << nume << " " << prenume << ", " << specializare << ", Experienta "
            << aniExperienta << " ani si " << luniExperienta << "luni" << endl;
    }
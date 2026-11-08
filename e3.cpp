/*
 * e3.cpp
 *
 *  Created on: 8 nov. 2026
 *      Author: hP
 */


#include <iostream>
#include <stdexcept>
using namespace std;

class Tableau {
private:
    int* data;
    int taille;

public:
    // Constructeur : alloue et initialise à 0
    Tableau(int taille) : taille(taille) {
        if (taille <= 0)
            throw invalid_argument("La taille doit etre strictement positive");
        data = new int[taille]();
    }

    // Constructeur de copie (copie profonde)
    Tableau(const Tableau& autre) : taille(autre.taille) {
        data = new int[taille];
        for (int i = 0; i < taille; i++)
            data[i] = autre.data[i];
    }

    // Opérateur d'affectation (copie profonde)
    Tableau& operator=(const Tableau& autre) {
        if (this != &autre) {
            delete[] data;
            taille = autre.taille;
            data = new int[taille];
            for (int i = 0; i < taille; i++)
                data[i] = autre.data[i];
        }
        return *this;
    }

    // Destructeur
    ~Tableau() {
        delete[] data;
    }

    // Version modifiable (lecture/écriture)
    int& operator[](int index) {
        if (index < 0 || index >= taille)
            throw out_of_range("Index hors limites : " + to_string(index));
        return data[index];
    }

    // Version const (lecture seule)
    const int& operator[](int index) const {
        if (index < 0 || index >= taille)
            throw out_of_range("Index hors limites : " + to_string(index));
        return data[index];
    }

    int getTaille() const { return taille; }
};

int main() {
    Tableau t(5);

    for (int i = 0; i < t.getTaille(); i++)
        t[i] = (i + 1) * 10;

    for (int i = 0; i < t.getTaille(); i++)
        cout << "t[" << i << "] = " << t[i] << endl;

    try {
        cout << t[10] << endl;   // index invalide
    }
    catch (const out_of_range& e) {
        cout << "Erreur : " << e.what() << endl;
    }
    return 0;
}


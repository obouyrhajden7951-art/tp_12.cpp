/*
 * e.cpp
 *
 *  Created on: 8 nov. 2026
 *      Author: hP
 */


#include <iostream>
using namespace std;

class Date {
private:
    int jour, mois, annee;

public:
    // Constructeur par défaut
    Date() : jour(1), mois(1), annee(1970) {}

    // Constructeur paramétré
    Date(int j, int m, int a) : jour(j), mois(m), annee(a) {}

    // Constructeur de copie
    Date(const Date& d) : jour(d.jour), mois(d.mois), annee(d.annee) {}

    bool operator==(const Date& autre) const {
        return jour == autre.jour && mois == autre.mois && annee == autre.annee;
    }

    bool operator!=(const Date& autre) const {
        return !(*this == autre);   // réutilise ==
    }

    void afficher() const {
        cout << jour << "/" << mois << "/" << annee;
    }
};

int main() {
    Date d1(8, 11, 2026);
    Date d2(8, 11, 2026);
    Date d3(25, 12, 2026);

    cout << "d1 == d2 : " << (d1 == d2 ? "vrai" : "faux") << endl;  // vrai
    cout << "d1 == d3 : " << (d1 == d3 ? "vrai" : "faux") << endl;  // faux
    cout << "d1 != d3 : " << (d1 != d3 ? "vrai" : "faux") << endl;  // vrai
    cout << "d1 != d2 : " << (d1 != d2 ? "vrai" : "faux") << endl;  // faux
    return 0;
}


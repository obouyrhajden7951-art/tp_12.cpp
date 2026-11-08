/*
 * e1.cpp
 *
 *  Created on: 8 nov. 2026
 *      Author: hP
 */


#include <iostream>
using namespace std;

class Vecteur2D {
private:
    double x, y;

public:
    Vecteur2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Retourne un nouveau vecteur : la somme de *this et autre
    Vecteur2D operator+(const Vecteur2D& autre) const {
        return Vecteur2D(x + autre.x, y + autre.y);
    }

    void afficher() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Vecteur2D v1(1.5, 2.0);
    Vecteur2D v2(3.0, 4.5);
    Vecteur2D v3 = v1 + v2;

    cout << "v1 = "; v1.afficher();
    cout << "v2 = "; v2.afficher();
    cout << "v1 + v2 = "; v3.afficher();   // (4.5, 6.5)
    return 0;
}


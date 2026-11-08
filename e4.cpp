#include <iostream>
#include <string>
using namespace std;

class Produit {
private:
    string nom;
    double prix;
    int quantite;

public:
    Produit(const string& nom, double prix, int quantite)
        : nom(nom), prix(prix), quantite(quantite) {}

    // Fonction amie : accès aux attributs privés
    friend ostream& operator<<(ostream& os, const Produit& p);
};

ostream& operator<<(ostream& os, const Produit& p) {
    os << "Produit : " << p.nom
       << " | Prix : " << p.prix << " DH"
       << " | Quantite : " << p.quantite;
    return os;   // permet le chaînage : cout << p1 << p2
}

int main() {
    Produit p1("Clavier", 199.99, 15);
    Produit p2("Souris", 89.50, 30);

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p1 << "\n" << p2 << endl;   // chaînage
    return 0;
}

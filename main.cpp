#include <iostream>
#include "Entreprise.hpp"

using namespace std;

void testentreprise()
{
    EntrepriseProduitFinis Ikea{"ikea", 2};
    Ikea.ajouterProduits(3,3,3,3);
    Ikea.ajouterProduits(8,6,2,4);
    cout << "entrepriseOK" << endl;
}


int main()
{
    testentreprise();
    return 0;
}

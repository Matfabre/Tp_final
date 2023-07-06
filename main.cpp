#include <iostream>

#include "produit.hpp"
#include "Market.hpp"

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

    struct Produit p1;
    struct Produit p2;
    struct Produit p3;

    Market::constructeurMarket();

    Market::getInstance()->ajouterProduit(&p1);
    Market::getInstance()->ajouterProduit(&p2);
    Market::getInstance()->ajouterProduit(&p3);

    delete Market::getInstance();

    testentreprise();
    return 0;
}

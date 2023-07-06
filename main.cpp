#include <iostream>

#include "produit.hpp"
#include "Market.hpp"
#include "Entreprise.hpp"

using namespace std;

void testentreprise()
{
    Produit p1;
    Produit *ptrProduit = &p1;

    EntrepriseProduitFinis Ikea{"ikea", 2};
    Ikea.creerProduits(3,3,3,3, ptrProduit);
    Ikea.creerProduits(8,6,2,4, ptrProduit);
    Ikea.afficherEtat();
    Ikea.vendreProduits(3, 20);
    Ikea.afficherEtat();
}

void testmarket()
{
    struct Produit p1;
    struct Produit p2;
    struct Produit p3;

    Market::constructeurMarket();

    Market::getInstance()->ajouterProduitFini(&p1);
    Market::getInstance()->ajouterProduitFini(&p2);
    Market::getInstance()->ajouterProduitFini(&p3);

    delete Market::getInstance();

}
int main()
{
    testmarket();
    testentreprise();
    return 0;
}

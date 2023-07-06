#include <iostream>

#include "produit.hpp"
#include "Market.hpp"
#include "Entreprise.hpp"
#include "Automate.hpp"

using namespace std;

void testentreprise()
{
    Produit p1;
    Produit *ptrProduit = &p1;

    EntrepriseProduitFinis Ikea{"ikea", 2, 2000};
    Ikea.creerProduits(3,3,3,3, ptrProduit);
    Ikea.creerProduits(8,6,2,4, ptrProduit);

    Market::getInstance()->ajouterProduitFini(&p1);
    Ikea.acheterProduits(0);
    Ikea.afficherEtat();
    Ikea.vendreProduits(1, 20);
    Ikea.afficherEtat();
}

void testmarket()
{

    Produit p1;
    Produit p2;
    Produit p3;

    Market::getInstance()->ajouterProduitFini(&p1);
    Market::getInstance()->ajouterProduitFini(&p2);
    Market::getInstance()->ajouterProduitFini(&p3);

}
int main()
{
    testmarket();
    testentreprise();

    Automate* m=Automate::getInstance();

    m->initialClient();
    m->initialEntreprise();
    return 0;
}

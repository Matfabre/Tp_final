#include <iostream>

#include "produit.hpp"
#include "Market.hpp"
#include "Entreprise.hpp"
#include "Automate.hpp"

int N_TOURS = 100;
int N_PRODUITS_FINIS = 3;
int N_MATIERES_PREMIERES = 3;


void testentreprise()
{
    Produit p1;
    Produit *ptrProduit = &p1;

    EntrepriseProduitFinis Ikea{"ikea", 2};
    Ikea.creerProduits(3,3,3,3, ptrProduit);
    Ikea.creerProduits(8,6,2,4, ptrProduit);
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

    Automate* m = Automate::getInstance();

    m->initialClient(N_PRODUITS_FINIS);
    m->initialEntreprise();

    m->play(N_TOURS);

    m->gestionMemoire();

    return 0;
}

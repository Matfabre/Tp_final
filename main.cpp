#include <iostream>

#include "produit.hpp"
#include "Market.hpp"
#include "Entreprise.hpp"
#include "Automate.hpp"

int N_TOURS = 100;
int N_PRODUITS_FINIS = 3;
int N_MATIERES_PREMIERES = 3;



int main()
{


    Automate* m = Automate::getInstance();

    m->initialClient(N_PRODUITS_FINIS);
    m->initialEntreprise();
    m->initialProduit();

    m->play(N_TOURS);

    m->gestionMemoire();

    return 0;
}

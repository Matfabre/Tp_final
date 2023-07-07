//authors : Mathias, Pierre-Antoine, Belmont
#include <iostream>

#include "produit.hpp"
#include "Market.hpp"
#include "Entreprise.hpp"
#include "Automate.hpp"

int N_TOURS = 10;
int N_PRODUITS_FINIS = 3;
int N_MATIERES_PREMIERES = 3;



int main()  //programme principal
{


    Automate* m = Automate::getInstance();  //appel au singleton

    m->initialClient(N_PRODUITS_FINIS);  //initialisation des clients
    m->initialEntreprise();  //initalisation des entreprises
    m->initialProduit();

    CompteRendu compterendu;
    compterendu.afficheCR(m);  //affiche la situation initiale

    m->play(N_TOURS);  //joue le nombre de tour demandé

    m->gestionMemoire();  //supprime tous les objets

    return 0;
}

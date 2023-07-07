#include "Automate.hpp"
#include "CompteRendu.hpp"
#include <iostream>

void CompteRendu::afficheCR(Automate* m)
{
    std::cout << "Voici les resultats du mois" << std::endl;
    std::vector<EntrepriseProduitFinis*> *entreprises = m->getEntreprisesProduitFinis();
    std::cout << "Taille du vecteur EntrepriseProduitFinis : "<<entreprises->size()<<std::endl;
    for(unsigned int i = 0; i < entreprises->size(); i++)
    {

        entreprises->at(i)-> afficherEtat();
    }
}

CompteRendu::~CompteRendu()
{

}

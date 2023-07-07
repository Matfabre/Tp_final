#include "CompteRendu.hpp"
#include <iostream>

void CompteRendu::afficheCR(Automate * m)
{
    std::cout << "Voici les resultats du mois" << std::endl;
    std::vector<EntrepriseProduitFinis*> entreprisesPF = m->getEntreprisesProduitFinis();
    for(unsigned int i = 0; i < entreprisesPF.size(); i++)
    {
        entreprisesPF.at(i)-> afficherEtat();
    }
    std::vector<EntrepriseMatierePremiere*> entreprisesMP = m->getEntreprisesMatierePremiere();
    for(unsigned int i = 0; i < entreprisesMP.size(); i++)
    {
        entreprisesMP.at(i)-> afficherEtat();
    }
}

CompteRendu::~CompteRendu()
{

}

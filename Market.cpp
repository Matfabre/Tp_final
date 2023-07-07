//CLAIRE Belmont
#include <iostream>
#include "produit.hpp"
#include "Market.hpp"
#include "Automate.hpp"

// methode pour avoir l'instance
Market *Market::getInstance()
{
    if(nombreInstances == 0)
    {
        instance = new Market();
        nombreInstances++;
    }
    return instance;
}

// methode pour ajouter un produit
void Market::ajouterProduitFini(Produit* produit)
{
    produitsFinis.push_back(produit);
}

// Destucteur de Market
Market::~Market()
{
    nombreInstances --;
    std::cout << "destructeur de Market" << std::endl;
}

// Constructeur de Market
Market::Market()
{
    std::cout << "constructeur de Market" << std::endl;
}

std::vector<Produit*> Market::getProduitsFinis()
{
    return produitsFinis;
}

std::vector<Produit*> Market::getMatieresPremieres()
{
    return matieresPremieres;
}

void Market::transaction(Produit* produit, int quantiteAchete)
{
    (produit->quantite) -= quantiteAchete;
    std::vector<EntrepriseProduitFinis*> marchandsProduitsFinis =*( Automate::getInstance()->getEntreprisesProduitFinis());
    std::vector<EntrepriseMatierePremiere*> marchandsMatierePremiere = Automate::getInstance()->getEntreprisesMatierePremiere();

    for(Entreprise* marchand : marchandsProduitsFinis)
    {

        if(marchand->getIdEntreprise() == produit->idEntreprise)
        {
            marchand->recois(produit->prix * quantiteAchete);
            break;
        }
    }
    for(Entreprise* marchand : marchandsMatierePremiere)
    {

        if(marchand->getIdEntreprise() == produit->idEntreprise)
        {
            marchand->recois(produit->prix * quantiteAchete);
            break;
        }
    }

}

int Market::nombreInstances = 0;




Market *Market::instance = NULL;

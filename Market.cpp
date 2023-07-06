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
    std::vector<Entreprise*> marchands = Automate::getInstance()->getEntreprises();
    for(Entreprise* marchand : marchands)
    {

        if(marchand->getIdEntreprise() == produit->idEntreprise)
        {
            marchand->recois(produit->prix * quantiteAchete);
        }
    }
}

int Market::nombreInstances = 0;




Market *Market::instance = NULL;

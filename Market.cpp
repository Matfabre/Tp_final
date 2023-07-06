//CLAIRE Belmont
#include <iostream>
#include "produit.hpp"
#include "market.hpp"
#include "Automate.hpp"

// constructeur de l'instance sous forme de singleton
void Market::constructeurMarket()
{
    if(nombreInstances == 0)
    {
        nombreInstances ++;
        instance = new Market();
    }
}

// methode pour avoir l'instance
Market *Market::getInstance()
{
    if(nombreInstances == 1)
    {
        return instance;
    }
    return NULL;
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
        /* TODO!!!!
        if(marchand->idEntreprise == produit->idEntreprise)
        {
            marchand->paye(produit->prix * quantiteAchete);
        }*/
    }
}

int Market::nombreInstances = 0;




Market *Market::instance = NULL;

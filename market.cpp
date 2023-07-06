//CLAIRE Belmont
#include <iostream>
#include "produit.hpp"
#include "market.hpp"


void Market::constructeurMarket()
{
    if(nombreInstances == 0)
    {
        nombreInstances ++;
        instance = new Market();
    }
}

Market *Market::getInstance()
{
    if(nombreInstances == 1)
    {
        return instance;
    }
    return NULL;
}

void Market::ajouterProduit(Produit *produit)
{
    Produits.push_back(produit);
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

int Market::nombreInstances = 0;
Market *Market::instance = NULL;

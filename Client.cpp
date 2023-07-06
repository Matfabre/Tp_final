#include "Market.hpp"
#include "Client.hpp"
#include "produit.hpp"
#include <iostream>
#include <vector>


Client::Client(float _salaire, float _argent)
{
    salaire = _salaire;
    argent = _argent;
}
Client::Client(float _argent)
{
    argent = _argent;
}
Produit* Client::selectProduit(std::vector<Produit*> produits)
{
    float bestVA = 0;
    Produit* produitChoisi = nullptr;

    for(Produit* produit : produits)
    {
        float va = produit->qualite / produit->prix;
        if(va > bestVA && argent > produit->prix)
        {
            bestVA = va;
            produitChoisi = produit;
        }
    }
    return produitChoisi;
}


void Client::shop(int produitRechercheId)
{
    Market* market = Market::getInstance();
    std::vector<Produit*> produitsCorrespondants;

    for(Produit* produit : market->getProduitsFinis())
    {
        if(produit->idProduit == produitRechercheId && produit->quantite != 0)
        {
            produitsCorrespondants.push_back(produit);
        }
    }
    if(produitsCorrespondants.size() == 0)
    {
        return;
    }
    if(produitsCorrespondants.size() == 1)
    {
        market->transaction(produitsCorrespondants[0], 1);
        argent -= produitsCorrespondants[0]->prix;
    }
    else
    {
        Produit* produitChoisi = selectProduit(produitsCorrespondants);
        if(produitChoisi != nullptr)
        {
            market->transaction(produitChoisi, 1);
            argent -= produitChoisi->prix;
        }

    }

}



void Client::gagneSalaire() {
    argent += salaire;
}

Client::~Client()
{

}

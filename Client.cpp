#include "Market.hpp"
#include "Client.hpp"
#include "produit.hpp"
#include <iostream>
#include <vector>
#include <random>

float sumVector(const std::vector<float>& vec) {
    float sum = 0.0f;
    for (float num : vec) {
        sum += num;
    }
    return sum;
}


Client::Client(float _salaire, float _argent, int _produitRechercheId)
{
    salaire = _salaire;
    argent = _argent;
    produitRechercheId = _produitRechercheId;

}
Client::Client(float _argent)
{
    argent = _argent;
}
Produit* Client::selectProduit(std::vector<Produit*> produits)
{
    float bestVA = 0;
    Produit* produitChoisi = nullptr;
    std::vector<float> poids;

    std::random_device rd;
    std::mt19937 gen(rd());

    for(Produit* produit : produits)
    {
        float va = produit->qualite / produit->prix;
        poids.push_back(va*va);
        if(va > bestVA && argent > produit->prix)
        {
            bestVA = va;
            produitChoisi = produit;
        }
    }
    float totalPoids = sumVector(poids);
    std::uniform_real_distribution<> dist(0.0f, totalPoids);

    float randomPoids = dist(gen);


    float sommePoidsActuelle = 0.0f;


    for(int i = 0; i < poids.size(); i++)
    {
        sommePoidsActuelle += poids[i];
        if(randomPoids < sommePoidsActuelle)
        {
            return produits[i];
        }
    }
    return produitChoisi;
}


void Client::shop(int produitRechercheId)
{
    Market* market = Market::getInstance();
    std::vector<Produit*> produitsCorrespondants;
    //std::cout << market->getProduitsFinis().size() << std::endl;
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

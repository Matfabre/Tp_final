//authors : Pierre-Antoine
#include "Market.hpp"
#include "Client.hpp"
#include "produit.hpp"
#include <iostream>
#include <vector>
#include <random>

float sumVector(const std::vector<float>& vec) {  //fait la somme d'un vecteur
    float sum = 0.0f;
    for (float num : vec) {
        sum += num;
    }
    return sum;
}


Client::Client(float _salaire, float _argent, int _produitRechercheId)  //constructeur
{
    salaire = _salaire;
    argent = _argent;
    produitRechercheId = _produitRechercheId;

}
Client::Client(float _argent)
{
    argent = _argent;
}
Produit* Client::selectProduit(std::vector<Produit*> produits)  //méthode pour que le clients sélectionne un bon produit
{
    float bestVA = 0;
    Produit* produitChoisi = nullptr;
    std::vector<float> poids;

    std::random_device rd;
    std::mt19937 gen(rd());

    for(Produit* produit : produits)
    {
        float va = produit->qualite / produit->prix;  //va : valeur ajouté = rapport qualite/prix
        poids.push_back(va*va);                      //les poids sont la proba que le client choisissent un article, le degré 2 est pour amplifier l'importance de va
        if(va > bestVA && argent > produit->prix)
        {
            bestVA = va;
            produitChoisi = produit;
        }
    }
    float totalPoids = sumVector(poids);
    std::uniform_real_distribution<> dist(0.0f, totalPoids);

    float randomPoids = dist(gen);   //valeur aléatoire entre 0 et poids total


    float sommePoidsActuelle = 0.0f;


    for(int i = 0; i < poids.size(); i++)
    {
        sommePoidsActuelle += poids[i];
        if(randomPoids < sommePoidsActuelle)
        {
            return produits[i];
        }
    }
    return produitChoisi;  //récupération du produit selon valeur séléctionnée
}


void Client::shop(int produitRechercheId)  //méthode d'achat du client
{
    Market* market = Market::getInstance();
    std::vector<Produit*> produitsCorrespondants;
    //std::cout << market->getProduitsFinis().size() << std::endl;
    for(Produit* produit : market->getProduitsFinis())
    {
        if(produit->idProduit == produitRechercheId && produit->quantite != 0)
        {
            produitsCorrespondants.push_back(produit);   //les produits correspondants sont ceux dont l'id est égal à celui recherché par le client
        }
    }
    if(produitsCorrespondants.size() == 0)
    {
        return;  //pas de produit trouvé
    }
    if(produitsCorrespondants.size() == 1)
    {
        market->transaction(produitsCorrespondants[0], 1);  //un seul produit, pas de choix, la transaction va transférer l'argent au marchand

        argent -= produitsCorrespondants[0]->prix;  // le client est débité
    }
    else
    {
        Produit* produitChoisi = selectProduit(produitsCorrespondants);  //utilisation de la méthode pour faire un choix
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

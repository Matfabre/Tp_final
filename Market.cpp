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
    for(int i = 0; i < produitsFinis.size(); i++)
    {
        if(produit->idProduit == produitsFinis[i]->idProduit && produit->idEntreprise == produitsFinis[i]->idEntreprise)
        {
            produitsFinis[i]->quantite += produit->quantite;
            delete produit;
            return;
        }
    }
    produitsFinis.push_back(produit);
}

void Market::ajouterMatierePremiere(Produit* produit)
{
    std::cout << matieresPremieres.size()<<std::endl;
    for(int i = 0; i < matieresPremieres.size(); i++)
    {
        if((produit->idProduit == matieresPremieres[i]->idProduit) && (produit->idEntreprise == matieresPremieres[i]->idEntreprise))
        {
            matieresPremieres[i]->quantite += produit->quantite;
                std::cout << &(produit->idProduit) << " "<< &(matieresPremieres[i]->idProduit)<< std::endl;
            delete produit;
            return;
        }
    }
    matieresPremieres.push_back(produit);
}


// Destucteur de Market
Market::~Market()
{
    for (Produit* produit : produitsFinis) {
        delete produit;
    }
    for (Produit* produit : matieresPremieres) {
        delete produit;
    }

    delete(instance);
}

// Constructeur de Market
Market::Market()
{
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
    std::vector<EntrepriseProduitFinis*> marchandsProduitsFinis = Automate::getInstance()->getEntreprisesProduitFinis();
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

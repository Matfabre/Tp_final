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

//author Pierre-Antoine
// methode pour ajouter un produit fini
void Market::ajouterProduitFini(Produit* produit)
{
    for(int i = 0; i < produitsFinis.size(); i++)
    {
        if(produit->idProduit == produitsFinis[i]->idProduit && produit->idEntreprise == produitsFinis[i]->idEntreprise)  //si le produit est déjà connu
        {                                                                                                    //il suffit d'augmenter la quantité
            produitsFinis[i]->quantite += produit->quantite;
            delete produit;  //on supprime l'objet produit en mémoire, il existe déjà un produit dans le marché qui sera supprimé au destructeur
            return;
        }
    }
    produitsFinis.push_back(produit); //sinon on ajoute le produit au vecteur
}
// methode pour ajouter une matiere première au marché
void Market::ajouterMatierePremiere(Produit* produit)
{
    for(int i = 0; i < matieresPremieres.size(); i++)
    { //si le produit est déjà connu il suffit d'augmenter la quantité
        if((produit->idProduit == matieresPremieres[i]->idProduit) && (produit->idEntreprise == matieresPremieres[i]->idEntreprise))
        {
            matieresPremieres[i]->quantite += produit->quantite;
            delete produit; //on supprime l'objet produit en mémoire, il existe déjà un produit dans le marché qui sera supprimé au destructeur
            return;
        }
    }
    matieresPremieres.push_back(produit);
}


// Destucteur de Market
Market::~Market()
{
    for (Produit* produit : produitsFinis) {  //on supprime toutes les structures produit
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

void Market::transaction(Produit* produit, int quantiteAchete)  //envoie l'argent de la transaction au marchand
{
    (produit->quantite) -= quantiteAchete;
    std::vector<EntrepriseProduitFinis*> marchandsProduitsFinis = Automate::getInstance()->getEntreprisesProduitFinis();
    std::vector<EntrepriseMatierePremiere*> marchandsMatierePremiere = Automate::getInstance()->getEntreprisesMatierePremiere();

    for(Entreprise* marchand : marchandsProduitsFinis)
    {

        if(marchand->getIdEntreprise() == produit->idEntreprise)
        {
            marchand->recois(produit->prix * quantiteAchete);  //on envoie la somme a l'entreprise ayant le bon id
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




Market *Market::instance = NULL;  //initialisation de l'instance à null

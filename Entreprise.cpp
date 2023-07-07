// Mathias
#include "Entreprise.hpp"

Entreprise::Entreprise(std::string _nomEntreprise,int _idEntreprise, float argent) : Client( argent)
{
    nomEntreprise = _nomEntreprise;
    idEntreprise = _idEntreprise;
    capital = argent;

}

int Entreprise::getIdEntreprise()
{
    return idEntreprise;
}

void Entreprise::recois(float montant)
{
    capital += montant;
}

Entreprise::~Entreprise(){}

 void Entreprise::acheterProduits(int achatProduitId)
{
    Entreprise::shop(achatProduitId);
//    idProduits.push_back(id);
//    prixProduits.push_back(prix);
//    coutsProduits.push_back(couts);
//    qualiteProduits.push_back(qualite);
//    reserveProduits.push_back(*produit);

    //cr�ation du produit � vendre
//    produit->idEntreprise = idEntreprise;
//    produit->idProduit = id;
//    produit->qualite = qualite;
//    produit->prix = prix;
//    produit->quantite ++;
}


 void Entreprise::creerProduits( int id, float prix, float couts, float qualite, Produit *produit)
{
    idProduits.push_back(id);
    prixProduits.push_back(prix);
    coutsProduits.push_back(couts);
    qualiteProduits.push_back(qualite);
    reserveProduits.push_back(*produit);

    //cr�ation du produit � vendre
    produit->idEntreprise = idEntreprise;
    produit->idProduit = id;
    produit->qualite = qualite;
    produit->prix = prix;
    produit->quantite ++;
}

 void Entreprise::vendreProduits(int id, float prixVente)
{
    if(id >= (int) idProduits.size())
    {
        std::cout << "L'element a supprimer n'existe pas" << std::endl;
    }
    else
    {
        idProduits.erase(idProduits.begin()+id);
        prixProduits.erase(prixProduits.begin()+id);
        coutsProduits.erase(coutsProduits.begin()+id);
        qualiteProduits.erase(qualiteProduits.begin()+id);

        //Vente du produit
        reserveProduits.erase(reserveProduits.begin()+id);
        recois(prixVente);
    }
}
void Entreprise::afficherEtat()
{
    std::cout << "Entreprise: " << nomEntreprise << " id: " << idEntreprise;
    std::cout << " Capital : " << capital << std::endl;
    for (int i =0 ; i< (int) idProduits.size() ; i++)
    {
        std::cout << "idProduits : " << idProduits.at(i);
        std::cout << " cout produit : " << coutsProduits.at(i);
        std::cout << " qualite produit : " << qualiteProduits.at(i) << std::endl;
    }

}
EntrepriseProduitFinis::EntrepriseProduitFinis(std::string _nomEntreprise,int _idEntreprise, float _capital) : Entreprise(_nomEntreprise,_idEntreprise, _capital)
{
}
EntrepriseProduitFinis::~EntrepriseProduitFinis(){}

void EntrepriseProduitFinis::creerProduits( int id, float prix, float couts, float qualite,  Produit *produit)
{
    Entreprise::creerProduits(id, prix, couts, qualite, produit);
}
void EntrepriseProduitFinis::afficherEtat()
{
    Entreprise::afficherEtat();
}

EntrepriseMatierePremiere::EntrepriseMatierePremiere(std::string _nomEntreprise,int _idEntreprise, float _capital) : Entreprise(_nomEntreprise,_idEntreprise, _capital)
{

}
EntrepriseMatierePremiere::~EntrepriseMatierePremiere(){}

void EntrepriseMatierePremiere::creerProduits()
{
    if(reserveProduits.size() != 0)
    {
        reserveProduits[0].quantite = quantiteProduite;
        reserveProduits[0].qualite = qualiteProduits[0];
        reserveProduits[0].prix = prixProduits[0];
    }
    else
    {
        Produit* produit;

        produit->idEntreprise = idEntreprise;
        produit->idProduit = idProduits[0];
        produit->qualite = qualiteProduits[0];
        produit->prix = prixProduits[0];
        produit->quantite = quantiteProduite;

        reserveProduits.push_back(*produit);
    }

}

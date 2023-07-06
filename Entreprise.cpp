// Mathias
#include "Entreprise.hpp"

Entreprise::Entreprise(std::string _nomEntreprise,int _idEntreprise)
{
    nomEntreprise = _nomEntreprise;
    idEntreprise = _idEntreprise;
    capital = 1000;

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

 void Entreprise::creerProduits( int id, float prix, float couts, float qualite, Produit *produit)
{
    idProduits.push_back(id);
    prixProduits.push_back(prix);
    coutsProduits.push_back(couts);
    qualiteProduits.push_back(qualite);
    reserveProduits.push_back(*produit);

    //création du produit à vendre
    produit->idEntreprise = idEntreprise;
    produit->idProduit = id;
    produit->qualite = qualite;
    produit->prix = prix;
    produit->quantite ++;
}

 void Entreprise::vendreProduits(int id, float prixVente)
{
    idProduits.erase(idProduits.begin()+id);
    prixProduits.erase(prixProduits.begin()+id);
    coutsProduits.erase(coutsProduits.begin()+id);
    qualiteProduits.erase(qualiteProduits.begin()+id);

    //Vente du produit
    reserveProduits.erase(reserveProduits.begin()+id);
    recois(prixVente);
}
void Entreprise::afficherEtat()
{
    std::cout << "Entreprise: " << nomEntreprise << " id: " << idEntreprise <<std::endl;
    std::cout << "Captial :" << capital << std::endl;
}
EntrepriseProduitFinis::EntrepriseProduitFinis(std::string _nomEntreprise,int _idEntreprise) : Entreprise(_nomEntreprise,_idEntreprise)
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

EntrepriseMatierePremiere::EntrepriseMatierePremiere(std::string _nomEntreprise,int _idEntreprise) : Entreprise(_nomEntreprise,_idEntreprise)
{
}
EntrepriseMatierePremiere::~EntrepriseMatierePremiere(){}

// Mathias
#include "Entreprise.hpp"

Entreprise::Entreprise(std::string _nomEntreprise,int _idEntreprise)
{
    nomEntreprise = _nomEntreprise;
    idEntreprise = _idEntreprise;
    capital = 1000;

}

Entreprise::~Entreprise(){}

 void Entreprise::ajouterProduits( int id, float prix, float couts, float qualite)
{
    idProduits.push_back(id);
    prixProduits.push_back(prix);
    coutsProduits.push_back(couts);
    qualiteProduits.push_back(qualite);
}

EntrepriseProduitFinis::EntrepriseProduitFinis(std::string _nomEntreprise,int _idEntreprise) : Entreprise(_nomEntreprise,_idEntreprise)
{
}
EntrepriseProduitFinis::~EntrepriseProduitFinis(){}

void EntrepriseProduitFinis::ajouterProduits( int id, float prix, float couts, float qualite)
{
    Entreprise::ajouterProduits(id, prix, couts, qualite);
}

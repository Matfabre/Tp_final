#ifndef ENTREPRISE_HPP
#define ENTREPRISE_HPP

// Mathias
#pragma once
#include <vector>
#include <string>
#include "produit.hpp"
#include "Client.hpp"
class Entreprise
{
protected:
    std::string nomEntreprise;
    int idEntreprise;
    float capital;
    std::vector<int> idProduits;
    std::vector<float> prixProduits;
    std::vector<float> coutsProduits;
    std::vector<float> qualiteProduits;
    std::vector<Produit> reserveProduits;

public:
    Entreprise(std::string _nomEntreprise,int _idEntreprise, float argent);
    virtual ~Entreprise();
    int getIdEntreprise();
    void recois(float montant);
    void acheterProduits(int achatProduitId);
    virtual void creerProduits( int id, float prix, float couts, float qualite);
    void vendreProduits(int id, float prixVente);
    void afficherEtat();



};
#endif


#ifndef ENTREPRISEPRODUITFINIS_HPP
#define ENTREPRISEPRODUITFINIS_HPP

class EntrepriseProduitFinis : public Entreprise
{
private:
public:
    EntrepriseProduitFinis(std::string _nomEntreprise,int _idEntreprise, float _capital);
    ~EntrepriseProduitFinis();
    void creerProduits();
    virtual void creerProduits( int id, float prix, float couts, float qualite);
    void afficherEtat();

};

class EntrepriseMatierePremiere : public Entreprise
{
private:
    int quantiteProduite;
public:
    EntrepriseMatierePremiere(std::string _nomEntreprise,int _idEntreprise, float _capital);
    ~EntrepriseMatierePremiere();
    void creerProduits();
    void insertionNouveauProduit(int _id, float _prix, float _qualite,  float _couts, int _quantiteProduite);


};
#endif

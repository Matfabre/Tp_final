// CLAIRE Belmont
#ifndef PRODUIT_HPP
#define PRODUIT_HPP
#include <iostream>

// Creation de la structure Produit
struct Produit
{
    int idProduit;
    float prix;
    int idEntreprise;
    int quantite;
    float qualite;
    // Constructeur par defaut
    Produit();
    // constructeur
    Produit(int _idProduit, float _prix, int _idEntreprise, int _quantite, float _qualite);
};

#endif

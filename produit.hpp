// CLAIRE Belmont
#ifndef PRODUIT_HPP
#define PRODUIT_HPP
#include <iostream>


struct Produit
{
    int idProduit;
    float prix;
    int idEntreprise;
    int quantite;
    int qualite;
    Produit(){};
    Produit(int _idProduit, float _prix, int _idEntreprise, int _quantite, int _qualite):
        idProduit(_idProduit),prix(_prix),idEntreprise(_idEntreprise), quantite(_quantite),qualite(_qualite)
    {
    }
};

#endif

//CLAIRE Belmont
#include "produit.hpp"

struct Produit produit;

// Contructeur par defaut
Produit::Produit()
{

}

// Constructeur
Produit::Produit(int _idProduit, float _prix, int _idEntreprise, int _quantite, int _qualite):
        idProduit(_idProduit),prix(_prix),idEntreprise(_idEntreprise), quantite(_quantite),qualite(_qualite)
{

}

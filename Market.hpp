// CLAIRE Belmont
#ifndef MARKET_HPP
#define MARKET_HPP
#include <iostream>
#include <vector>
#include "produit.hpp"
// creation de la classe Market qui contiendra les produits des entreprises
class Market
{
public :
    // Constructeur sous forme de singleton
    static void constructeurMarket();

    // methode pour avoir l'instance
    static Market *getInstance();

    //Destructeur
    ~Market();

    //methode pour ajouter un produit
    void ajouterProduit(Produit *produit);
protected:
    static int nombreInstances;
    static Market *instance;
    std::vector<Produit*> Produits;

private:
    Market();
};


#endif // MARKET_HPP

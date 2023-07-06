// CLAIRE Belmont
#ifndef MARKET_HPP
#define MARKET_HPP
#include <iostream>
#include <vector>

class Market
{
public :
    static void constructeurMarket();

    static Market *getInstance();

    ~Market();

    void ajouterProduit(Produit *produit);
protected:
    static int nombreInstances;
    static Market *instance;
    std::vector<Produit*> Produits;

private:
    Market();
};


#endif // MARKET_HPP

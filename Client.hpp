#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Client.hpp"
#include "produit.hpp"

class Client
{
private:
    float salaire;
    float argent;

public:
    Client(float _salaire, float _argent);
    Client(float _argent);
    void shop(int _produitRechercheId);
    ~Client();

private:
    void gagneSalaire();
    Produit* selectProduit(std::vector<Produit*> produits);
};

#endif


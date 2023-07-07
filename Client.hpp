#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Client.hpp"
#include "produit.hpp"

class Client
{
private:
    float salaire;
    float argent;
    int produitRechercheId;

public:
    Client(float _salaire, float _argent, int _produitRechercheId);
    Client(float _argent);
    void shop(int _produitRechercheId);
    void shop();
    ~Client();

private:
    void gagneSalaire();
    Produit* selectProduit(std::vector<Produit*> produits);
};

#endif


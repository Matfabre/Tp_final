#pragma once
#include <vector>
#include "Entreprise.hpp"
#include "Client.hpp"
#include "Market.hpp"
#include "produit.hpp"
#include "CompteRendu.hpp"
#include "ListeProduit.hpp"

class Automate
{
private:
    std::vector<EntrepriseProduitFinis*> entreprisesProduitFinis;
    std::vector<EntrepriseMatierePremiere*> entreprisesMatierePremiere;

    std::vector<Client*> clients;
    Automate();
protected:
    static Automate* instance;

public:
    static Automate* getInstance();
    void initialClient(const int& N_PRODUITS_FINIS);
    void initialEntreprise();
    void initialProduit();
    void addEntrepriseProduitFinis(EntrepriseProduitFinis* entreprise);
    void addEntrepriseMatierePremiere(EntrepriseMatierePremiere* entreprise);
    void addClient(Client& client);
    void gestionMemoire();
    void play(int n_tours);
    std::vector<EntrepriseProduitFinis*> getEntreprisesProduitFinis();
    std::vector<EntrepriseMatierePremiere*> getEntreprisesMatierePremiere();
    ~Automate();
};


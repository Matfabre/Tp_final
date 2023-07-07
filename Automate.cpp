#include "Automate.hpp"
#include "Entreprise.hpp"
#include <Time.h>
#include <vector>
#include <random>

Automate::Automate()
{
}

void Automate::addEntrepriseProduitFinis(EntrepriseProduitFinis& entreprise)
{
    entreprisesProduitFinis.push_back(&entreprise);
}

void Automate::addEntrepriseMatierePremiere(EntrepriseMatierePremiere& entreprise)
{
    entreprisesMatierePremiere.push_back(&entreprise);
}

void Automate::addClient(Client& client)
{
    clients.push_back(&client);
}

Automate* Automate::getInstance()
{
    if(instance == NULL)
    {
        instance = new Automate();
    }
    else
    {
        std::cout << "Deja initialise !" << std::endl;
    }
    return instance;
}

void Automate::initialClient(const int& N_PRODUITS_FINIS)
{
    srand((unsigned) time(NULL));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, N_PRODUITS_FINIS + 1);

    // Creation de 100 clients
    for(int i = 0; i<100; i++)
    {
        // salaire est un nombre au hasard entre 0 et 3000
        float salaire = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/3000));
        // argent est un nombre au hasard entre 0 et 3000
        float argent = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/3000));
        Client client(salaire, argent, dist(gen));
        instance->addClient(client);
    }
}

void Automate::initialEntreprise()
{
    EntrepriseProduitFinis SuperMeuble("SuperMeuble",1, 10000);
    EntrepriseProduitFinis MeubleHyper("MeubleHyper",2, 10000);
    EntrepriseProduitFinis DecoMaison("DecoMaison",3, 10000);
    EntrepriseProduitFinis CuisineOutil("CuisineOutil",4, 10000);
    EntrepriseProduitFinis MonJardin("MonJardin",5, 10000);

    instance->addEntrepriseProduitFinis(SuperMeuble);
    instance->addEntrepriseProduitFinis(MeubleHyper);
    instance->addEntrepriseProduitFinis(DecoMaison);
    instance->addEntrepriseProduitFinis(CuisineOutil);
    instance->addEntrepriseProduitFinis(MonJardin);
}

std::vector<EntrepriseProduitFinis*> *Automate::getEntreprisesProduitFinis()
{
    return &entreprisesProduitFinis;
}

std::vector<EntrepriseMatierePremiere*> Automate::getEntreprisesMatierePremiere()
{
    return entreprisesMatierePremiere;
}

void Automate::play(int n_tours)
{
    for(int i = 0; i < n_tours; i++)
    {
        for(EntrepriseMatierePremiere* entreprise : entreprisesMatierePremiere)
        {
            //entreprise->creerProduits();
        }
        for(EntrepriseProduitFinis* entreprise : entreprisesProduitFinis)
        {
            //entreprise->shop();
        }
        for(EntrepriseProduitFinis* entreprise : entreprisesProduitFinis)
        {
            //entreprise->vendreProduits();
        }
        for(Client* client : clients)
        {
            client->gagneSalaire();
            int produitRechercheId = (rand() % 3) + 1;
            client->shop(produitRechercheId);
        }
        //CompteRendu::afficheCR(entreprises, i);
    }

}

void Automate::gestionMemoire()
{

}

Automate::~Automate()
{

}

Automate* Automate::instance = NULL;

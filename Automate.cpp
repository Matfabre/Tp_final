#include "Automate.hpp"
#include <Time.h>
#include <vector>
#include <random>

Automate::Automate()
{
}

void Automate::addEntreprise(Entreprise& entreprise)
{
    entreprises.push_back(&entreprise);
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
    EntrepriseProduitFinis SuperMeuble("SuperMeuble",1);
    EntrepriseProduitFinis MeubleHyper("MeubleHyper",2);
    EntrepriseProduitFinis DecoMaison("DecoMaison",3);
    EntrepriseProduitFinis CuisineOutil("CuisineOutil",4);
    EntrepriseProduitFinis MonJardin("MonJardin",5);

    instance->addEntreprise(SuperMeuble);
    instance->addEntreprise(MeubleHyper);
    instance->addEntreprise(DecoMaison);
    instance->addEntreprise(CuisineOutil);
    instance->addEntreprise(MonJardin);
}

std::vector<Entreprise*> Automate::getEntreprises()
{
    return entreprises;
}

void Automate::play(int n_tours)
{
    for(int i = 0; i < n_tours; i++)
    {
        for(Entreprise* entreprise : entreprises)
        {
            //entreprise->creerProduits();
        }
        for(Entreprise* entreprise : entreprises)
        {
            //entreprise->shop();
        }
        for(Entreprise* entreprise : entreprises)
        {
            //entreprise->vendreProduits();
        }
        for(Client* client : clients)
        {
            client->shop();
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

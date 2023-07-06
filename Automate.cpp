#include "Automate.hpp"
#include <Time.h>

Automate::Automate()
{
}

void Automate::addEntreprise(const Entreprise& entreprise)
{
    entreprises.push_back(entreprise);
}

void Automate::addClient(const Client& client)
{
    clients.push_back(client);
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

void Automate::initialClient()
{
    srand((unsigned) time(NULL));

    // Creation de 20 clients
    for(int i = 0; i<20; i++)
    {
        // salaire est un nombre au hasard entre 0 et 3000
        float salaire = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/3000));
        // argent est un nombre au hasard entre 0 et 3000
        float argent = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/3000));
        Client client(salaire, argent);
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


Automate::~Automate()
{

}

Automate* Automate::instance = NULL;

#include "Automate.hpp"
#include <Time.h>

Automate::Automate()
{
    Entreprise SuperMeuble("SuperMeuble",1);
    Entreprise MeubleHyper("MeubleHyper",2);
    Entreprise DecoMaison("DecoMaison",3);
    Entreprise CuisineOutil("CuisineOutil",4);
    Entreprise MonJardin("MonJardin",5);

    getInstance()->addEntreprise(SuperMeuble);
    getInstance()->addEntreprise(MeubleHyper);
    getInstance()->addEntreprise(DecoMaison);
    getInstance()->addEntreprise(CuisineOutil);
    getInstance()->addEntreprise(MonJardin);

    srand((unsigned) time(NULL));

    // Creation de 20 clients
    for(int i = 0; i<20; i++)
    {
        // salaire est un nombre au hasard entre 0 et 3000
        float salaire = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/3000));
        // argent est un nombre au hasard entre 0 et 3000
        float argent = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/3000));
        Client client(salaire, argent);
        getInstance()->addClient(client);
    }
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


Automate::~Automate()
{

}

Automate* Automate::instance = NULL;

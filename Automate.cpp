#include "Automate.hpp"

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

static Automate* Automate::getInstance()
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

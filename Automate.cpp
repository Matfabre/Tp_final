#include "Automate.hpp"
#include <vector>

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

std::vector<Entreprise*> Automate::getEntreprises()
{
    return entreprises;
}

Automate::~Automate()
{

}

Automate* Automate::instance = NULL;

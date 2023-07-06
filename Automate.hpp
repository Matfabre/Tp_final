#include <vector>
#include "Entreprise.hpp"
#include "Client.hpp"
#include "Market.hpp"

class Automate
{
private:
    std::vector<Entreprise> entreprises;
    std::vector<Client> clients;
    Automate();
protected:
    static Automate* instance;

public:
    static Automate* getInstance();
    void addEntreprise(const Entreprise& entreprise);
    void addClient(const Client& client);
    ~Automate();
};


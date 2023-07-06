#include <vector>
#include "Entreprise.hpp"
#include "Client.hpp"
#include "Market.hpp"
#include "produit.hpp"
#include "CompteRendu.hpp"

class Automate
{
private:
    std::vector<Entreprise*> entreprises;
    std::vector<Client*> clients;
    Automate();
protected:
    static Automate* instance;

public:
    static Automate* getInstance();
    void initialClient(const int& N_PRODUITS_FINIS);
    void initialEntreprise();
    void addEntreprise(Entreprise& entreprise);
    void addClient(Client& client);
    void gestionMemoire();
    void play(int n_tours);
    std::vector<Entreprise*> getEntreprises();
    ~Automate();
};


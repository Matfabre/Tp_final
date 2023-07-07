#include "Automate.hpp"
#include "Entreprise.hpp"
#include <Time.h>
#include <vector>
#include <random>

Automate::Automate()
{
}

void Automate::addEntrepriseProduitFinis(EntrepriseProduitFinis* entreprise)
{
    entreprisesProduitFinis.push_back(entreprise);
}

void Automate::addEntrepriseMatierePremiere(EntrepriseMatierePremiere* entreprise)
{
    entreprisesMatierePremiere.push_back(entreprise);
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
    instance->addEntrepriseProduitFinis(new EntrepriseProduitFinis("SuperMeuble",1, 10000));
    instance->addEntrepriseProduitFinis(new EntrepriseProduitFinis("MeubleHyper",2, 10000));
    instance->addEntrepriseProduitFinis(new EntrepriseProduitFinis("DecoMaison",3, 10000));
    instance->addEntrepriseProduitFinis(new EntrepriseProduitFinis("CuisineOutil",4, 10000));
    instance->addEntrepriseProduitFinis(new EntrepriseProduitFinis("MonJardin",5, 10000));


    EntrepriseMatierePremiere* gigabois = new EntrepriseMatierePremiere("GigaBois",6, 10000);
    gigabois->insertionNouveauProduit(-1, 50.0f, 5.0f, 20.0f, 100);
    instance->addEntrepriseMatierePremiere(gigabois);

    EntrepriseMatierePremiere* gigafer = new EntrepriseMatierePremiere("GigaFer",7, 10000);
    gigafer->insertionNouveauProduit(-2, 200.0f, 5.0f, 100.0f, 30);
    instance->addEntrepriseMatierePremiere(gigafer);


}

void Automate::initialProduit()
{
    ListeProduit L1;


    std::vector<Produit> vproduitsFini;
    std::vector<Produit> vmatieresPremiere;
    std::cout <<'\n' <<  "Matieres Premiere : ";
    for(int i =1 ; i<= L1.size()/2 ; i++)
    {
        Produit p;
        vproduitsFini.push_back(p);

        std::cout << L1[i] << ": id = " << i << ", ";
    }
    std::cout << std::endl;
    std::cout << "Produits finis : ";
    for(int i =1 ; i<= L1.size()/2 ; i++)
    {
        Produit p;
        vmatieresPremiere.push_back(p);
        std::cout << L1[-i] << ": id = " << -i << ", ";
    }
    std::cout << '\n' << std::endl;


}
std::vector<EntrepriseProduitFinis*> Automate::getEntreprisesProduitFinis()
{
    return entreprisesProduitFinis;
}

std::vector<EntrepriseMatierePremiere*> Automate::getEntreprisesMatierePremiere()
{
    return entreprisesMatierePremiere;
}

void Automate::play(int n_tours)
{
    for(int i = 0; i < n_tours; i++)
    {
        std::cout << "[ TOUR " << i + 1 << " ]"<< std::endl;
        for(EntrepriseMatierePremiere* entreprise : entreprisesMatierePremiere)
        {
            entreprise->creerProduits();
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
    for (EntrepriseProduitFinis* entreprise : entreprisesProduitFinis) {
        delete entreprise;
    }
    for (EntrepriseMatierePremiere* entreprise : entreprisesMatierePremiere) {
        delete entreprise;
    }
    for (Client* client : clients) {
        delete client;
    }

    delete(instance);
}

Automate* Automate::instance = NULL;

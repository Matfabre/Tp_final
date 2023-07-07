//authors : Pierre-Antoine
// Classe gérant l'exécution des tâches
#include "Automate.hpp"
#include "Entreprise.hpp"
#include <Time.h>
#include <vector>
#include <random>

Automate::Automate()
{
}

void Automate::addEntrepriseProduitFinis(EntrepriseProduitFinis* entreprise)  //ajoute une entreprise au vecteur attribut
{
    entreprisesProduitFinis.push_back(entreprise);
}

void Automate::addEntrepriseMatierePremiere(EntrepriseMatierePremiere* entreprise) //ajoute une entreprise au vecteur attribut
{
    entreprisesMatierePremiere.push_back(entreprise);
}

void Automate::addClient(Client& client) //ajoute un client au vecteur attribut
{
    clients.push_back(&client);
}

Automate* Automate::getInstance()   //singleton Automate
{
    if(instance == NULL)
    {
        instance = new Automate();
    }

    return instance;
}

void Automate::initialClient(const int& N_PRODUITS_FINIS)  //initialise le vecteur de clients
{
    srand((unsigned) time(NULL));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, N_PRODUITS_FINIS + 1);

    // Creation de 100 clients
    for(int i = 0; i<10; i++)
    {
        // salaire est un nombre au hasard entre 0 et 3000
        float salaire = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/3000));
        // argent est un nombre au hasard entre 0 et 3000
        float argent = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/3000));
        Client client(salaire, argent, dist(gen));
        instance->addClient(client);
    }
}

void Automate::initialEntreprise() //initialise les entreprises
{

    EntrepriseProduitFinis* superMeuble = new EntrepriseProduitFinis("SuperMeuble",1, 10000);
    superMeuble->creerProduits(1, 1000.0f, 500.0f, 4.0f);
    instance->addEntrepriseProduitFinis(superMeuble);


    EntrepriseProduitFinis* meubleHyper = new EntrepriseProduitFinis("MeubleHyper",1, 10000);
    meubleHyper->creerProduits(1, 1000.0f, 500.0f, 4.0f);
    instance->addEntrepriseProduitFinis(meubleHyper);

    EntrepriseProduitFinis* cuisineOutil = new EntrepriseProduitFinis("CuisineOutil",1, 10000);
    cuisineOutil->creerProduits(2, 1000.0f, 500.0f, 4.0f);
    instance->addEntrepriseProduitFinis(cuisineOutil);

    EntrepriseProduitFinis* decoMaison = new EntrepriseProduitFinis("DecoMaison",1, 10000);
    decoMaison->creerProduits(2, 1000.0f, 500.0f, 4.0f);
    instance->addEntrepriseProduitFinis(decoMaison);

    EntrepriseProduitFinis* monJardin = new EntrepriseProduitFinis("MonJardin",1, 10000);
    monJardin->creerProduits(3, 1000.0f, 500.0f, 4.0f);
    instance->addEntrepriseProduitFinis(monJardin);

    EntrepriseMatierePremiere* gigabois = new EntrepriseMatierePremiere("GigaBois",6, 10000);
    gigabois->insertionNouveauProduit(-1, 50.0f, 5.0f, 20.0f, 100);
    instance->addEntrepriseMatierePremiere(gigabois);

    EntrepriseMatierePremiere* gigafer = new EntrepriseMatierePremiere("GigaFer",7, 10000);
    gigafer->insertionNouveauProduit(-2, 200.0f, 5.0f, 100.0f, 30);
    instance->addEntrepriseMatierePremiere(gigafer);


}

void Automate::initialProduit()  //affiche les informations produit au début de l'exécution
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

void Automate::play(int n_tours)  //joue les étapes de tour par tour
{
    for(int i = 0; i < n_tours; i++)
    {
        std::cout << "[ TOUR " << i + 1 << " ]"<< std::endl;
        for(EntrepriseMatierePremiere* entreprise : entreprisesMatierePremiere)  //les entreprises de matière première crééent leur ressources
        {
            entreprise->creerProduits();
        }

        for(EntrepriseProduitFinis* entreprise : entreprisesProduitFinis)  //les entreprises produit finis les achètent
        {
            //entreprise->shop();
        }
        for(EntrepriseProduitFinis* entreprise : entreprisesProduitFinis) //elles construisent et envoie leur produit sur le marché
        {
            entreprise->creerProduits();
        }
        for(Client* client : clients)  // les clients achètent ensuite le produit
        {
            client->gagneSalaire();
            int produitRechercheId = (rand() % 3) + 1;
            client->shop(produitRechercheId);
        }
        CompteRendu::afficheCR(this);  //on affiche les informations de l'étape
    }

}

void Automate::gestionMemoire()
{

}

Automate::~Automate()  //destructeur
{
    for (EntrepriseProduitFinis* entreprise : entreprisesProduitFinis) { //on fait en sorte que toutes les entreprises et client soient détruits
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

Automate* Automate::instance = NULL;  //initialisation de l'instance à null

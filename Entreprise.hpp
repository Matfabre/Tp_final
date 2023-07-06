#ifndef ENTREPRISE_HPP
#define ENTREPRISE_HPP

// Mathias
#include <vector>
#include <string>

class Entreprise
{
private:
    std::string nomEntreprise;
    int idEntreprise;
    float capital;
    std::vector<int> idProduits;
    std::vector<float> prixProduits;
    std::vector<float> coutsProduits;
    std::vector<float> qualiteProduits;
    std::vector<float> reserveProduits;

public:
    Entreprise(std::string _nomEntreprise,int _idEntreprise);
    virtual ~Entreprise();
    int getIdEntreprise();
    void recois(float montant);
    virtual void ajouterProduits( int id, float prix, float couts, float qualite);

};
#endif


#ifndef ENTREPRISEPRODUITFINIS_HPP
#define ENTREPRISEPRODUITFINIS_HPP

class EntrepriseProduitFinis : public Entreprise
{
private:
public:
    EntrepriseProduitFinis(std::string _nomEntreprise,int _idEntreprise);
    ~EntrepriseProduitFinis();

    virtual void ajouterProduits( int id, float prix, float couts, float qualite);

};
#endif

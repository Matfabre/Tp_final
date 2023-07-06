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

    virtual void ajouterProduits( int id, float prix, float couts, float qualite);

};

class EntrepriseProduitFinis : public Entreprise
{
private:
public:
    EntrepriseProduitFinis(std::string _nomEntreprise,int _idEntreprise);
    ~EntrepriseProduitFinis();

    virtual void ajouterProduits( int id, float prix, float couts, float qualite, Produit produit);

};

void testentreprise()
{
    EntrepriseProduitFinis Ikea{"ikea", 2};
    Ikea.ajouterProduits(3,3,3,3);
    Ikea.ajouterProduits(8,6,2,4);
    cout << "entrepriseOK" << endl;
}

#include <string>
#include <unordered_map>
class ListeProduit
{
public:
    std::string operator[](int id) const;
    ~ListeProduit();

private:
    std::unordered_map<int, std::string> produits =
    {
        {1, "Produit 1"},
        {2, "Produit 2"},
        {3, "Produit 3"}
    };
};


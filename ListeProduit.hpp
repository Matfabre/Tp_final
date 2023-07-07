#pragma once
#include <string>
#include <unordered_map>
class ListeProduit
{
public:
    std::string operator[](int id) const;
    int size();
    ~ListeProduit();

private:
    std::unordered_map<int, std::string> produits =
    {
        {-1, "Planche"},
        {-2, "Ferraille"},
        {-3, "Pierre"},
        {1, "Table"},
        {2, "Voiture"},
        {3, "Piscine"}
    };
};


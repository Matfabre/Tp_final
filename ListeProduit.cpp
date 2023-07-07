//author : Pierre-Antoine
//cette classe sert à accéder aux noms des produits à partir de leur id
#include "ListeProduit.hpp"

std::string ListeProduit::operator[](int id) const  //surcharge de l'opérateur [] pour rendre l'accessibilité en dictionnaire
{
    return produits.at(id);
}
int ListeProduit::size()
{
    return produits.size();
}
ListeProduit::~ListeProduit()
{

}

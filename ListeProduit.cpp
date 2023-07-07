#include "ListeProduit.hpp"

std::string ListeProduit::operator[](int id) const
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

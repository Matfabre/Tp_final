#include "ListeProduit.hpp"

std::string ListeProduit::operator[](int id) const
{
    return produits.at(id);
}

ListeProduit::~ListeProduit()
{

}

#include "client.hpp"
#include <iostream>

Client::Client(float _salaire, float _argent)
{
    salaire = _salaire;
    argent = _argent;
}

void Client::shop()
{
}


void Client::gagneSalaire() {
    argent += salaire;
}

Client::~Client()
{

}

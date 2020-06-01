// Formes.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

#include "ez-draw++.hpp"

#include "formes.hpp"

Formes::Formes(unsigned int taille)
:maxformes(taille),nbformes(0),formes(nullptr)
{
    formes = new Forme * [taille];
}

Formes::~Formes()
{
for(uint i=0;i<nbformes;i++)
delete formes[i];
delete [] formes;
}

void Formes::ajouter(Forme *f)
{
    if(nbformes>=maxformes)
    throw runtime_error("Impossible d'ajouter une forme");
else
   formes[nbformes++]=f;
}

// Rappel : « a->f() » est la même chose que « (*a).f() ».

void Formes::dessiner(EZWindow& w) const
{
    for(uint i=0; i<nbformes;++i)
        formes[i]->dessiner(w); // ou de manière équivalente : (*formes[i]).dessiner(w);
}

Forme* Formes::isOver(uint _x,uint _y)
{
    for (uint i=0; i<nbformes; ++i)
        if( formes[i]->isOver(_x, _y) )
            return formes[i];
   return nullptr;
}

/* Rappel :
a.operator<<(os) // Faux avec l'implantation que nous avons faite (en fonction non-membre).
operator<<(os,a); // Juste et compliqué
os << a // Juste et simple
*/

ostream& operator<<(ostream& os, const Formes& formes)
{
    for(uint i=0; i<formes.nbformes;++i)
os << *formes.formes[i];
return os;
}

void Formes::sauver(ostream& os) const
{
    os << nbformes << endl;
//    operator<<(os,*this); Compliqué !!!
    os << *this; // Simple !
}

void Formes::charger(istream& is)
{
    uint nbf;
    is >>  nbf;
    for(int i=0; i<nbf; i++)
    ajouter(Forme::charger(is));
}



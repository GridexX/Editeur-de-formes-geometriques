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
    cout << "Nb :" << nbformes<< endl;
    for(uint i=0;i<nbformes;i++){
        cout << "Boucle ind:"<<i<<endl;
        delete formes[i];
    }
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
    for(uint i=0; i<nbf; i++)
        ajouter(Forme::charger(is));
}


void Formes::supprimer(Forme *forme)
{
    uint i=0;
    uint indForme;
    bool trouve=false;
    while(!trouve && i<nbformes){   //On parcourt le tableau de formes jusqu'à ce qu'on obtienne la bonne et on sauvegarde l'indice
        if(formes[i] == forme){
            trouve=true;
            indForme=i;
        }
        i++; 
    }    
    
    if(trouve){
        uint j=0;
        Forme **tabFormes = new Forme * [maxformes];    //On crée un nouveau tableau de forme et on le remplit avec toutes celles d'avant sauf celle à supprimer
        for (uint i=0; i<nbformes; ++i){
            if( formes[i] != forme  )
                tabFormes[j++] = formes[i];    
        }

        formes[indForme]->~Forme(); //On détruit la forme et on reset le tableau
        delete [] formes;
        formes=tabFormes;
        --nbformes;
    }
} 
#include <iostream>

using namespace std;

#include "calques2.hpp"


Calques::Calques(size_t taille)
 : listeCalque(), maxcalques(taille), nbcalques(1)
{
    listeCalque[1].first = new Formes;
    listeCalque[1].second = new bool;
    *listeCalque[1].second = true;
    listeCalque.reserve(taille);

}

Calques::~Calques()
{
    for(uint i=0; i<nbcalques; ++i){
        delete listeCalque[i].first;
        delete listeCalque[i].second;
        nbcalques=0;
    }
}

void Calques::ajouter(Formes *calque)
{
    if(nbcalques<maxcalques)
    {
        std::pair<Formes *, bool *> tPaire;
        tPaire.first = calque;
        *tPaire.second = true;
        listeCalque.push_back(tPaire);
        nbcalques++;
    }
    else
        cerr << "La liste des calques est pleine";

}

void Calques::supprimer(uint index)
{
    if(nbcalques > 0){
        listeCalque.erase(listeCalque.begin()+index);
        nbcalques--;
    }
    else
        cerr << "Il n'y a plus de calques à supprimer";
}

void Calques::monterCalque(uint index)
{
    if(index < maxcalques && nbcalques > 1){
        std::pair<Formes *, bool *> tPaire = listeCalque[index+1];
        listeCalque[index+1] = listeCalque[index];
        listeCalque[index] = tPaire;
    }
    else
        cerr << "Vous ne pouvez pas monter ce calque";
}

void Calques::descendreCalque(uint index)
{
    if(index > 0 && nbcalques > 1){
        std::pair<Formes *, bool *> tPaire = listeCalque[index-1];
        listeCalque[index-1] = listeCalque[index];
        listeCalque[index] = tPaire;
    }
    else
        cerr << "Vous ne pouvez pas descendre ce calque";
}

void Calques::dessiner(EZWindow &w) const
{
    for ( uint i=0; i<nbcalques; ++i)
        if ( *listeCalque[i].second == true )
            listeCalque[i].first->dessiner(w);
}

Forme *Calques::isOver(uint _x, uint _y)
{
    for ( uint i=0; i<nbcalques; ++i)
        if( listeCalque[i].first->isOver(_x,_y) != nullptr)
            return listeCalque[i].first->isOver(_x,_y);
}
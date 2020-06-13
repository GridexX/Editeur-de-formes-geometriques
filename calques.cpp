#include <iostream>

using namespace std;

#include "calques.hpp"



Calques::Calques(size_t taille)
 : listeCalque(), maxcalques(taille), nbcalques(0), calqueSelec(0)
{
    listeCalque.reserve(taille);
    creerCalque(nbcalques++);  
}

Calques::~Calques()
{
    for(uint i=0; i<nbcalques; ++i){
        delete listeCalque[i].first;
    }
    nbcalques=0;
}

void Calques::creerCalque(uint _nbcalques)
{
    listeCalque[_nbcalques].first = new Formes;
    listeCalque[_nbcalques].second = true;
}

void Calques::creerCalque()
{
    if(nbcalques<maxcalques)
        creerCalque(nbcalques++);
    else
        cerr << "La liste des calques est pleine";
}


void Calques::supprimerCalque() //modif
{
    if(nbcalques > 0){
        listeCalque.erase(listeCalque.begin()+calqueSelec);
        nbcalques--;
    }
    else
        cerr << "Il n'y a plus de calques à supprimer";
}

void Calques::monterCalque()
{
    if(calqueSelec < nbcalques && nbcalques > 1){
        calqAndBool tPaire = listeCalque[calqueSelec+1];
        listeCalque[calqueSelec+1] = listeCalque[calqueSelec];
        listeCalque[calqueSelec] = tPaire;
    }
    else
        cerr << "Vous ne pouvez pas monter ce calque";
}

void Calques::descendreCalque()
{
    if(calqueSelec > 0 && nbcalques > 1){
        calqAndBool tPaire = listeCalque[calqueSelec-1];
        listeCalque[calqueSelec-1] = listeCalque[calqueSelec];
        listeCalque[calqueSelec] = tPaire;
    }
    else
        cerr << "Vous ne pouvez pas descendre ce calque";
}

void Calques::ajouterForme( Forme *forme )
{
    listeCalque[calqueSelec].first->ajouter(forme);
    listeCalque[calqueSelec].second=true;
}


void Calques::swapFormeCalque(Forme *forme, uint dest)
{
    //si il n'y a pas de calque déjà crée au dessus, on en crée 1
/*
    if(calqueSelec==nbcalques && calqueSelec<maxcalques-1){
        Forme *forme =new
        supprimerForme(forme);
        creerCalque();
        calqueSelec++;
        ajouterForme(forme);
    }*/
    
    
}

void Calques::fusionner()
{}

void Calques::dessiner(EZWindow &w) const
{
    for ( uint i=0; i<nbcalques; ++i)
        if ( listeCalque[i].second == true )
            listeCalque[i].first->dessiner(w);
}

Forme *Calques::isOver(uint _x, uint _y)
{
    return listeCalque[calqueSelec].first->isOver(_x,_y);
}

void Calques::supprimerForme(Forme *f)
{
    for ( uint i=0; i<nbcalques; ++i)
        listeCalque[i].first->supprimer(f);
}

ostream& operator<<(ostream& os, const Calques &calques)
{
    for(uint i=0; i<calques.nbcalques; ++i)
    {
        os << "Calque n°" << i+1 << endl;
        for ( uint j=0 ; j<calques.nbcalques ; ++j )
            os << "test";
    }
    return os;
}

void Calques::sauver(ostream &os) const
{
    listeCalque[calqueSelec].first->sauver(os);
}


void Calques::charger(istream &is)
{ /*
    uint nbc;
    is >> nbc;
    for(uint i=0 ; i<nbc ; ++i)
        ajouter( Formes::charger(is) );
        for ( uint j=0 ; j<calques.getCalque(i).getFormes() ; j ) */

    listeCalque[calqueSelec].first->charger(is);
} 
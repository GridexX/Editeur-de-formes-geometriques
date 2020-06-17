/** @file calques.cpp
 *  @author DUHAMEL Andréa et FOUGEROUSE Arsène
 *  @date Juin 2020
 *  @brief Classe Calques
 */

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
    for(uint i=0; i<nbcalques; ++i)
        listeCalque.clear();
    nbcalques=0;
}

void Calques::creerCalque(uint numCalque)
{
    //calqAndBool nvCalq;
    //nvCalq.first=new Formes; nvCalq.second=true;
    listeCalque[numCalque].first= new Formes; listeCalque[numCalque].second=true;
    //listeCalque.insert(listeCalque.begin()+numCalque, nvCalq);
}

void Calques::creerCalque()
{
    if(nbcalques<maxcalques){
        creerCalque(nbcalques++);
        if (nbcalques==1)
            calqueSelec=0;
        //++nbcalques;
    }
    else
        cerr << "La liste des calques est pleine" << endl;
}


void Calques::supprimerCalque(uint numCalque) //modif
{
    
    if(nbcalques==0){
        delete listeCalque[numCalque].first;
        listeCalque[numCalque].first=nullptr;
        calqueSelec=1;
    } else
    {
        uint i=0;
        uint indFormes;
        bool trouve=false;
        while(!trouve && i<nbcalques){   //On parcourt le tableau de formes jusqu'à ce qu'on obtienne la bonne et on sauvegarde l'indice
            if(listeCalque[i].first == listeCalque[numCalque].first){
                trouve=true;
                indFormes=i;
            }
            i++; 
        }
          
        if(trouve){
            uint j=0;
            vecFormes tempCalques;    //On crée un nouveau tableau de forme et on le remplit avec toutes celles d'avant sauf celle à supprimer
            tempCalques.reserve(maxcalques);
            for (uint i=0; i<nbcalques; ++i)
                if( listeCalque[i].first != listeCalque[numCalque].first  )
                    tempCalques[j++] = listeCalque[i];

            listeCalque[indFormes].first->~Formes(); //On détruit la forme et on reset le tableau
            listeCalque.swap(tempCalques);
            tempCalques.clear();
            --nbcalques;

            if(calqueSelec==nbcalques)
                --calqueSelec;
        }
    } 
    
}


void Calques::monterCalque()
{
    if(calqueSelec < nbcalques-1 && nbcalques > 1){
        calqAndBool tPaire = listeCalque[calqueSelec+1];
        listeCalque[calqueSelec+1] = listeCalque[calqueSelec];
        listeCalque[calqueSelec++] = tPaire;
    }
    else
        cerr << "Vous ne pouvez pas monter ce calque" << endl;
}

void Calques::descendreCalque()
{
    if(calqueSelec > 0 && nbcalques > 1){
        calqAndBool tPaire = listeCalque[calqueSelec-1];
        listeCalque[calqueSelec-1] = listeCalque[calqueSelec];
        listeCalque[calqueSelec--] = tPaire;
    }
    else
        cerr << "Vous ne pouvez pas descendre ce calque" << endl;
}

void Calques::ajouterForme( Forme *forme )
{
    listeCalque[calqueSelec].first->ajouter(forme);
}


void Calques::swapFormeCalque(Forme *forme, uint dest)
{
    bool doitMonterForme= getCalqueSelec() < dest ? true : false;

    //tester si le calque de destination est compris dans les bornes des calques crées
    if( ( doitMonterForme && getCalqueSelec()+1 < getNbCalques() ) || ( !doitMonterForme && getCalqueSelec()-1 >= 0 ))
    {
        ofstream fo("swapForme.txt");   
        fo<<*forme;
        fo.close();
        ifstream fi("swapForme.txt");
        supprimerForme(forme); 
        if(doitMonterForme)
            setCalqueSelec(getCalqueSelec()+1);
        else
            setCalqueSelec(getCalqueSelec()-1);
        ajouterForme( Forme::charger(fi) );
    }
    else{
        if(doitMonterForme)
            cerr << "Il n'y a pas de calque supérieur disponible" << endl;
        else
            cerr << "Il n'y a pas de calque inférieur disponible" << endl;
    }
        
    
}

void Calques::fusionner()
{
    if( calqueSelec + 1 < nbcalques ){

        ofstream fo("sauvegardeCalque.txt");   
        listeCalque[calqueSelec].first->sauver(fo);
        fo.close();
        ++calqueSelec;
        supprimerCalque(calqueSelec-1);
        //listeCalque.erase(listeCalque.begin()+calqueSelec);
        ifstream fi("sauvegardeCalque.txt");
        listeCalque[calqueSelec].first->charger(fi);
    }
    else
        cerr << "Il n'y a pas de calque supérieur disponible" << endl;
}

void Calques::dessiner(EZWindow &w) const
{
    for ( uint i=0; i<nbcalques; ++i)
        if ( listeCalque[i].second == true )
            listeCalque[i].first->dessiner(w);
}

Forme *Calques::isOver(uint _x, uint _y) const
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
        cerr << "Ind calque: "<<i<<endl;
        calques.listeCalque[i].first->sauver(os);
    }
    return os;
}

void Calques::sauverCalque(ostream &os) const
{
    listeCalque[calqueSelec].first->sauver(os);
}

void Calques::chargerCalque(istream& is) const
{
    listeCalque[calqueSelec].first->charger(is);
}

void Calques::sauver(ostream &os) const
{
    cerr << "nbcalques: "<<nbcalques<<endl;
    os << nbcalques << endl;
    os << *this;
}

void Calques::charger(istream &is)
{ 
    uint nbc;
    is >> nbc;

    for(uint i=0 ; i<nbc ; ++i){
        if(i == nbcalques-1)
            creerCalque();
        listeCalque[i].first->charger(is);
        listeCalque[i].second=true;
    }
} 
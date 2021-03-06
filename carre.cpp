/**
 * @file carre.cpp
 * @author DUHAMEL Andréa et FOUGEROUSE Arsène
 * @date Juin 2020
 * @brief Classe Carré
 */ 

#include <iostream>

using namespace std;

#include "carre.hpp"

Carre::Carre(ulong _couleur, uint _x, uint _y, uint _cote)
: Forme(_couleur,_x,_y), cote(_cote)
{}

Carre::Carre(const Carre& orig)
: Forme(orig),cote(orig.cote)
{}

Carre::Carre(istream &is)
: Forme(is), cote(0)
{
    is >> cote;
}

Carre::~Carre()
{}

void Carre::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w, isActive);
    if( Forme::getFilled() )
        w.fillRectangle(
            getAncre().getX(),
            getAncre().getY(),
            getAncre().getX()+cote,
            getAncre().getY()+cote
        );
    else
        w.drawRectangle(
            getAncre().getX(),
            getAncre().getY(),
            getAncre().getX()+cote,
            getAncre().getY()+cote
        );
}

double Carre::perimetre() const
{return 4*cote;}

void Carre::scale(uint x, uint y)
{
    Point tempP(getAncre());
    bool estDiag = false;
    if(y<getAncre().getY() && x<getAncre().getX()){
        setAncre(x,y);
        estDiag=true;
    }
    else{
        if(y<getAncre().getY())
    
        setAncre(tempP.getX(),y);

        if(x<getAncre().getX())
            setAncre(x,tempP.getY());
    }

    if(estDiag) 
        cote = (tempP.getX()-x > tempP.getY()) ? tempP.getX()-x : tempP.getY()-y;

    else
        cote = ( abs( int(x-getAncre().getX() )) > abs( int(y-getAncre().getY() ))) ?  abs( int(x-getAncre().getX() )) : abs( int(y-getAncre().getY() ));
}

ostream& Carre::ecrire(ostream& os) const
{
    os<<"Carre ";
    Forme::ecrire(os);
    os<<" "<<cote <<" ";
    return os;
}

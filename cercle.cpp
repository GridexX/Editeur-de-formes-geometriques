//Cercle.cpp

#include <iostream>
#ifndef M_PI
   #define M_PI 3.14159265358979323846
#endif
#include <cmath>


using namespace std;

#include "cercle.hpp"

Cercle::Cercle(ulong _couleur, uint _x, uint _y, uint _rayon)
 : Forme(_couleur,_x,_y), rayon(_rayon)
{}

Cercle::Cercle(const Cercle &orig)
 :Forme(orig), rayon(orig.rayon)
{}

Cercle::Cercle(istream &is)
 :Forme(is), rayon(0)
{
    is >> rayon;
}

Cercle::~Cercle()
{}

void Cercle::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w, isActive);
    if( Forme::getFilled() )
        w.fillCircle(
            getAncre().getX(),
            getAncre().getY(),
            getAncre().getX()+rayon*2,
            getAncre().getY()+rayon*2
        );
    else
        w.drawCircle(
            getAncre().getX(),
            getAncre().getY(),
            getAncre().getX()+rayon*2,
            getAncre().getY()+rayon*2
        );
}

double Cercle::perimetre() const
{return 2*M_PI*rayon;}

void Cercle::scale(uint x, uint y)
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
        rayon = (tempP.getX()-x > tempP.getY()) ? (tempP.getX()-x)/2 : (tempP.getY()-y)/2;

    else
        rayon = ( abs( int(x-getAncre().getX()) ) > abs( int(y-getAncre().getY()) )) ?  abs( int(x-getAncre().getX() )/2 ) : abs( int(y-getAncre().getY() )/2 );
}

ostream& Cercle::ecrire(ostream &os) const
{
    os<<"Cercle ";
    Forme::ecrire(os);
    os<<" "<<rayon<<" ";
    return os;
}
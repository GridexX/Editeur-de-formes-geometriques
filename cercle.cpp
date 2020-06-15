//Cercle.cpp

#include <iostream>
#define PI 3.14159265358979323846
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
{return 2*PI*rayon;}

ostream& Cercle::ecrire(ostream &os) const
{
    os<<"Cercle ";
    Forme::ecrire(os);
    os<<" "<<rayon;
    return os;
}
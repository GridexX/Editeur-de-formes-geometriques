//Cercle.cpp

#include <iostream>
#include <cmath>

using namespace std;

#include "Cercle.hpp"

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
    w.drawCircle(
        getAncre().getX(),
        getAncre().getY(),
        getAncre().getX()+rayon,
        getAncre().getY()+rayon,
    );
}

double Cercle::perimetre() const
{return 2*M_PI*rayon;}

ostream& Cercle::ecrire(ostream &os) const
{
    os<<"Cercle";
    Forme::ecrire(os);
    os<<""<<rayon;
    return os;
}
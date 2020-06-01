//Ellipse.cpp

#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

#include "ellipse.hpp"

Ellipse::Ellipse(ulong _couleur, uint _x, uint _y, uint _demiLargeur, uint _demiLongueur)
 : Forme(_couleur,_x,_y), demiLargeur(_demiLargeur), demiLongueur(_demiLongueur)
{}

Ellipse::Ellipse(const Ellipse &orig)
 :Forme(orig), demiLargeur(orig.demiLargeur), demiLongueur(orig.demiLongueur)
{}

Ellipse::Ellipse(istream &is)
 :Forme(is), demiLargeur(0), demiLongueur(0)
{
    is >> demiLargeur >> demiLongueur;
}

Ellipse::~Ellipse()
{}

void Ellipse::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w, isActive);
    w.drawCircle(
        getAncre().getX(),
        getAncre().getY(),
        getAncre().getX()+demiLargeur,
        getAncre().getY()+demiLongueur,
    );
}

double Ellipse::perimetre() const
{return 2*M_PI*sqrt( (demiLargeur*demiLargeur+demiLongueur*demiLongueur) / 2 );}

ostream& Ellipse::ecrire(ostream &os) const
{
    os<<"Ellipse";
    Forme::ecrire(os);
    os<<""<<demiLargeur<<""<<demiLongueur;
    return os;
}
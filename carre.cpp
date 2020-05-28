//Carré.cpp

#include <iostream>

using namespace std;

#include "Carre.hpp"

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
    w.drawRectangle(
        getAncre().getX(),
        getAncre().getY(),
        getAncre().getX()+cote,
        getAncre().getY()+cote
    );
}

double Carre::perimetre() const
{return 4*cote;}

ostream& Carre::ecrire(ostream& os) const
{
    os<<"Carrre";
    Forme::ecrire(os);
    os<<""<<cote;
    return os;
}

//Triangle.cpp


#include <iostream>

using namespace std;

#include "triangle.hpp"

Triangle::Triangle(ulong _couleur, uint _x, uint _y, uint _base, uint _hauteur)
 : Forme(_couleur,_x,_y), base(_base), hauteur(_hauteur)
{}

Triangle::Triangle(const Triangle& orig)
 : Forme(orig),base(orig.base), hauteur(orig.hauteur)
{}

Triangle::Triangle(istream& is)
 : Forme(is),base(0),hauteur(0)
{
 is >> base >> hauteur;
}

Triangle::~Triangle()
{}

void Triangle::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w, isActive);
    w.drawTriangle(
        getAncre().getX(),
        getAncre().getY(),
        getAncre().getX(),
        getAncre().getY()+base,
        getAncre().getX()+hauteur,
        getAncre().getY()+base
    );
}

double Triangle::perimetre() const
{ return base*hauteur/2; }

ostream& Triangle::ecrire(ostream& os) const
{
    os<<"Triangle ";
    Forme::ecrire(os);
    os <<" "<<base<<" "<<hauteur;
    return os;
}

// Rectangle.cpp

#include <iostream>

using namespace std;

#include "Rectangle.hpp"

Rectangle::Rectangle(ulong _couleur, uint _x, uint _y, uint _largeur, uint _hauteur)
 : Forme(_couleur,_x,_y), largeur(_largeur), hauteur(_hauteur)
{}

Rectangle::Rectangle(const Rectangle& orig)
 : Forme(orig),largeur(orig.largeur), hauteur(orig.hauteur)
{}

Rectangle::Rectangle(istream& is)
 : Forme(is),largeur(0),hauteur(0)
{
 is >> largeur >> hauteur;
}

Rectangle::~Rectangle()
{}

void Rectangle::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w, isActive);
    w.drawRectangle(
        getAncre().getX(),
        getAncre().getY(),
        getAncre().getX()+largeur,
        getAncre().getY()+hauteur
    );
}

double Rectangle::perimetre() const
{ return 2*largeur+2*hauteur; }

ostream& Rectangle::ecrire(ostream& os) const
{
    os<<"Rectangle ";
    Forme::ecrire(os);
    os <<" "<<largeur<<" "<<hauteur;
    return os;
}

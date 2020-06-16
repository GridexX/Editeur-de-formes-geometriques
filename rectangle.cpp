// Rectangle.cpp

#include <iostream>

using namespace std;

#include "rectangle.hpp"

Rectangle::Rectangle(ulong _couleur, uint _x, uint _y, uint _largeur, uint _longueur)
 : Forme(_couleur,_x,_y), largeur(_largeur), longueur(_longueur)
{}

Rectangle::Rectangle(const Rectangle& orig)
 : Forme(orig),largeur(orig.largeur), longueur(orig.longueur)
{}

Rectangle::~Rectangle()
{}

void Rectangle::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w, isActive);
    if( Forme::getFilled() )
        w.fillRectangle(
            getAncre().getX(),
            getAncre().getY(),
            getAncre().getX()+longueur,
            getAncre().getY()+largeur
        );
    else
        w.drawRectangle(
            getAncre().getX(),
            getAncre().getY(),
            getAncre().getX()+longueur,
            getAncre().getY()+largeur
        );
}

double Rectangle::perimetre() const
{ return 2*largeur+2*longueur; }

void Rectangle::scale(uint x, uint y)
{
    Point tempP(getAncre());

    if(y<getAncre().getY() && x<getAncre().getX())
        setAncre(x,y);
    else{
        if(y<getAncre().getY())
    
        setAncre(tempP.getX(),y);

        if(x<getAncre().getX())
            setAncre(x,tempP.getY());
    }
    
    longueur = abs(int(x-tempP.getX()));
    largeur = abs(int(y-tempP.getY()));
    
}

Rectangle::Rectangle(istream& is)
 : Forme(is),largeur(0),longueur(0)
{
    is >> largeur >> longueur;
}

ostream& Rectangle::ecrire(ostream& os) const
{
    os<<"Rectangle ";
    Forme::ecrire(os);
    os <<" "<<largeur<<" "<<longueur<<" ";
    return os;
}

//Image.cpp

#include <iostream>

using namespace std;

#include "image.hpp"

void Image::setupImage(string _nomFichier, double ratio, bool _estTransparente)
{
    delete image;
    image = new EZImage(nomFichier.c_str());
    setRatio(ratio);
    setTransparence(_estTransparente);
}


Image::Image(ulong _couleur, uint _x, uint _y, string _nomFichier, double _ratio, bool _estTransparente)
 : Forme(_couleur,_x,_y), nomFichier(_nomFichier), image(nullptr), ratio(_ratio), estTransparente(_estTransparente)
{
    setupImage(nomFichier,ratio,estTransparente);
}

Image::Image(const Image &orig)
 : Forme(orig), nomFichier(""), image(nullptr), ratio(orig.ratio), estTransparente(orig.estTransparente)
{
    setupImage(nomFichier,ratio,estTransparente);
}


Image::~Image()
{}

void Image::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w, isActive);
    image->paint(w,
        getAncre().getX(),
        getAncre().getY());
}

double Image::perimetre() const
{ return image->getWidth()*(image->getHeight())*ratio; }

void Image::scale(uint x, uint y)
{
    
}

Image::Image(istream &is)
    : Forme(is), nomFichier(""), image(nullptr)
{
    is >> nomFichier >> ratio >> estTransparente;
    setupImage(nomFichier,ratio,estTransparente);
}

ostream &Image::ecrire(ostream &os) const{
    os << "Image ";
    Forme::ecrire(os);
    os <<" "<<nomFichier<<" "<< ratio<<" "<<estTransparente<<" ";
    return os;
}

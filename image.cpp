//Image.cpp

#include <iostream>

using namespace std;

#include "image.hpp"

Image::Image(ulong _couleur, uint _x, uint _y, uint _ratio, char *_nomFichier)
 : Forme(_couleur,_x,_y), ratio(_ratio), image(_nomFichier)
{}

Image::Image(const Image &orig)
 : Forme(orig),ratio(orig.ratio),image(orig.image)
{}


Image::Image(istream &is)
 : Forme(is),ratio(0),image(0,0)
{
    /*
    char * str = new char;
    is >> *str >> ratio;
    const char * nomImage = new char;
    *nomImage = *str;
    image(nomImage);
    delete nomImage; */
}

Image::~Image()
{}

void Image::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w, isActive);
    image.scale(ratio);
    image.paint(w,
        getAncre().getX(),
        getAncre().getY());
}

double Image::perimetre() const
{ return image.getWidth()*image.getHeight(); }

ostream &Image::ecrire(ostream &os) const{
    os << "Image ";
    Forme::ecrire(os);
    os << " " << ratio;
    return os;
}
//Image.cpp

#include <iostream>

using namespace std;

#include "image.hpp"

Image::Image(ulong _couleur, uint _x, uint _y, double _ratio, const char *_nomFichier)
 : Forme(_couleur,_x,_y), ratio(_ratio), image(_nomFichier)
{
    pimage = new EZImage(image);
    pimage->setAlpha(estTransparente);
}

Image::Image(const Image &orig)
 : Forme(orig),ratio(orig.ratio),image(orig.image)
{
    pimage = new EZImage(orig.image);
    pimage->setAlpha(orig.estTransparente);
}


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
    pimage->paint(w,
        getAncre().getX(),
        getAncre().getY());
}

double Image::perimetre() const
{ return pimage->getWidth()*(pimage->getHeight()); }

ostream &Image::ecrire(ostream &os) const{
    os << "Image ";
    Forme::ecrire(os);
    os << " " << ratio;
    return os;
}

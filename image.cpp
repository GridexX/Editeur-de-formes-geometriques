//Image.cpp

#include <iostream>

using namespace std;

#include "image.hpp"

Image::Image(ulong _couleur, uint _x, uint _y, uint _largeur, uint _longueur, const char *_nomFichier)
 : Forme(_couleur,_x,_y), largeur(_largeur), longueur(_longueur), nomFichier(_nomFichier)
{}

Image::Image(const Image &orig)
 : Forme(orig),largeur(orig.largeur),longueur(orig.longueur),nomFichier(orig.nomFichier)
{}

Image::Image(istream &is)
 : Forme(is),largeur(0),longueur(0),nomFichier(nullptr)
{
    is >> *nomFichier >> largeur >> longueur;
}

Image::~Image()
{
    delete nomFichier;
}

void Image::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w, isActive);
    (*nomFichier)::EZImage(longueur, largeur);
}
/** @file forme.cpp
 *  @author DUHAMEL Andréa et FOUGEROUSE Arsène
 *  @date Juin 2020
 *  @brief Classe Forme
 */

#include <iostream>

using namespace std;

#include "forme.hpp"

Forme::Forme(ulong _couleur, uint _x, uint _y)
: couleur(_couleur), ancre(_x, _y), animation_couleur(_couleur)
{}

Forme::Forme(const Forme& orig)
 : Forme(orig.couleur,orig.ancre.getX(),orig.ancre.getY())
{}

Forme::Forme(istream& is)
 :couleur(ez_black),ancre(0,0),selected(false)
{
 is >> couleur >> ancre >> epaisseur >> isFilled >> animation >> animation_couleur >> animation_epaisseur;
}

Forme::~Forme()
{}

void Forme::dessiner(EZWindow &w, bool active) const
{
    ancre.dessiner(w,active);
    w.setColor(couleur);
    w.setThick(epaisseur);
}


// fonction non membre
ostream& operator<<(ostream& os, const Forme& f)
{
    f.ecrire(os);
    return os;
}

ostream& Forme::ecrire(ostream& os) const
{
    os<<couleur<<" "<<ancre<<" "<<epaisseur<<" "<<isFilled<<" "<<animation<<" "<<animation_couleur<<" "<<animation_epaisseur;
    return os;
}

// Pour la prochaine fonction, on a besoin de rajouter les déclarations des classes
// correspondantes... C'est l'inévitable défaut de cette conception relativement
// simple.
#include "rectangle.hpp"
#include "carre.hpp"
#include "ellipse.hpp"
#include "cercle.hpp"
#include "image.hpp"
#include "polygone.hpp"

Forme* Forme::charger(istream& is)
{
string mot;
is>>mot;

if(mot=="Rectangle")
       return new Rectangle(is);
else if(mot=="Ellipse")
    return new Ellipse(is);
else if(mot=="Carre")
    return new Carre(is);
else if(mot=="Cercle")
    return new Cercle(is);
else if(mot=="Image")
    return new Image(is);
else if(mot=="Polygone")
    return new Polygone(is);
else
    throw runtime_error("Type de forme inconnue rencontré lors du chargement !");
}

/* ATTENTION : impossible de faire cela car cela comparerait les adresses des chaines et non les valeurs des chaines :
char str[]="Bonjour";

switch (str) // Ici str est un « char * »
{
    case "Bonjour": 
}
*/
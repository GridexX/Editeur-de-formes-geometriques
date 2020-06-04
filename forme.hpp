// Forme.hpp

#ifndef FORME_HPP
#define FORME_HPP

#include "point.hpp"

 
class Forme {
    
private :
     ulong couleur;
     Point ancre;
     bool selected;
     uint epaisseur=1;

public :
    Forme(ulong couleur, uint x, uint y);
    Forme(const Forme& orig);
    Forme(istream& is);
    virtual ~Forme();

    inline ulong getCouleur() const{ return couleur; }
    inline Point getAncre() const { return ancre; }
    inline uint getEpaisseur() const { return epaisseur; }

    inline void setCouleur(ulong _couleur) { couleur=_couleur; }
    inline void setAncre(uint x,uint y) { ancre.setXY(x,y) ; }
    inline void setAncre(uint _taille) {ancre.setTaille(_taille);}
    inline void setEpaisseur(uint _epaisseur) { epaisseur=_epaisseur; }

    inline bool isOver(uint x, uint y) const { return ancre.isOver(x,y); }
    virtual void dessiner(EZWindow& w, bool active=false) const;
    virtual double perimetre() const = 0;
    friend ostream& operator<<(ostream& os, const Forme& f);
    static Forme* charger(istream& is);
    
protected :
    virtual ostream& ecrire(ostream& os) const;
};

#endif
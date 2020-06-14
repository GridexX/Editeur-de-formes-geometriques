// Forme.hpp

#ifndef FORME_HPP
#define FORME_HPP

#include "point.hpp"

 
class Forme {
    
private :
    ulong couleur;
    Point ancre;    
    ulong animation_couleur;
    bool selected;
    uint epaisseur=1;
    uint animation_epaisseur=1;
    bool isFilled=false;
    uint animation=0;
    

public :
    Forme(ulong couleur, uint x, uint y);
    Forme(const Forme& orig);
    Forme(istream& is);
    
    virtual ~Forme();

    inline ulong getCouleur() const{ return couleur; }
    inline ulong getAnimationCouleur() const{ return animation_couleur; }
    inline Point getAncre() const { return ancre; }
    inline uint getEpaisseur() const { return epaisseur; }
    inline uint getAnimationEpaisseur() const { return animation_epaisseur; }
    inline bool getFilled() const { return isFilled; }
    inline uint getAnimation() const { return animation; }

    inline void setCouleur(ulong _couleur) { couleur=_couleur; }
    inline void setAnimationCouleur(ulong _animation_couleur) { animation_couleur=_animation_couleur; }
    inline void setAncre(uint x,uint y) { ancre.setXY(x,y) ; }
    inline void setAncre(uint _taille) {ancre.setTaille(_taille); }
    inline void setEpaisseur(uint _epaisseur) { epaisseur=_epaisseur; }
    inline void setAnimationEpaisseur(uint _animation_epaisseur) { animation_epaisseur=_animation_epaisseur; }
    inline void setFilled(bool _isFilled) { isFilled=_isFilled; }
    inline void setAnimation(uint _animation) { animation=_animation; }

    inline bool isOver(uint x, uint y) const { return ancre.isOver(x,y); }
    virtual void dessiner(EZWindow& w, bool active=false) const;
    virtual double perimetre() const = 0;
    friend ostream& operator<<(ostream& os, const Forme& f);
    static Forme* charger(istream& is);
    
protected :
    virtual ostream& ecrire(ostream& os) const;
};

#endif
// Cercle.hpp

#ifndef Cercle_HPP
#define Cercle_HPP

#include "Forme.hpp"

class Cercle : public Forme {
        private :
            uint rayon;
public :
    Cercle(ulong _couleur, uint _x, uint _y, uint _rayon);
    Cercle(const Cercle &orig);
    Cercle(istream &is);
    ~Cercle();
    inline uint getRayon() const {return rayon;}
    inline void setRayon(uint _rayon) {rayon=_rayon;}
    void dessiner(EZWindow &w, bool isActive) const override;
    double perimetre() const; 
protected :
    virtual ostream& ecrire(ostream& os) const;
}
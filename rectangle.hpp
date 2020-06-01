// Rectangle.hpp

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "forme.hpp"

class Rectangle : public Forme {
      private :
        uint longueur;
        uint largeur;
        

public:
Rectangle(ulong _couleur, uint _x, uint _y, uint _largeur, uint _longueur);
Rectangle(const Rectangle& orig);
Rectangle(istream& is);
~Rectangle();


inline uint getLongueur() const { return longueur; }
inline uint getLargeur() const { return largeur; }

inline void setLongueur(uint _longueur) { longueur = _longueur; }
inline void setLargeur(uint _largeur) { largeur=_largeur; }
void dessiner(EZWindow &w, bool isActive) const override;
double perimetre() const override;

protected:
ostream& ecrire(ostream& os) const override;
};

#endif

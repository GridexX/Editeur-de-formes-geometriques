// Rectangle.hpp

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Forme.hpp"

class Rectangle : public Forme {
      private :
        uint largeur;
        uint hauteur;

public:
Rectangle(ulong _couleur, uint _x, uint _y, uint _largeur, uint _hauteur);
Rectangle(const Rectangle& orig);
Rectangle(istream& is);
~Rectangle();

inline uint getLargeur() const { return largeur; }
inline uint getHauteur() const { return hauteur; }

inline void setLargeur(uint _largeur) { largeur=_largeur; }
inline void setHauteur(uint _hauteur) { hauteur = _hauteur; }
void dessiner(EZWindow &w, bool isActive) const override;
double perimetre() const;

protected:
virtual ostream& ecrire(ostream& os) const;
};

#endif

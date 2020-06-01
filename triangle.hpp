//triangle.hpp

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "forme.hpp"

class Triangle : public Forme {
    private :
        uint base;
        uint hauteur;

    public :
        Triangle(ulong _couleur, uint _x, uint _y, uint _base, uint _hauteur);
        Triangle(const Triangle& orig);
        Triangle(istream& is);
        ~Triangle();

        inline uint getBase() const { return base; }
        inline uint getHauteur() const { return hauteur; }

        inline void setLargeur(uint _base) { base=_base; }
        inline void setHauteur(uint _hauteur) { hauteur = _hauteur; }
        void dessiner(EZWindow &w, bool isActive) const override;
        double perimetre() const override;

        protected:
        ostream& ecrire(ostream& os) const override;
};
#endif
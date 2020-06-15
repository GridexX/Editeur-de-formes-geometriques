// Ellipse.hpp

#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#ifndef M_PI
   #define M_PI 3.14159265358979323846
#endif
#include "forme.hpp"

class Ellipse : public Forme {
        private :
            uint demiLargeur;
            uint demiLongueur;
public :
    Ellipse(ulong _couleur, uint _x, uint _y, uint _demiLargeur, uint _demiHauteur);
    Ellipse(const Ellipse &orig);
    Ellipse(istream &is);
    ~Ellipse();

    inline uint getDemiLargeur() const {return demiLargeur;}
    inline uint getDemiLongueur() const {return demiLongueur;}

    inline void setDemiLargeur(uint _demiLargeur) {demiLargeur=_demiLargeur;}
    inline void setDemiLongueur(uint _demiLongueur) {demiLongueur=_demiLongueur;}
    void dessiner(EZWindow &w, bool isActive) const override;
    double perimetre() const override; 

protected :
    ostream& ecrire(ostream& os) const override;
};
#endif
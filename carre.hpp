
#ifndef CARRE_HPP
#define CARRE_HPP

#include "forme.hpp"




class Carre : public Forme {
    private :
        uint cote;

    public :
        Carre(ulong _couleur, uint _x, uint _y, uint _cote);
        Carre(const Carre& orig);
        Carre(istream &is);
        ~Carre();

        inline uint getCote() const { return cote; }

        inline void setCote(uint _cote) { cote=_cote;}
        void dessiner(EZWindow &w, bool isActive) const override;
        double perimetre() const;

        protected:
        virtual ostream& ecrire(ostream& os) const;
};

#endif
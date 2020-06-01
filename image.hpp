//Image.hpp

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "forme.hpp"

class Image : public Forme {
    private :
        char * nomFichier;
        uint longueur;
        uint largeur;
    
    public :
        Image(ulong _couleur, uint _x, uint _y, uint _largeur, uint _longueur, const char *_nomFichier);
        Image(const Image& orig);
        Image(istream& is);
        ~Image();

        inline uint getLargeur() const { return largeur; }
        inline uint getlongueur() const { return longueur; }

        inline void setLargeur(uint _largeur) { largeur=_largeur; }
        inline void setlongueur(uint _longueur) { longueur = _longueur; }
        void dessiner(EZWindow &w, bool isActive) const override;
        double perimetre() const;

        protected:
        virtual ostream& ecrire(ostream& os) const; 
};

#endif
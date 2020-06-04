//Image.hpp

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "forme.hpp"

class Image : public Forme {
    private :
        EZImage image;
        double ratio;
        int opacite=10; // pourcentage (0=transparent / 100=opaque)
    
    public :
        Image(ulong _couleur, uint _x, uint _y, double _ratio, const char * _nomFichier);
        Image(const Image& orig);
        Image(istream& is);
        ~Image();

        inline uint getRatio() const { return ratio; }
        inline uint getOpacite() const { return opacite; }

        inline void setRatio(uint _ratio) { ratio=_ratio; }
        inline void setOpacite(int _opacite) { opacite=_opacite; }

        void dessiner(EZWindow &w, bool isActive) const override;
        double perimetre() const override; 
        protected:
        virtual ostream& ecrire(ostream& os) const; 
};

#endif
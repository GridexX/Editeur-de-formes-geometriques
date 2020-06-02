//Image.hpp

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "forme.hpp"

class Image : public Forme {
    private :
        EZImage image;
        uint ratio;
        
    
    public :
        Image(ulong _couleur, uint _x, uint _y, uint ratio, char *_nomFichier);
        Image(const Image& orig);
        Image(istream& is);
        ~Image();

        inline uint getRation() const { return ratio; }


        inline void setLargeur(uint _ratio) { ratio=_ratio; }
        void dessiner(EZWindow &w, bool isActive) const override;
        double perimetre() const override; 
        protected:
        virtual ostream& ecrire(ostream& os) const; 
};

#endif
//Image.hpp

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "forme.hpp"

class Image : public Forme {
    private :
        EZImage image, *pimage;
        double ratio;
        bool estTransparente=true;
    
    public :
        Image(ulong _couleur, uint _x, uint _y, double _ratio, const char * _nomFichier);
        Image(const Image& orig);
        Image(istream& is);
        ~Image();

        inline double getRatio() const { return ratio; }
        inline bool getTransparence() const { return estTransparente; }

        inline void setRatio(double _ratio) { ratio=_ratio; delete pimage; pimage=image.scale(ratio); }
        inline void setTransparence(bool _estTransparente) { estTransparente=_estTransparente; pimage->setAlpha(estTransparente); }

        void dessiner(EZWindow &w, bool isActive) const override;
        double perimetre() const override; 
        protected:
        virtual ostream& ecrire(ostream& os) const; 
};

#endif
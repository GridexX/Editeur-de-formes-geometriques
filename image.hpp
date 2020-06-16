//Image.hpp

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "forme.hpp"

class Image : public Forme {
    private :
        string nomFichier;
        EZImage *image;
        double ratio;
        bool estTransparente;

        void setupImage(string _nomFichier, double ratio, bool _estTransparente);
    public :
        Image(ulong _couleur, uint _x, uint _y, string _nomFichier, double _ratio, bool _estTransparente);
        Image(const Image& orig);
        Image(istream& is);
        
        ~Image();

        inline double getRatio() const { return ratio; }
        inline bool getTransparence() const { return estTransparente; }

        inline void setRatio(double _ratio) { ratio=_ratio; delete image; EZImage *img=new EZImage(nomFichier.c_str()); image=img->scale(ratio); }
        inline void setTransparence(bool _estTransparente) { estTransparente=_estTransparente; image->setAlpha(estTransparente); }

        void dessiner(EZWindow &w, bool isActive) const override;
        double perimetre() const override; 
        void scale(uint x, uint y) override;
        protected:
        virtual ostream& ecrire(ostream& os) const; 
};

#endif
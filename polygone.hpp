#ifndef POLYGONE_HPP
#define POLYGONE_HPP
#define PI 3.14159265358979323846
#include <cmath>
#include "forme.hpp"


class Polygone : public Forme {
    private :
        uint rayon;
        uint nbpoints;
        Point ** points;
        bool isRegular;
        

    public :
        Polygone(ulong _couleur, uint _x, uint _y, uint _rayon, uint _nbpoints);
        Polygone(const Polygone& orig);
        Polygone(istream &is);
        ~Polygone();

        inline Point * getPoint(uint numero) {if((numero >= 0) && (numero < nbpoints)) return points[numero];}
        inline uint getNbpoints() { return nbpoints;}
        inline uint getRayon() { return rayon;}
        inline bool getIsRegular() { return isRegular;}
        inline void setIsRegular(bool regular) { isRegular = regular;}
        inline void setRayon(uint _rayon) { rayon=_rayon;}
        void dessiner(EZWindow &w, bool isActive) const override;
        double perimetre() const override;

        void setPoint(Point * p, uint numero);
        friend ostream&  operator<<(ostream&  os, const Polygone& poly);

        protected:
        ostream& ecrire(ostream& os) const override;
};

#endif
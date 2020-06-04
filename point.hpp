// Point.hpp

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

#include "ez-draw++.hpp"

using namespace std;

typedef unsigned int uint;
typedef unsigned long int ulong;

class Point {
    
private :
       //static const uint taille = 3; // Membre de classe !
       uint taille = 3;
       uint x,y; 
       
public :
       Point(uint x, uint y);
       Point(const Point& orig); // Constructeur de copie !
       Point(istream& is);
       ~Point();
       
       inline uint getX() const{ return x; }
       inline uint getY() const { return y; }

       //ajout de setters et getters pour adapter la taille du point en fonction de l'épaisseur de la forme
       inline uint getTaille() const { return taille;}
       inline void setTaille(uint _taille) { taille=_taille; }
       
       inline void setXY(uint _x, uint _y) {x=_x; y=_y;}
       inline bool isOver(uint _x, uint _y) const { return ( x-taille <= _x && _x <= x+taille )&& (y-taille <= _y && _y <= y+taille ); }
       void dessiner(EZWindow& w, bool isActive=false) const;
       friend ostream& operator<<(ostream& os, const Point& p);
       friend istream& operator>>(istream& is, Point& p);
};

// a <= b <= c se traduit en C++ préférentiellement par : (a <= b && b <= c)

#endif

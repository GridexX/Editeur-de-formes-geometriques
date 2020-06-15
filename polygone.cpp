//Polygone.cpp

#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

#include "polygone.hpp"

Polygone::Polygone(ulong _couleur, uint _x, uint _y, uint _rayon, uint _nbpoints)
: Forme(_couleur,_x,_y),rayon(_rayon), nbpoints(_nbpoints), points(nullptr)
{
    points = new Point*[nbpoints];
    for(uint i=0; i<nbpoints; i++)
    {
        points[i] = new Point(getAncre().getX()+rayon*cos(i*(360/nbpoints)*PI/180.0),getAncre().getY()+rayon*sin(i*(360/nbpoints)*PI/180.0));        
    }
}

Polygone::Polygone(const Polygone& orig)
: Forme(orig), rayon(orig.rayon),nbpoints(orig.nbpoints), points(orig.points)
{
    for(uint i = 0; i < nbpoints; i++)
    {
        points[i] = orig.points[i];
    }
}

Polygone::Polygone(istream &is)
: Forme(is), rayon(0)
{
    is >> rayon >> nbpoints;
}

Polygone::~Polygone()
{
    delete[] points;
}

void Polygone::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w, isActive);
    for(uint i = 0; i < nbpoints; i++)
    {
        if(i<nbpoints-1) w.drawLine(points[i]->getX(),points[i]->getY(), points[i+1]->getX(),points[i+1]->getY());
        else w.drawLine(points[i]->getX(),points[i]->getY(), points[0]->getX(),points[0]->getY());
    }        
}

ostream& Polygone::ecrire(ostream& os) const
{
    os<<"Polygone ";
    Forme::ecrire(os);
    os<<" "<<rayon<<" "<<nbpoints;
    return os;
}

double Polygone::perimetre() const
{
    return 2.3;
}

//void setPoint(Point p, uint numero){}

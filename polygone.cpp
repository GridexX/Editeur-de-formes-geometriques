//Polygone.cpp

#include <iostream>
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
 :Forme(is), rayon(0), nbpoints(0), points(nullptr)
{
    uint x,y;
    is >> rayon >> nbpoints;
    points = new Point*[nbpoints];
    for(uint i = 0; i < nbpoints; i++)
    {
        is >> x >> y;
        points[i] = new Point(x,y);
    }
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
        w.drawLine(points[i]->getX(),points[i]->getY(), points[(i+1)%nbpoints]->getX(),points[(i+1)%nbpoints]->getY());
    }        
}

ostream& operator<<(ostream& os, const Polygone& poly)
{
    for(uint i=0; i < poly.nbpoints; ++i)
        os << *poly.points[i] <<" ";
    return os;
}

ostream& Polygone::ecrire(ostream& os) const
{
    os<<"Polygone ";
    Forme::ecrire(os);
    os<<" "<<rayon<<" "<<nbpoints<<" ";
    os << *this;
    return os;
}

double Polygone::perimetre() const
{
    double perimetre=0;
    for(uint i=0; i<nbpoints; i++)
    {
        perimetre += sqrt(pow(abs(int(points[i]->getX()-points[(i+1)%nbpoints]->getX())),2) + pow(abs(int(points[i]->getY()-points[(i+1)%nbpoints]->getY())),2));        
    }
    return perimetre;
}

void Polygone::setPoint(Point * p, uint numero)
{
    points[numero]=p;
}



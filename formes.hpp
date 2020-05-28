// Formes.hpp

#ifndef FORMES_HPP
#define FORMES_HPP

#include "Forme.hpp"

typedef unsigned int uint;

class Formes {
  private:
  uint maxformes;
  uint nbformes;
  Forme** formes;
public:
  Formes(uint taille=200);
  ~Formes();
  void ajouter(Forme *forme);
  Forme *isOver(uint _x,uint _y);
  void dessiner(EZWindow& w) const;
  friend ostream&  operator<<(ostream&  os, const Formes& formes);
  void sauver(ostream& os) const;
  void charger(istream& is);
};
#endif
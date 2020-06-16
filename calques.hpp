//calques.hpp
//contient un tableau de formes

#ifndef CALQUE_HPP
#define CALQUE_HPP

#include <vector>
#include <utility>
#include <fstream>

#include "formes.hpp"

typedef std::vector< std::pair<Formes *,bool>> vecFormes;
typedef std::pair<Formes *, bool> calqAndBool;

class Calques { //herite de formes
    private :
        vecFormes listeCalque;
        uint maxcalques;
        uint nbcalques=0;
        uint calqueSelec=0;
    
    public :
        Calques(size_t taille=20);
        
        ~Calques();

        inline uint getCalqueSelec() const { return calqueSelec; }
        inline uint getNbCalques() const { return nbcalques; }
        inline bool getCalqueVisible(uint numCalque) const { return listeCalque[numCalque].second; }
        inline uint getNbForme(uint numCalque) const { return listeCalque[numCalque].first->getFormes();}
        
        inline void setCalqueSelec(uint _calqueSelec) { if(_calqueSelec>=0 && _calqueSelec<nbcalques) calqueSelec=_calqueSelec; }
        inline void setCalqueVisible(bool _isVisible) { listeCalque[calqueSelec].second = _isVisible; }

        void creerCalque();
        void creerCalque(uint _nbcalques);
        void supprimerCalque(uint numCalque);
        
        void monterCalque();
        void descendreCalque();
        void ajouterForme(Forme *forme);
        void supprimerForme(Forme * forme);
        void fusionner();
        void swapFormeCalque(Forme * forme, uint dest);

        void dessiner(EZWindow &w) const;

        Forme *isOver(uint _x, uint y) const;

        friend ostream& operator<<(ostream& os, const Calques & calques);
        void sauverCalque(ostream& os) const;
        void chargerCalque(istream& is) const;
        void sauver(ostream& os) const;
        void charger(istream& is);
        
}; 

#endif
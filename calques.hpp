//calques.hpp
//contient un tableau de formes

#ifndef CALQUE_HPP
#define CALQUE_HPP

#include <vector>
#include <utility>

#include "formes.hpp"

typedef std::vector< std::pair<Formes *,bool>> vecFormes;
typedef std::pair<Formes *, bool> calqAndBool;

class Calques { //herite de formes
    private :
        vecFormes listeCalque;
        int maxcalques;
        int nbcalques=0;
        int calqueSelec=0;
    
    public :
        Calques(size_t taille=20);
        
        ~Calques();

        inline int getCalqueSelec() { return calqueSelec; }
        inline int getNbCalques() { return nbcalques; }
        inline bool getCalqueVisible() { return listeCalque[calqueSelec].second; }
        inline bool getCalqueVisible(int numCalque) { return listeCalque[numCalque].second; }
        inline int getNbForme(int numCalque) { return listeCalque[numCalque].first->getFormes();}

        inline void setCalqueSelec(int _calqueSelec) { if(_calqueSelec>=0 && _calqueSelec<nbcalques) calqueSelec=_calqueSelec; }
        inline void setCalqueVisible(bool _isVisible) { listeCalque[calqueSelec].second = _isVisible; }

        void creerCalque();
        void creerCalque(int _nbcalques);
        void supprimerCalque();
        void monterCalque();
        void descendreCalque();
        void ajouterForme(Forme *forme);
        void supprimerForme(Forme * forme);
        void fusionner();
        void swapFormeCalque(Forme * forme, uint dest);

        void dessiner(EZWindow &w) const;

        Forme *isOver(uint _x, uint y);

        friend ostream& operator<<(ostream& os, const Calques & calques);
        void sauver(ostream& os) const;
        void charger(istream& is);
        
}; 

#endif
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
        size_t maxcalques;
        uint nbcalques=0;
        uint calqueSelec=0;
    
    public :
        Calques(size_t taille=20);
        
        ~Calques();

        inline uint getCalqueSelect() { return calqueSelec; }
        inline uint getNbCalques() { return nbcalques; }
        inline bool getCalqueVisible() { return listeCalque[calqueSelec].second; }
        inline bool getCalqueVisible(uint numCalque) { return listeCalque[numCalque].second; }
        inline uint getNbForme(uint numCalque) { return listeCalque[numCalque].first->getFormes();}

        inline void setCalqueSelec(uint _calqueSelec) { if(_calqueSelec>=0 && _calqueSelec<nbcalques) calqueSelec=_calqueSelec; }
        inline void setCalqueVisible(bool _isVisible) { listeCalque[calqueSelec].second = _isVisible; }

        void creerCalque();
        void creerCalque(uint _nbcalques);
        void supprimerCalque();
        void monterCalque();
        void descendreCalque();
        void ajouterForme(Forme *forme);
        void supprimerForme(Forme * forme); // A voir si besoin
        void swapFormeCalque(Forme * forme, uint dest);

        void dessiner(EZWindow &w) const;

        Forme *isOver(uint _x, uint y);

        friend ostream& operator<<(ostream& os, const Calques & calques);
        void sauver(ostream& os) const;
        void charger(istream& is);
        
}; 

#endif
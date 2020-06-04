//calques.hpp
//contient un tableau de formes

#ifndef CALQUE_HPP
#define CALQUE_HPP

#include <vector>
#include <utility>

#include "formes.hpp"

class Calques {
    private :
        std::vector< std::pair<Formes *,bool *>> listeCalque;
        size_t maxcalques;
        uint nbcalques;
    
    public :
        Calques(size_t taille=20);
        
        ~Calques();

        Forme getFormes() const;

        void ajouter(Formes *calque);
        void supprimer(uint index);
        void monterCalque(uint index);
        void descendreCalque(uint index);
        void dessiner(EZWindow &w) const;

        Forme *isOver(uint _x, uint y);
        
}; 

#endif
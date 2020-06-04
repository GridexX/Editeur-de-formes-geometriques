//calques.hpp
//contient un tableau de formes

#ifndef CALQUE_HPP
#define CALQUE_HPP

#include "formes.hpp"

class Calques {
    private :
        Formes * listeCalque;
        bool isActive; 
        uint maxcalques;
        uint nbcalques;
    
    public :
        Calques(uint taille=200);
        
        ~Calques();

        Forme getFormes() const;

        void ajouter(Formes *calque);
        void dessiner(EZWindow &w) const;
        
}; 

#endif
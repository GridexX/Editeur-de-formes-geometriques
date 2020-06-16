
#ifndef CARRE_HPP
#define CARRE_HPP

#include "forme.hpp"
#include <cmath>



class Carre : public Forme {
    private :
        uint cote; ///< Le cote (Représente la longueur des cotés du carré en pixel)

    public :
        /** Constructeur de la clase Carre.
        * @param _couleur correspond à la couleur du carre (donnée de la classe Forme). 
        * @param _y correspond a la coordonnée y du point d'ancrage du carre (donnée de la classe Forme).
        * @param _x correspond a la coordonnée x du point d'ancrage du carre (donnée de la classe Forme).
        * @param _cote La longueur des cotés du carré . 
        */
        Carre(ulong _couleur, uint _x, uint _y, uint _cote);
        /** Constructeur de copie de la clase Carre.
        * @param orig Le carré d'origine qui va être copié.
        */
        Carre(const Carre& orig);
        /** Constructeur via le flux d'entrée de la clase Carre.
        * @param is le flux d'entrée sur lequel va être lu la chaine de caractères.
        */
        Carre(istream &is);
        /** Destructeur de la classe Carre.
        */
        ~Carre();

        /** Fonction getter de la classe Carre.
        * @return La longueur des cotés du carré.
        */
        inline uint getCote() const { return cote; }

        /** Fonction setter de la classe Carre.
        * @param _cote La nouvelle longueur des cotés du carré.
        */
        inline void setCote(uint _cote) { cote=_cote;}

        /** Fonction dessiner de la classe Carre.
        * @param fenetre Une réference sur la fenêtre EZwindow.
        * @param isActive Booléen pour afficher le carré dans la fenêtre.
        */
        void dessiner(EZWindow &w, bool isActive) const override;

        /** Fonction perimetre de la classe Carre.
        * @return Le périmètre du Carré.
        */
        double perimetre() const override;
        void scale(uint x, uint y) override;

        protected:

        /** Fonction ecrire de la classe Carre.
        * @param os Le flux de sortie sur lequel afficher les informations.
        * @return Le flux de sortie modifié contenant les informations sur les données membres de la classe.
        */
        ostream& ecrire(ostream& os) const override;
};

#endif
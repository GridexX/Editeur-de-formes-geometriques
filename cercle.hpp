

#ifndef Cercle_HPP
#define Cercle_HPP

#include "Forme.hpp"

/** La classe cercle **/

class Cercle : public Forme {
        private :
            uint rayon; ///< Le rayon (Représente la moitié du diamètre du cercle en pixel)
public :
    /** Constructeur de la classe carré.
    * @param couleur correspond à la couleur du cercle (donnée de la classe Forme). 
    * @param y @param x correspond aux coordonnées x et y du point d'ancrage du cercle (donnée de la classe Forme).
    * @param rayon Le rayon du cercle. 
    */
    Cercle(ulong _couleur, uint _x, uint _y, uint _rayon);
    
    /** Constructeur de copie de la classe cercle.
    * @param orig Le cercle d'origine qui va être copié.
    */
    Cercle(const Cercle &orig);

    /** Constructeur via le flux d'entrée de la classe cercle.
    * @param is le flux d'entrée sur lequel va être lu la chaine de caractères.
    */
    Cercle(istream &is);

    /** Destructeur de la classe Cercle.
    */
    ~Cercle();

    /** Fonction getter de la classe Cercle.
    * @return Le rayon du cercle.
    */
    inline uint getRayon() const {return rayon;}

    /** Fonction setter de la classe Cercle.
    * @param rayon Le nouveau rayon du cercle.
    */
    inline void setRayon(uint _rayon) {rayon=_rayon;}

    /** Fonction dessiner de la classe Cercle.
    * @param fenetre Une réference sur la fenêtre EZwindow.
    * @param estActivé Booléen pour afficher le cercle dans la fenêtre.
    */
    void dessiner(EZWindow &w, bool isActive) const override;
    
    /** Fonction perimetre de la classe Cercle.
    * @return Le périmètre du Cercle.
    */
    double perimetre() const; 

protected :
    /** Fonction ecrire de la classe Cercle.
    * @param os Le flux de sortie sur lequel afficher les informations.
    * @return Le flux de sortie modifié contenant les informations sur les données membres de la classe.
    */
    virtual ostream& ecrire(ostream& os) const;
};

#endif
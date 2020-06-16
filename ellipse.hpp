// Ellipse.hpp

#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "forme.hpp"

class Ellipse : public Forme {
        private :
            uint demiLargeur;   ///< La demi largeur (Représente la longueur de la demi largeur de l'ellipse en pixel)
            uint demiLongueur;  ///< La demi longueur (Représente la longueur de la demi longueur de l'ellipse en pixel)
public :
    /** Constructeur de la classe Ellipse.
    * @param _couleur correspond à la couleur de l'ellipse (donnée de la classe Forme). 
    * @param _y correspond a la coordonnée y du point d'ancrage de l'ellipse (donnée de la classe Forme).
    * @param _x correspond a la coordonnée x du point d'ancrage de l'ellipse (donnée de la classe Forme).
    * @param _demiLargeur La longueur de la demi largeur. 
    * @param _demiLongueur La longueur de la demi longueur. 
    */
    Ellipse(ulong _couleur, uint _x, uint _y, uint _demiLargeur, uint _demiHauteur);

    /** Constructeur de copie de la classe Ellipse.
    * @param orig L'ellipse d'origine qui va être copié.
    */
    Ellipse(const Ellipse &orig);

    /** Constructeur via le flux d'entrée de la classe Ellipse.
    * @param is le flux d'entrée sur lequel va être lu la chaine de caractères.
    */
    Ellipse(istream &is);

    /** Destructeur de la classe Ellipse.
    */
    ~Ellipse();

    /** Fonction getter de la classe Ellipse.
    * @return La longueur de la demi largeur. 
    */
    inline uint getDemiLargeur() const {return demiLargeur;}

    /** Fonction getter de la classe Ellipse.
    * @return La longueur de la demi longueur. .
    */
    inline uint getDemiLongueur() const {return demiLongueur;}

    /** Fonction setter de la classe Ellipse.
    * @param _demiLargeur La nouvelle demi largeur de l'ellipse.
    */
    inline void setDemiLargeur(uint _demiLargeur) {demiLargeur=_demiLargeur;}

    /** Fonction setter de la classe Ellipse.
    * @param _demiLongueur La nouvelle demi longueur de l'ellipse.
    */
    inline void setDemiLongueur(uint _demiLongueur) {demiLongueur=_demiLongueur;}

    /** Fonction dessiner de la classe Ellipse.
    * @param fenetre Une réference sur la fenêtre EZwindow.
    * @param isActive Booléen pour afficher l'ellipse dans la fenêtre.
    */
    void dessiner(EZWindow &w, bool isActive) const override;

    /** Fonction perimetre de la classe Ellipse.
    * @return Le périmètre de l'Ellipse.
    */
    double perimetre() const override; 

protected :

    /** Fonction ecrire de la classe Ellipse.
    * @param os Le flux de sortie sur lequel afficher les informations.
    * @return Le flux de sortie modifié contenant les informations sur les données membres de la classe.
    */
    ostream& ecrire(ostream& os) const override;
};
#endif
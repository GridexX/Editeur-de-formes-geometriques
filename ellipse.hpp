/**
 * @file ellipse.hpp
 * @author DUHAMEL Andréa et FOUGEROUSE Arsène
 * @date Juin 2020
 * @brief Classe Ellipse (classe fille de la classe Forme)
 */ 

#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "forme.hpp"

class Ellipse : public Forme {
        private :
            uint demiLargeur;   ///< La demi largeur (Représente la longueur de la demi largeur de l'ellipse en pixel)
            uint demiLongueur;  ///< La demi longueur (Représente la longueur de la demi longueur de l'ellipse en pixel)
public :
    /** 
    * @fn Ellipse(ulong _couleur, uint _x, uint _y, uint _demiLargeur, uint _demiHauteur)
    * @brief Constructeur de la classe Ellipse.
    * @param _couleur : correspond à la couleur de l'ellipse (donnée de la classe Forme). 
    * @param _y : correspond a la coordonnée y du point d'ancrage de l'ellipse (donnée de la classe Forme).
    * @param _x : correspond a la coordonnée x du point d'ancrage de l'ellipse (donnée de la classe Forme).
    * @param _demiLargeur : La longueur de la demi largeur. 
    * @param _demiLongueur : La longueur de la demi longueur. 
    */
    Ellipse(ulong _couleur, uint _x, uint _y, uint _demiLargeur, uint _demiHauteur);

    /** 
    * @fn Ellipse(const Ellipse &orig)
    * @brief Constructeur de copie de la classe Ellipse.
    * @param orig : L'ellipse d'origine qui va être copié.
    */
    Ellipse(const Ellipse &orig);

    /** 
    * @fn Ellipse(istream &is)
    * @brief Constructeur via le flux d'entrée de la classe Ellipse.
    * @param is : le flux d'entrée sur lequel va être lu la chaine de caractères.
    */
    Ellipse(istream &is);

    /** 
    * @fn ~Ellipse()
    * @brief Destructeur de la classe Ellipse.
    */
    ~Ellipse();

    /** 
    * @fn uint getDemiLargeur() const
    * @brief Fonction getter de la classe Ellipse.
    * @return La longueur de la demi largeur. 
    */
    inline uint getDemiLargeur() const {return demiLargeur;}

    /** 
    * @fn uint getDemiLongueur() const
    * @brief Fonction getter de la classe Ellipse.
    * @return La longueur de la demi longueur. .
    */
    inline uint getDemiLongueur() const {return demiLongueur;}

    /** 
    * @fn void setDemiLargeur(uint _demiLargeur)
    * @brief Fonction setter de la classe Ellipse.
    * @param _demiLargeur : La nouvelle demi largeur de l'ellipse.
    */
    inline void setDemiLargeur(uint _demiLargeur) {demiLargeur=_demiLargeur;}

    /** 
    * @fn void setDemiLongueur(uint _demiLongueur)
    * @brief Fonction setter de la classe Ellipse.
    * @param _demiLongueur : La nouvelle demi longueur de l'ellipse.
    */
    inline void setDemiLongueur(uint _demiLongueur) {demiLongueur=_demiLongueur;}

    /** 
    * @fn void dessiner(EZWindow &w, bool isActive) const override
    * @brief Fonction dessiner de la classe Ellipse.
    * @param fenetre : Une réference sur la fenêtre EZwindow.
    * @param isActive : Booléen pour afficher l'ellipse dans la fenêtre.
    */
    void dessiner(EZWindow &w, bool isActive) const override;

    /** 
    * @fn double perimetre() const override
    * @brief Fonction perimetre de la classe Ellipse.
    * @return Le périmètre de l'Ellipse.
    */
    double perimetre() const override; 

    /** 
    * @fn  void scale(uint x, uint y) override
    * @brief Ajuste le rayon de l'ellipse au coordonnés entrées en paramètres
    * @param x : coordonnée en abcisse. 
    * @param y : coordonnée en ordonnée. 
    */
    void scale(uint x, uint y) override;

protected :

    /** 
    * @fn ostream& ecrire(ostream& os) const override
    * @brief Fonction ecrire de la classe Ellipse.
    * @param os : Le flux de sortie sur lequel afficher les informations.
    * @return Le flux de sortie modifié contenant les informations sur les données membres de la classe.
    */
    ostream& ecrire(ostream& os) const override;
};
#endif
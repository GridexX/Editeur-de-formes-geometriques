/** @file cercle.hpp
 *  @author DUHAMEL Andréa et FOUGEROUSE Arsène
 *  @date Juin 2020
 *  @brief Classe Cercle
 */

#ifndef CERCLE_HPP
#define CERCLE_HPP
#ifndef M_PI
   #define M_PI 3.14159265358979323846
#endif
#include "forme.hpp"


class Cercle : public Forme {
        private :
            uint rayon; ///< Le rayon (Représente la moitié du diamètre du cercle en pixel)

public :
    /** 
     * @fn Cercle(ulong _couleur, uint _x, uint _y, uint _rayon)
     * @brief Le constructeur de la classe Cercle.
    * @param _couleur correspond à la couleur du cercle (donnée de la classe Forme). 
    * @param _y correspond a la coordonnée y du point d'ancrage du cercle (donnée de la classe Forme).
    * @param _x correspond a la coordonnée x du point d'ancrage du cercle (donnée de la classe Forme).
    * @param _rayon Le rayon du cercle. 
    */
    Cercle(ulong _couleur, uint _x, uint _y, uint _rayon);
    
    /** 
     * @fn Cercle(const Cercle &orig)
     * @brief Constructeur de copie de la classe Cercle.
    * @param orig Le cercle d'origine qui va être copié.
    */
    Cercle(const Cercle &orig);

    /** 
     * @fn Cercle(istream &is)
     * @brief Constructeur via le flux d'entrée de la classe Cercle.
    * @param is le flux d'entrée sur lequel va être lu la chaine de caractères.
    */
    Cercle(istream &is);

    /** 
     * @fn ~Cercle()
     * @brief Destructeur de la classe Cercle.
    */
    ~Cercle();

    /** 
     * @fn inline uint getRayon() const {return rayon;}
     * @brief Fonction getter de la classe Cercle.
    * @return Le rayon du cercle.
    */
    inline uint getRayon() const {return rayon;}

    /** 
     * @fn inline void setRayon(uint _rayon) {rayon=_rayon;}
     * @brief Fonction setter de la classe Cercle.
    * @param _rayon Le nouveau rayon du cercle.
    */
    inline void setRayon(uint _rayon) {rayon=_rayon;}

    /** 
     * @fn void dessiner(EZWindow &w, bool isActive) const override
     * @brief Fonction dessiner de la classe Cercle.
    * @param fenetre Une réference sur la fenêtre EZwindow.
    * @param isActive Booléen pour afficher le cercle dans la fenêtre.
    */
    void dessiner(EZWindow &w, bool isActive) const override;
    
    /** 
     * @fn double perimetre() const override
     * @brief Fonction perimetre de la classe Cercle.
    * @return Le périmètre du Cercle.
    */
    double perimetre() const override; 

    /** 
     * @fn void scale(uint x, uint y) override
     * @brief Ajuste la taille de lu cercle en fonction des coordonnées passées en paramètres.
     * @param x : coordonnée en abcisse. 
     * @param y : coordonnée en ordonnée. 
     */
    void scale(uint x, uint y) override;

protected :
    /**
    * @fn ostream& ecrire(ostream& os) const override
    * @brief Fonction ecrire de la classe Cercle.
    * @param os Le flux de sortie sur lequel afficher les informations.
    * @return Le flux de sortie modifié contenant les informations sur les données membres de la classe.
    */
    ostream& ecrire(ostream& os) const override;
};

#endif
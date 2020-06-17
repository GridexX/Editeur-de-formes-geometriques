/**
 * @file rectangle.hpp
 * @author DUHAMEL Andréa et FOUGEROUSE Arsène
 * @date Juin 2020
 * @brief Classe Rectangle (classe fille de la classe Forme)
 */ 

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "forme.hpp"

class Rectangle : public Forme {
      private :
        uint largeur;   ///< La largeur (Représente la longueur de la largeur du rectangle en pixel)
        uint longueur;  ///< La longueur (Représente la longueur de la longueur du rectangle en pixel)
        

public:
/** 
* @fn Rectangle(ulong _couleur, uint _x, uint _y, uint _largeur, uint _longueur)
* @brief Constructeur de la classe Rectangle.
* @param _couleur : correspond à la couleur du rectangle (donnée de la classe Forme). 
* @param _y : correspond a la coordonnée y du point d'ancrage du rectangle (donnée de la classe Forme).
* @param _x : correspond a la coordonnée x du point d'ancrage du rectangle (donnée de la classe Forme).
* @param _largeur : La longueur de la demi largeur. 
* @param _longueur : La longueur de la demi longueur. 
*/
Rectangle(ulong _couleur, uint _x, uint _y, uint _largeur, uint _longueur);

/** 
* @fn Rectangle(const Rectangle& orig)
* @brief Constructeur de copie de la classe Rectangle.
* @param orig : L'rectangle d'origine qui va être copié.
*/
Rectangle(const Rectangle& orig);

/** @fn Rectangle(istream& is)
* @brief Constructeur via le flux d'entrée de la classe Rectangle.
* @param is : le flux d'entrée sur lequel va être lu la chaine de caractères.
*/
Rectangle(istream& is);

/** 
* @fn ~Rectangle()
* @brief Destructeur de la classe Rectangle.
*/
~Rectangle();

/** @fn uint getLongueur() const
* @brief Fonction getter de la classe Rectangle.
* @return La longueur de la demi longueur. 
*/
inline uint getLongueur() const { return longueur; }

/** 
* @fn uint getLargeur() const
* @brief Fonction getter de la classe Rectangle.
* @return La longueur de la demi largeur.
*/
inline uint getLargeur() const { return largeur; }


/** 
* @fn void setLongueur(uint _longueur)
* @brief Fonction setter de la classe Rectangle.
* @param _largeur : La nouvelle longueur du rectangle.
*/
inline void setLongueur(uint _longueur) { longueur = _longueur; }

/** 
* @fn void setLargeur(uint _largeur)
* @brief Fonction setter de la classe Rectangle.
* @param _longueur : La nouvelle largeur du rectangle.
*/
inline void setLargeur(uint _largeur) { largeur=_largeur; }

/** 
* @fn void dessiner(EZWindow &w, bool isActive) const override
* @brief Fonction dessiner de la classe Rectangle.
* @param fenetre : Une réference sur la fenêtre EZwindow.
* @param estActivé : Booléen pour afficher l'rectangle dans la fenêtre.
*/
void dessiner(EZWindow &w, bool isActive) const override;

/** 
* @fn double perimetre() const override
* @brief Fonction perimetre de la classe Rectangle.
* @return Le périmètre du Rectangle.
*/
double perimetre() const override;

/** 
* @fn  void scale(uint x, uint y) override
* @brief Ajuste la taille de l'image en fonction des coordonnées passées en paramètres.
* @param x : coordonnée en abcisse. 
* @param y : coordonnée en ordonnée. 
*/        
void scale(uint x, uint y) override;

protected:

/** 
* @fn
* @brief Fonction ecrire de la classe Rectangle.
* @param os Le flux de sortie sur lequel afficher les informations.
* @return Le flux de sortie modifié contenant les informations sur les données membres de la classe.
*/
ostream& ecrire(ostream& os) const override;
};

#endif

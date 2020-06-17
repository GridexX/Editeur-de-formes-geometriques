/**
 * @file point.hpp
 * @author DUHAMEL Andréa et FOUGEROUSE Arsène
 * @date Juin 2020
 * @brief Classe Point
 */ 

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

#include "ez-draw++.hpp"

using namespace std;

typedef unsigned int uint; 
typedef unsigned long int ulong;

class Point {
    
private :
       uint taille = 3; ///< La marge autour du point pour cliquer dessus
       uint x; ///< Coordonné x du point
       uint y; ///< Coordonné y du point
       
public :
       /** 
       * @fn Point(uint x, uint y)
       * @brief Constructeur de la classe Point.
	* @param _y : correspond a la coordonnée y du Point.
	* @param _x : correspond a la coordonnée x du Point.
	*/	
       Point(uint x, uint y);

       /** 
       * @fn Point(uint x, uint y)
       * @brief Constructeur de la classe Point.
	* @param orig : Le point d'origine qui va être copié.
	*/	
       Point(const Point& orig); 

       /** 
       * @fn Point(istream& is)
       * @brief Constructeur via le flux d'entrée de la classe Point.
	* @param is : le flux d'entrée sur lequel va être lu la chaine de caractères.
	*/
       Point(istream& is);

       /** 
       * @fn ~Point()
       * @brief Destructeur de la classe Point.
	*/	
       ~Point();
       
       /** 
        * @fn uint getX()
        * @brief Fonction getter de la classe Point.
        * @return la coordonnée d'abcisse du point.
        */  
       inline uint getX() const{ return x; }

       /** 
        * @fn uint getY()
        * @brief Fonction getter de la classe Point.
        * @return la coordonnée d'ordonnée du point.
        */ 
       inline uint getY() const { return y; }

       /** 
        * @fn uint getTaille()
        * @brief Fonction getter de la classe Point.
        * @return la marge (attribut taille) du point.
        */ 
       inline uint getTaille() const { return taille;}
       
       /** 
        * @fn void setTaille(uint _taille)
        * @brief Fonction setter de la classe Point.
        * @param _taille : La marge (attribut taille) du point.
        */ 	
       inline void setTaille(uint _taille) { taille=_taille; }
       
       /** 
        * @fn void setXY(uint _x, uint _y)
        * @brief Fonction setter de la classe Point.
        * @param _x : Nouvelle valeur d'abcisse du Point.
        * @param _y : Nouvelle valeur d'ordonée du Point.
        */ 
       inline void setXY(uint _x, uint _y) {x=_x; y=_y;}

       /** 
        * @fn bool isOver(uint _x, uint _y) const
        * @brief Fonction qui observe si les coordonnées passées en paramètres sont au dessus du Point.
        * @param _x : La valeur d'abcisse à observer.
        * @param _y : La valeur d'ordonée à observer.
        */ 
       inline bool isOver(uint _x, uint _y) const { return ( x-taille <= _x && _x <= x+taille )&& (y-taille <= _y && _y <= y+taille ); }

       /** 
        * @fn void dessiner(EZWindow &w, bool isActive) const 
        * @brief Fonction dessiner de la classe Point.
        * @param fenetre : Une réference sur la fenêtre EZwindow.
        * @param isActive : Booléen pour afficher le point dans la fenêtre.
        */
       void dessiner(EZWindow& w, bool isActive=false) const;

       /** 
        * @fn friend ostream& operator<<(ostream& os, const Point& p)
        * @brief Operateur << qui ecrit les données du Point sur un flux de sortie.
        * @param os : Le flux de sortie.
        * @param p : Le point dont on récupère les attributs.
        */
       friend ostream& operator<<(ostream& os, const Point& p);

       /** 
        * @fn friend istream& operator>>(istream& is, Point& p)
        * @brief Operateur >> qui lit les données du Point sur un flux d'entrée.
        * @param is : Le flux d'entrée.
        * @param p : Le point sur lequel on applique les attributs.
        */
       friend istream& operator>>(istream& is, Point& p);
       
       /** 
        * @fn uint getX()
        * @brief Fonction getter de la classe Point. (Pour permettre aux autres classes d'acceder au getter)
        * @return la coordonnée d'abcisse du point.
        */ 
       friend uint getY();

       /** 
        * @fn uint getX()
        * @brief Fonction getter de la classe Point. (Pour permettre aux autres classes d'acceder au getter)
        * @return la coordonnée d'ordonnée du point.
        */ 
       friend uint getX();
};

#endif

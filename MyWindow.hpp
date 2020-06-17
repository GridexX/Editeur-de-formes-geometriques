/**
 * @file MyWindow.hpp
 * @author DUHAMEL Andréa et FOUGEROUSE Arsène
 * @date Juin 2020
 * @brief Classe MyWindow
 */ 

#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP

#include "calques.hpp"

class MyWindow : public EZWindow {
  Calques calques; 
  Forme  *pforme; ///< Le pointeur sur forme qui pointe la forme sélectionné
  uint mouseX; ///< La variable qui contient la coordonnée d'abcisse de la souris
  uint mouseY; ///< La variable qui contient la coordonnée d'ordonnée de la souris
  const uint marge=0;
  int point;
  uint ancre_x; ///< La variable qui contient la coordonnée d'abcisse d'une ancre
  uint ancre_y; ///< La variable qui contient la coordonnée d'ordonnée d'une ancre
  int diff_x; ///< La variable qui contient la distance en abcisse entre l'ancre_x stocké et l'ancre de la forme selectionnée
  int diff_y; ///< La variable qui contient la distance en ordonnée entre l'ancre_y stocké et l'ancre de la forme selectionnée

 public:
 /** 
* @fn MyWindow(int w, int h,const char *name)
* @brief Constructeur de la classe MyWindow.
* @param w : largeur de la fenêtre. 
* @param h : hauteur de la fenêtre.
* @param name : nom de la fenêtre. 
*/
  MyWindow(int w, int h,const char *name);

  /** 
  * @fn ~MyWindow()
  * @brief Destructeur de la classe MyWindow.
  */
  ~MyWindow();

  /** 
  * @fn void expose()
  * @brief Recharge la fenêtre.
  */
  void expose();

  /** 
  * @fn void keyPress(EZKeySym keysym)
  * @brief S'active lors de l'appuie sur une touche du clavier.
  * @param keysym : touche appuyée.
  */
  void keyPress(EZKeySym keysym);

  /** 
  * @fn void buttonPress(int mouse_x,int mouse_y,int button)
  * @brief S'active lors de l'appuie sur une bonton de la souris.
  * @param mouse_x : coordonnée en abcisse de la souris.
  * @param mouse_y : coordonnée en ordonée de la souris.
  * @param button : bouton appuyée.
  */
  void buttonPress(int mouse_x,int mouse_y,int button);

  /** 
  * @fn void motionNotify(int mouse_x,int mouse_y,int button)
  * @brief S'active lors du déplacement de la souris.
  * @param mouse_x : coordonnée en abcisse de la souris.
  * @param mouse_y : coordonnée en ordonée de la souris.
  * @param button : bouton appuyée.
  */
  void motionNotify(int mouse_x,int mouse_y,int button);

  /** 
  * @fn void buttonRelease(int mouse_x,int mouse_y,int button)
  * @brief S'active lors du relachement d'un bonton de la souris.
  * @param mouse_x : coordonnée en abcisse de la souris.
  * @param mouse_y : coordonnée en ordonée de la souris.
  * @param button : bouton relaché.
  */
  void buttonRelease(int mouse_x,int mouse_y,int button);
  
  /** 
  * @fn void setXY(uint _x, uint _y)
  * @brief Fonction setter de la classe MyWindow.
  * @param _x : Nouvelle valeur d'abcisse de mouseX.
  * @param _y : Nouvelle valeur d'ordonée de mouseY.
  */ 
  inline void setXY(int x, int y) { mouseX=x; mouseY=y; }

  /** 
  * @fn bool isMouseWindow(uint x,uint y) const
  * @brief Détecte si les coordonnées passées en paramètre sont dans la fenêtre.
  * @param x : coordonnée d'abcisse à comparer.
  * @param y : coordonnée d'ordonnée à comparer.
  * @return renvoie false si les coordonnées ne sont pas dans la fenêtre et true si elles le sont.
  */
  inline bool isMouseWindow(uint x,uint y) const { return x>=marge && x<=getWidth()-marge && y>marge && y<getHeight()-marge; }

  void creerForme(string forme, bool coordAuto);

  void listeCalques();

  /** 
  * @fn void switchAnimation()
  * @brief Permet d'alterner l'animation d'une forme.
  */
  void switchAnimation();

  /** 
  * @fn void animationRainbow(Forme * f)
  * @brief Permet d'animer une forme en mode "arc en ciel"
  * @param f : forme sur laquelle on applique l'animation.
  */
  void animationRainbow(Forme * f);

   /** 
  * @fn void animationBlink(Forme * f)
  * @brief Permet d'animer une forme en mode "clignotement"
  * @param f : forme sur laquelle on applique l'animation.
  */
  void animationBlink(Forme * f);

   /** 
  * @fn void animationBounce(Forme * f)
  * @brief Permet d'animer une forme en mode "bounce"
  * @param f : forme sur laquelle on applique l'animation.
  */
  void animationBounce(Forme * f);

   /** 
  * @fn void animationReset(Forme * f)
  * @brief Permet de retourner à une forme inanimé.
  * @param f : forme sur laquelle on applique l'animation.
  */
  void animationReset(Forme * f);

 /** 
  * @fn void timerNotify()
  * @brief Fonction qui se lance après un startTimer().
  */
  void timerNotify();
};

#endif

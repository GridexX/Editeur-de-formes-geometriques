/** @file formes.hpp
 *  @author DUHAMEL Andréa et FOUGEROUSE Arsène
 *  @date Juin 2020
 *  @brief Classe Formes
 */

#ifndef FORMES_HPP
#define FORMES_HPP

#include "forme.hpp"

/**
 * @typedef uint
 * @brief équivalent à uint.
 */
typedef unsigned int uint;

class Formes {
  private:
  uint maxformes; ///< Nombre ma de formes
  uint nbformes; ///< Nombre de formes
  Forme** formes; ///Liste des formes
public:

  /** @fn Formes(uint taille=200)
   *  @brief Le constructeur de la classe Formes.
   *  @param taille : le nombre maximum de formes. 
   */
  Formes(uint taille=200);

  /**
   * @fn ~Formes()
   * @brief Le destucteur de la classe Formes.
   */
  ~Formes();

  /** @fn uint getFormes() const { return nbformes; }
   *  @brief Fonction getter pour obtenir le nombre de formes.
   *  @return Le nombre de formes.
   */
  inline uint getFormes() const { return nbformes; }

  /** @fn Forme *getFormes(uint numForme) const {return formes[numForme];}
   *  @brief Fonction getter pour obtenir une forme.
   *  @param numForme : l'index de la forme dans la liste
   *  @return Le nombre de formes.
   */
  inline Forme *getFormes(uint numForme) const {return formes[numForme];}

  /** @fn void ajouter(Forme *forme)
   *  @brief Fonction pour ajouter une forme
   *  @param forme : Un pointeur sur la forme à ajouter
   */
  void ajouter(Forme *forme);

  /** @fn void supprimer(Forme *forme)
   *  @brief Fonction pour supprimer une forme
   *  @param forme : Un pointeur sur la forme à supprimer
   */
  void supprimer(Forme *forme);

  /** 
   * @fn Forme *isOver(uint _x, uint y) const;
   *  @brief Fonction qui observe si les coordonnées passées en paramètres sont au dessus d'une forme.
   *  @param _x : La valeur d'abcisse à observer.
   *  @param _y : La valeur d'ordonée à observer.
   *  @return Un pointeur sur Forme.
   */
  Forme *isOver(uint _x,uint _y);

  /** @fn void dessiner(EZWindow& w,e) const
   *  @brief Fonction pour dessiner le contenu de la liste de formes.
   *  @param w : Une référence sur une fenêtre EZWindow où dessiner la forme.
   */
  void dessiner(EZWindow& w) const;

  /** 
   * @fn friend ostream&  operator<<(ostream&  os, const Formes& formes)
   * @brief Opérateur << qui écrit les attributs de la liste des formes passée en paramètre sur un flux de sortie.
   * @param os : Le flux de sortie.
   * @param formes : Une référence sur la classe Formes dont on récupère les attributs.
  */
  friend ostream&  operator<<(ostream&  os, const Formes& formes);

  /**
   * @fn void sauver(ostream &os) const
   * @brief Fonction pour sauvegarder la liste de formes
   * @param os : Le flux de sortie.
   */
  void sauver(ostream& os) const;

  /**
   * @fn void charger(istream &is) const
   * @brief Fonction pour charger la liste des formes
   * @param is : Le flux d'entrée.
   */
  void charger(istream& is);
};
#endif
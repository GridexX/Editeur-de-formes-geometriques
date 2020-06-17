/** @file forme.hpp
 *  @author DUHAMEL Andréa et FOUGEROUSE Arsène
 *  @date Juin 2020
 *  @brief Classe Forme
 */

#ifndef FORME_HPP
#define FORME_HPP

#include "point.hpp"

class Forme
{

private:
    ulong couleur;                ///<La couleur  de la Forme
    Point ancre;                  ///< L'ancre de la Forme
    ulong animation_couleur;      ///< Entier pour sauvegarder la couleur avant l'animation
    bool selected;                ///< Booléen qui définit si la forme est sélectionnée
    uint epaisseur = 1;           ///< L'épaisseur du contour de la Forme
    uint animation_epaisseur = 1; ///<L'épaisseur avant l'animation
    bool isFilled = false;        ///<Mode de remplissage de la Forme
    uint animation = 0;           ///<Entier définit quelle animation subit la Forme

public:
    /** @fn Forme(ulong couleur, uint x, uint y)
     *  @brief Le constructeur de la classe Forme.
     *  @param _couleur : La couleur de la forme
     *  @param _x : La coordonnée x de l'ancre
     *  @param _y : La coordonnée y de l'ancre
     */
    Forme(ulong couleur, uint x, uint y);

    /** @fn Forme(const Forme& orig)
     *  @brief Le constructeur de copie de la classe forme.
     *  @param orig : une référence sur la forme à copier.
     */
    Forme(const Forme &orig);

    /** @fn Forme(istream& is)
     *  @brief Constructeur via le flux d'entrée de la classe Forme.
     *  @param is : le flux d'entrée sur lequel va être lu la chaine de caractères.
     */
    Forme(istream &is);

    /** @fn virtual ~Forme()
     *  @brief Le destructeur de la classe Forme.
     */
    virtual ~Forme();

    /** @fn ulong getCouleur() const{ return couleur; }
     *  @brief Fonction getter pour obtenir la couleur de la Forme.
     *  @return La couleur de la Forme.
     */
    inline ulong getCouleur() const { return couleur; }

    /** @fn ulong getAnimationCouleur() const{ return animation_couleur; }
     *  @brief Fonction getter pour obtenir la couleur avant l'animation de la Forme.
     *  @return La couleur de la Forme.
     */
    inline ulong getAnimationCouleur() const { return animation_couleur; }

    /** @fn Point getAncre() const { return ancre; }
     *  @brief Fonction getter pour obtenir l'ancre de la Forme.
     *  @return L'ancre de la Forme ( voir classe Point ) .
     */
    inline Point getAncre() const { return ancre; }

    /** @fn uint getEpaisseur() const { return epaisseur; }
     *  @brief Fonction getter pour obtenir l'épaisseur de la Forme.
     *  @return L'épaisseur de la Forme.
     */
    inline uint getEpaisseur() const { return epaisseur; }

    /** @fn uint getAnimationEpaisseur() const { return animation_epaisseur; }
     *  @brief Fonction getter pour obtenir l'épaisseur avant l'animation de la Forme.
     *  @return L'épaisseur de la Forme.
     */
    inline uint getAnimationEpaisseur() const { return animation_epaisseur; }

    /** @fn bool getFilled() const { return isFilled; }
     *  @brief Fonction getter pour obtenir la méthode de remplissage de la Forme.
     *  @return isFilled : un booléen.
     */
    inline bool getFilled() const { return isFilled; }

    /** @fn uint getAnimation() const { return animation; }
     *  @brief Fonction getter pour obtenir l'animation de la Forme.
     *  @return Un entier indiquant le numéro de l'animation. 
     */
    inline uint getAnimation() const { return animation; }

    /** @fn void setCouleur(ulong _couleur) { couleur=_couleur; }
     *  @brief Fonction setter pour définir la couleur de la Forme.
     *  @param _couleur : la nouvelle couleur de la Forme.
     */
    inline void setCouleur(ulong _couleur) { couleur = _couleur; }

    /** @fn void setAnimationCouleur(ulong _animation_couleur) { animation_couleur=_animation_couleur; }
     *  @brief Fonction setter pour définir la couleur d'animation de la Forme.
     *  @param _couleur : un entier sur la nouvelle d'animation couleur de la Forme.
     */
    inline void setAnimationCouleur(ulong _animation_couleur) { animation_couleur = _animation_couleur; }

    /** @fn void setAncre(uint x,uint y) { ancre.setXY(x,y) ; }
     *  @brief Fonction setter pour définir l'ancre de la Forme.
     *  @param _x : La coordonnée x de l'ancre.
     *  @param _y : La coordonnée y de l'ancre.
     */
    inline void setAncre(uint _x, uint _y) { ancre.setXY(_x, _y); }

    /** @fn void setAncre(uint _taille) {ancre.setTaille(_taille); }
     *  @brief Fonction setter pour modifier la taille de l'ancre.
     *  @param _taille : La taille de l'ancre.
     */
    inline void setAncre(uint _taille) { ancre.setTaille(_taille); }

    /** @fn void setEpaisseur(uint _epaisseur) { if(_epaisseur>0) epaisseur=_epaisseur; }
     *  @brief Fonction setter pour modifier l'épaisseur du contour de la Forme.
     *  @param _epaisseur : L'épaisseur de la Forme.
     */
    inline void setEpaisseur(uint _epaisseur)
    {
        if (_epaisseur > 0)
            epaisseur = _epaisseur;
    }

    /** @fn void setAnimationEpaisseur(uint _animation_epaisseur) { animation_epaisseur=_animation_epaisseur; }
     *  @brief Fonction setter pour modifier l'épaisseur pendant l'animation de la Forme.
     *  @param _animation_epaisseur : L'épaisseur de la Forme.
     */
    inline void setAnimationEpaisseur(uint _animation_epaisseur) { animation_epaisseur = _animation_epaisseur; }

    /** @fn void setFilled(bool _isFilled) { isFilled=_isFilled; }
     *  @brief Fonction setter pour modifier l'état de remplissage de la Forme.
     *  @param _isFilled : L'état de remplissage de la Forme.
     */
    inline void setFilled(bool _isFilled) { isFilled = _isFilled; }

    /** @fn void setAnimation(uint _animation) { animation=_animation; }
     *  @brief Fonction setter pour modifier l'animation de la Forme.
     *  @param _animation : L'animation de la Forme.
     */
    inline void setAnimation(uint _animation) { animation = _animation; }

    /** @fn bool isOver(uint _x, uint _y) const
     *  @brief Fonction qui observe si les coordonnées passées en paramètres sont au dessus de l'ancre.
     *  @param _x : La valeur d'abcisse à observer.
     *  @param _y : La valeur d'ordonée à observer.
     */
    inline bool isOver(uint x, uint y) const { return ancre.isOver(x, y); }

    /** @fn virtual void dessiner(EZWindow& w, bool active=false) const
     *  @brief Fonction virtuelle pour dessiner la forme.
     *  @param w : Une référence sur une fenêtre EZWindow où dessiner la forme.
     *  @param isActive Booléen pour dire si l'image doit être affichée dans la fenêtre.
     */
    virtual void dessiner(EZWindow &w, bool active = false) const;

    /** @fn virtual double perimetre() const = 0
     *  @brief Fonction virtuelle du périmètre de la classe Forme.
     *  @return Le périmètre de la Forme fille.
     */
    virtual double perimetre() const = 0;

    /** 
     * @fn virtual void scale(uint x, uint y) override
     * @brief Fonction virtuelle pour modifier la taille des Formes filles.
     * @param x : coordonnée en abcisse. 
     * @param y : coordonnée en ordonnée. 
     */
    virtual void scale(uint x, uint y) = 0;

    /** 
     * @fn friend ostream& operator<<(ostream& os, const Forme& f)
     * @brief Opérateur << qui écrit les attributs de la Forme passé en paramètre sur un flux de sortie.
     * @param os : Le flux de sortie.
     * @param f : Une référence sur la Forme dont on récupère les attributs.
    */
    friend ostream &operator<<(ostream &os, const Forme &f);

    /** 
     * @fn static Forme* charger(istream& is)
     * @brief Fonction qui charge une Forme depuis un flux d'entrée.
     * @param is : Le flux d'entrée où lire les attributs.
    */
    static Forme *charger(istream &is);

protected:
    /** 
     * @fn virtual ostream& ecrire(ostream& os) const
     * @brief Fonction virtuelle qui utilise un flux de sortie pour écrire les attributs de la Forme fille .
     * @param os : Le flux de sortis où écrire les attributs.
    */
    virtual ostream &ecrire(ostream &os) const;
};

#endif
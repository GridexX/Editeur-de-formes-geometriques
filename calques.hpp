/** @file calques.hpp
 *  @author DUHAMEL Andréa et FOUGEROUSE Arsène
 *  @date Juin 2020
 *  @brief Classe Calques
 */

#ifndef CALQUE_HPP
#define CALQUE_HPP

#include <vector>
#include <utility>
#include <fstream>

#include "formes.hpp"

/**
 * @typedef vecFormes
 * @brief contient une liste de calqAndBool.
 */
typedef std::vector<std::pair<Formes *, bool>> vecFormes;

/**
 * @typedef calqAndBool
 * @brief type pair de la STL qui contient un pointeur sur Formes et un booléen
 */
typedef std::pair<Formes *, bool> calqAndBool;

class Calques
{
private:
    vecFormes listeCalque; ///< La liste des calques
    uint maxcalques;       ///< Le nombre maximum de calques
    uint nbcalques = 0;    ///< Le nombre de calques actuels
    uint calqueSelec = 0;  ///< Le calque courrant

public:
    /** @fn Calques(size_t taille=20)
         *  @brief Le constructeur de la classe Calques.
         *  @param taille : le nombre maximum de calques. 
         */
    Calques(size_t taille = 20);

    /**
         * @fn ~Calques()
         * @brief Le destucteur de la classe Calques.
         */
    ~Calques();

    /** @fn uint getCalqueSelec() const { return calqueSelec; }
     *  @brief Fonction getter pour obtenir le calque courant.
     *  @return Le numéro du calque.
     */
    inline uint getCalqueSelec() const { return calqueSelec; }

    /** @fn uint getNbCalques() const { return nbcalques; }
     *  @brief Fonction getter pour obtenir le nombre de calques.
     *  @return Le nombre de calques.
     */
    inline uint getNbCalques() const { return nbcalques; }

    /** @fn bool getCalqueVisible(uint numCalque) const { return listeCalque[numCalque].second; }
     *  @brief Fonction getter pour savoir si le calque passé en paramètre est visible.
     *  @param numCalque : le numéro du calque. 
     *  @return La visibilité du calque.
     */
    inline bool getCalqueVisible(uint numCalque) const { return listeCalque[numCalque].second; }

    /** @fn Formes *getCalque(uint numCalque) const { return listeCalque[numCalque].first; }
     *  @brief Fonction getter pour obtenir le calque.
     *  @param numCalque : le numéro du calque.
     *  @return Un pointeur sur Formes (le calque).
     */
    inline Formes *getCalque(uint numCalque) const { return listeCalque[numCalque].first; }

    /** @fn Formes uint getNbForme(uint numCalque) const { return listeCalque[numCalque].first->getFormes(); }
     *  @brief Fonction getter pour obtenir le nombre de forme sur le calque.
     *  @param numCalque : le numéro du calque.
     *  @return Le nombre de formes.
     */
    inline uint getNbForme(uint numCalque) const { return listeCalque[numCalque].first->getFormes(); }

    /** @fn inline void setCalqueSelec(uint _calqueSelec){ if (_calqueSelec >= 0 && _calqueSelec < nbcalques) calqueSelec = _calqueSelec; }
     *  @brief Fonction setter pour modifier le calque sélectionné.
     *  @param _calqueSelec : Le calque sélectionné.
     */
    inline void setCalqueSelec(uint _calqueSelec)
    {
        if (_calqueSelec >= 0 && _calqueSelec < nbcalques)
            calqueSelec = _calqueSelec;
    }

    /** @fn inline void setCalqueVisible(bool _isVisible) { listeCalque[calqueSelec].second = _isVisible; }
     *  @brief Fonction setter pour modifier le calque visible.
     *  @param _isVisible : La visibilité du calque.
     */
    inline void setCalqueVisible(bool _isVisible) { listeCalque[calqueSelec].second = _isVisible; }

    /** @fn creerCalque()
     *  @brief Fonction pour créer un calque
     */
    void creerCalque();

    /** @fn void creerCalque()
     *  @brief Fonction pour créer un calque au numéro indiqué
     *  @param numCalque 
     */
    void creerCalque(uint numCalque);

    /** @fn void creerCalque()
     *  @brief Fonction pour supprimer un calque au numéro indiqué
     *  @param numCalque 
     */
    void supprimerCalque(uint numCalque);

    /**
     * @fn void monterCalque()
     * @brief monte le calque courrant
     */
    void monterCalque();

    /**
     * @fn void decendreCalque()
     * @brief descend le calque courrant
     */
    void descendreCalque();

    /**
     * @fn void ajouterForme(Forme *forme)
     * @brief ajoute la forme sur le calque courrant.
     * @param forme : Un pointeur sur forme
     */
    void ajouterForme(Forme *forme);

    /**
     * @fn void supprimerForme(Forme *forme)
     * @brief supprime la forme sur le calque courrant.
     * @param forme : Un pointeur sur forme
     */
    void supprimerForme(Forme *forme);

    /**
     * @fn void fusionner()
     * @brief fusionne le calque courant avec celui du dessus.
     */
    void fusionner();

    /**
     * @fn void swapFormeCalque(Forme *forme, uint dest)
     * @brief supprime la forme sur un autre calque.
     * @param forme : Un pointeur sur forme
     * @param dest : Le numéro de calque de destination
     */
    void swapFormeCalque(Forme *forme, uint dest);

    /** @fn void dessiner(EZWindow& w,e) const
     *  @brief Fonction pour dessiner le contenu du calque.
     *  @param w : Une référence sur une fenêtre EZWindow où dessiner la forme.
     */
    void dessiner(EZWindow &w) const;

    /** @fn Forme *isOver(uint _x, uint y) const;
     *  @brief Fonction qui observe si les coordonnées passées en paramètres sont au dessus d'une forme.
     *  @param _x : La valeur d'abcisse à observer.
     *  @param _y : La valeur d'ordonée à observer.
     *  @return Un pointeur sur Forme.
     */
    Forme *isOver(uint _x, uint y) const;

    /** 
     * @fn friend ostream &operator<<(ostream &os, const Calques &calques)
     * @brief Opérateur << qui écrit les attributs de la liste des calques passée en paramètre sur un flux de sortie.
     * @param os : Le flux de sortie.
     * @param calques : Une référence sur la classe Calques dont on récupère les attributs.
    */
    friend ostream &operator<<(ostream &os, const Calques &calques);

    /**
     * @fn void sauverCalque(ostream &os) const
     * @brief Fonction pour sauvegarder le calque courant
     * @param os : Le flux de sortie.
     */
    void sauverCalque(ostream &os) const;

    /**
     * @fn void chargerCalque(istream &is) const
     * @brief Fonction pour charger un calque
     * @param is : Le flux d'entrée.
     */
    void chargerCalque(istream &is) const;

    /**
     * @fn void sauverCalque(ostream &os) const
     * @brief Fonction pour sauvegarder la liste des calques
     * @param os : Le flux de sortie.
     */
    void sauver(ostream &os) const;

    /**
     * @fn void charger(istream &is) const
     * @brief Fonction pour charger la liste des calques
     * @param is : Le flux d'entrée.
     */
    void charger(istream &is);
};

#endif
// Carré.hpp

#ifndef CARRE_HPP
#define CARRE_HPP

#include "Forme.hpp"

/** La classe carré. **/

class Carre : public Forme {
    private :
        uint cote; ///< Le coté (Représente le coté du carré).

    public :
        /** Constructeur de la classe carré.
		* @param _couleur Correspond à la couleur du carré (donnée de la classe Forme). 
        * @param y correspond a la coordonnée y du point d'ancrage du cercle (donnée de la classe Forme).
        * @param x correspond a la coordonnée x du point d'ancrage du cercle (donnée de la classe Forme).
		*/
        Carre(ulong _couleur, uint _x, uint _y, uint _cote);

        /** Constructeur de copie de la classe carré.
		* @param orig Correspond au corré d'origne de la copie. 
		*/
        Carre(const Carre& orig);

        /** Constructeur via d'un flux d'entré de la classe carré.
        * @param is Correspond au flux d'entré. 
		*/
        Carre(istream &is);

        /** Destructeur de la classe carré.
		*/
        ~Carre();

        /** Geteur qui récupère le coté du carré.
		* @return Un uint correspondant au coté du carré.
		*/
        inline uint getCote() const { return cote; }

        /** Seteur qui modifie le coté du carré.
		* @param _cote Un uint correspondant à la nouvelle taille du coté
		*/
        inline void setCote(uint _cote) { cote=_cote;}

        /** Fonction dessiner de la classe Cercle.
        * @param fenetre Une réference sur la fenêtre EZwindow.
        * @param estActivé Booléen pour afficher le carré dans la fenêtre.
        */
        void dessiner(EZWindow &w, bool isActive) const override;

        /** Calcul et renvoie le périmètre du carré.
		* @return Un double correspondant au périmètre du carré.
		*/
        double perimetre() const;

        protected:
        /** Fonction ecrire de la classe Cercle.
        * @param os Le flux de sortie sur lequel afficher les informations.
        * @return Le flux de sortie modifié contenant les informations sur les données membres de la classe.
        */
        virtual ostream& ecrire(ostream& os) const;
};

#endif
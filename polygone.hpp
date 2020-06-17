/**
 * @file polygone.hpp
 * @author DUHAMEL Andréa et FOUGEROUSE Arsène
 * @date Juin 2020
 * @brief Classe Polygone (classe fille de la classe Forme)
 */ 
 
#ifndef POLYGONE_HPP
#define POLYGONE_HPP
#define PI 3.14159265358979323846
#include <cmath>
#include "forme.hpp"


class Polygone : public Forme {
    private :
        uint rayon; ///< Le rayon (Représente la distance entre le centre du Polygone et chaque point lors de la construction du Polygone en pixel)
        uint nbpoints;  ///< Le nombre de point du Polygone
        Point ** points;  ///< Tableau dynamique contenant des pointeurs sur tout les points du Polygone
        bool isRegular = true; ///< Booléen pour définir le type du polygone
        

    public :
		/** 
        * @fn Polygone(ulong _couleur, uint _x, uint _y, uint _rayon, uint _nbpoints)
        * @brief Constructeur de la classe Polygone.
		* @param _couleur : correspond à la couleur du polygone (donnée de la classe Forme). 
		* @param _y : correspond a la coordonnée y du point d'ancrage du polygone (donnée de la classe Forme).
		* @param _x : correspond a la coordonnée x du point d'ancrage du polygone (donnée de la classe Forme).
		* @param _rayon : Le rayon du polygone. 
        * @param _nbpoints : Le nombre de point du polygone. 
		*/	
        Polygone(ulong _couleur, uint _x, uint _y, uint _rayon, uint _nbpoints);
		
		/** 
        * @fn Polygone(const Polygone& orig)
        * @brief Constructeur de copie de la classe Polygone.
		* @param orig : Le polygone d'origine qui va être copié.
		*/		
        Polygone(const Polygone& orig);
		
		/** 
        * @fn Polygone(istream &is)
        * @brief Constructeur via le flux d'entrée de la classe Polygone.
		* @param is : le flux d'entrée sur lequel va être lu la chaine de caractères.
		*/
        Polygone(istream &is);
		
		/** 
        * @fn ~Polygone()
        * @brief Destructeur de la classe Polygone.
		*/		
        ~Polygone();

        /** 
        * @fn Point * getPoint(uint numero) const
        * @brief Getter qui récupère un point spécifique dans notre tableau dynamique de pointeur sur Point (correspondant à l'attribut points de la Classe Polygone).
		* @param numero : L'indice du point que l'on souhaite récuperer.
        * @return Le point dont l'incide est passé en paramètre.
		*/
        inline Point * getPoint(uint numero) const {if((numero >= 0) && (numero < nbpoints)) return points[numero]; else return nullptr;}

        /** 
        * @fn uint getNbpoints()
        * @brief Fonction getter de la classe Polygone.
        * @return nbpoints Le nombre de point du polynome.
        */       
        inline uint getNbpoints() { return nbpoints;}
		
		/** 
        * @fn uint getRayon()
        * @brief Fonction getter de la classe Polygone.
		* @return Le rayon du polygone.
		*/	
        inline uint getRayon() { return rayon;}

        /** 
        * @fn void setRayon(uint _rayon)
        * @brief Fonction setter de la classe Polygone.
        * @param _rayon : Le nouveau rayon du polygone.
        */       
        void setRayon(uint _rayon);

        /** 
        * @fn void setRegular(bool _isRegular)
        * @brief Fonction setter de la classe Polygone.
        * @param _isRegular : L'état de la régularité du polygone (true = régulier; false = irrégulier).
        */ 
        inline void setRegular(bool _isRegular) { isRegular = _isRegular; }

		/** 
        * @fn void addPoint()
        * @brief Fonction membre qui permet d'ajouter un point au polygone.
		*/	
        void addPoint();

        /** 
        * @fn void removePoint()
        * @brief Fonction membre qui permet de retirer un point au polygone.
		*/	
        void removePoint();

        /** 
        * @fn void dessiner(EZWindow &w, bool isActive) const override
        * @brief Fonction dessiner de la classe Polygone.
        * @param fenetre : Une réference sur la fenêtre EZwindow.
        * @param isActive : Booléen pour afficher le polygone dans la fenêtre.
        */
        void dessiner(EZWindow &w, bool isActive) const override;
        
        /** 
        * @fn  double perimetre() const override
        * @brief Fonction perimetre de la classe Polygone.
        * @return Le périmètre du Polygone.
        */
        double perimetre() const override;
        
        /** 
        * @fn  void scale(uint x, uint y) override
        * @brief Ajuste le rayon du Polygone au coordonnés entrées en paramètres
        * @param x : coordonnée en abcisse. 
        * @param y : coordonnée en ordonnée. 
        * @return Le périmètre du Polygone.
        */
        void scale(uint x, uint y) override;

        /** 
        * @fn void setPoint(Point * p, uint numero)
        * @brief Fonction setter de la classe Polygone.
        * @param p : Pointeur sur point pointant le point que l'on veut set.
        * @param numero : L'indice du point à modifier.
        */
        void setPoint(Point * p, uint numero);
        
        /** 
        * @fn friend ostream&  operator<<(ostream&  os, const Polygone& poly)
        * @brief Operateur << qui ecrit les données du Polygone sur un flux de sortie.
        * @param os : Le flux de sortie.
        * @param poly : Le polygone dont on récupère les attributs.
        */
        friend ostream&  operator<<(ostream&  os, const Polygone& poly);

        protected:
        /** 
        * @fn ostream& ecrire(ostream& os) const override
        * @brief Fonction ecrire de la classe Polygone.
        * @param os : Le flux de sortie sur lequel afficher les informations.
        * @return Le flux de sortie modifié contenant les informations sur les données membres de la classe.
        */
        ostream& ecrire(ostream& os) const override;
};

#endif
/** @file image.hpp
 *  @author DUHAMEL Andréa et FOUGEROUSE Arsène
 *  @date Juin 2020
 *  @brief Classe Image (classe fille de forme)
 */

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "forme.hpp"

class Image : public Forme
{
private:
    string nomFichier;    ///< Le chemin source de l'image
    EZImage *image;       ///< Un pointeur sur l'image
    double ratio;         ///< Le ratio de l'image
    bool estTransparente; ///< Un booléen pour dire si l'image accepte la transparence

    /** @fn void setupImage(string _nomFichier, double ratio, bool _estTransparente)
         *  @brief Fonction pour créer une image à partir de son ratio et de son Alpha.
         *  @param _nomFichier : Le chemin source de l'image.
         *  @param _ration : Le ratio de l'image.
         *  @param _estTransparente;   ///< Un booléen pour dire si l'image accepte la transparence.
         */
    void setupImage(string _nomFichier, double ratio, bool _estTransparente);

public:
    /** @fn Image(ulong _couleur, uint _x, uint _y, string _nomFichier, double _ratio, bool _estTransparente)
         *  @brief Le constructeur de la classe Image.
         *  @param _couleur : La couleur de la forme
         *  @param _x : La coordonnée x de l'ancre
         *  @param _y : La coordonnée y de l'ancre
         *  @param _nomFichier : Le chemin source de l'image 
         *  @param _ratio : Le ratio de l'image
         *  @param _estTransparente : Un booléen pour dire si l'image accepte la transparence
         */
    Image(ulong _couleur, uint _x, uint _y, string _nomFichier, double _ratio, bool _estTransparente);

    /** @fn Image(const Image& orig)
         *  @brief Le constructeur de copie de la classe Image.
         *  @param orig : une référence sur l'image à copier.
         */
    Image(const Image &orig);

    /** @fn Image(istream& is)
         *  @brief Constructeur via le flux d'entrée de la classe Image.
         *  @param is : le flux d'entrée sur lequel va être lu la chaine de caractères.
         */
    Image(istream &is);

    /** @fn ~Image()
         *  @brief Le destructeur de la classe Image.
         */
    ~Image();

    /** @fn double getRatio() const { return ratio; }
         *  @brief Fonction getter pour obtenir le ratio de l'image.
         *  @return ratio : Le ratio de l'image.
         */
    inline double getRatio() const { return ratio; }

    /** @fn bool getTransparence() const { return estTransparente; }
         *  @brief Fonction getter pour savoir si l'image accepte la transparence.
         *  @return estTransparente : Le booléen définiçant la transparence de l'image.
         */
    inline bool getTransparence() const { return estTransparente; }

    /** @fn void setRatio(double _ratio) { ratio=_ratio; delete image; EZImage *img=new EZImage(nomFichier.c_str()); image=img->scale(ratio); }
         *  @brief Fonction setter pour définir le ratio de l'image.
         *  @param _ratio : Le nouveau ratio de l'image sous forme de flotant.
         */
    inline void setRatio(double _ratio)
    {
        ratio = _ratio;
        delete image;
        EZImage *img = new EZImage(nomFichier.c_str());
        image = img->scale(ratio);
    }

    /** @fn void setTransparence(bool _estTransparente) { estTransparente=_estTransparente; image->setAlpha(estTransparente); }
         *  @brief Fonction setter pour définir Le booléen traduisant la transparence de l'image.
         *  @param _estTransparente : Le nouvel état de transparence de l'image.
         */
    inline void setTransparence(bool _estTransparente)
    {
        estTransparente = _estTransparente;
        image->setAlpha(estTransparente);
    }

    /** @fn void dessiner(EZWindow &w, bool isActive) const override
         *  @brief Fonction pour dessiner l'image.
         *  @param w : Une référence sur une fenêtre EZWindow où dessiner la forme.
         *  @param isActive Booléen pour dire si l'image doit être affichée dans la fenêtre.
         */
    void dessiner(EZWindow &w, bool isActive) const override;

    /** @fn perimetre() const override
         *  @brief Fonction  périmètre de la classe Image.
         *  @return Le périmètre du Image.
         */
    double perimetre() const override;

    /** 
         * @fn void scale(uint x, uint y) override
         * @brief Ajuste la taille de l'image en fonction des coordonnées passées en paramètres.
         * @param x : coordonnée en abcisse. 
         * @param y : coordonnée en ordonnée. 
         */
    void scale(uint x, uint y) override;

protected:
    /** 
        * @fn ostream& ecrire(ostream& os) const override
        * @brief Fonction ecrire de la classe Image.
        * @param os : Le flux de sortie sur lequel afficher les informations.
        * @return Le flux de sortie modifié contenant les informations sur les données membres de la classe Image.
        */
    virtual ostream &ecrire(ostream &os) const;
};

#endif
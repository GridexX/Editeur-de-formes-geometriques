/** @file MyWindow.cpp
 *  @author DUHAMEL Andréa et FOUGEROUSE Arsène
 *  @date Juin 2020
 *  @brief Classe MyWindow
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "ez-draw++.hpp"
#include "MyWindow.hpp"

#include "formes.hpp"
#include "point.hpp"
#include "ellipse.hpp"
#include "cercle.hpp"
#include "rectangle.hpp"
#include "carre.hpp"
#include "image.hpp"
#include "calques.hpp"
#include "polygone.hpp"

#include <cmath>

static unsigned int delay = 200; //délai pour les animations

MyWindow::MyWindow(int w, int h,const char *name)
 : EZWindow(w,h,name),calques(20),pforme(nullptr),point(-1), ancre_x(0), ancre_y(0), diff_x(0), diff_y(0)
{
  #ifdef ADVANCED_FACTORY
 if(needInitialization) // Ne faire l'initialisation que la première fois qu'une MyWindow est construite.
  {
   needInitialization=false;
   Forme::register_factory_function<Rectangle>("Rectangle");
   Forme::register_factory_function<Ellipse>("Ellipse");
   Forme::register_factory_function<Carre>("Carre");
   Forme::register_factory_function<Cercle>("Cercle");
   Forme::register_factory_function<Polygone>("Polygone");
   Forme::print_registered_factory_functions(cout);
  }
#endif
}

MyWindow::~MyWindow()
{}

void MyWindow::expose()
{
  calques.dessiner(*this);
  if(pforme!=nullptr) pforme->dessiner(*this,true);
  setColor(ez_black);
  setFont(0);
  drawText(EZAlign::TL,1,3,"h : affiche l'aide sur la console");
  drawText(EZAlign::TL,1,18,"Maj+'Touche Forme' : choisir les dimensions de la forme");
  setDoubleBuffer(true); // pour éviter le scintillement de l'image
}

void MyWindow::buttonPress(int mouse_x,int mouse_y,int button)
{
  if(button==1 && calques.getNbCalques()>0){ //Si le clic gauche est appuyé et le nombre de calque est > 0
     pforme = calques.isOver(mouse_x,mouse_y);
    if(pforme)
    {
    Polygone * poly;
    poly = dynamic_cast<Polygone*>(pforme); //Down casting de la classe Forme à Polygone
    if(poly!=nullptr) //Vérifie si il s'agit bien d'un Polygone
      {
        ancre_x = poly->getAncre().getX();
        ancre_y = poly->getAncre().getY();
      }
    }
  }    
  else if (button==3 && pforme)  //Si le clic droit est appuyé et que pforme pointe une Forme
    {
      Polygone * poly;
      poly = dynamic_cast<Polygone*>(pforme);
      if(poly!=nullptr) 
      {
        ancre_x = poly->getAncre().getX(); //On récupère l'ordonnée de l'ancre du polygone
        ancre_y = poly->getAncre().getY(); //On récupère l'abcisse de l'ancre du polygone
        point=-1; //On reset le l'indice du point à -1
        for(uint i = 0; i < poly->getNbpoints(); i++) //On parcours tout les points du Polygone sélectionné
          if(poly->getPoint(i)->isOver(mouse_x, mouse_y)) point = i; //On récupère le point par selectionné
          else
            pforme->scale(mouse_x, mouse_y);
      }
      else
        pforme->scale(mouse_x, mouse_y);
    }

}

// Deplacement de la souris :
void MyWindow::motionNotify(int mouse_x,int mouse_y,int button)
{
  setXY(mouse_x,mouse_y);
  if(button == 1 && pforme != nullptr){ // Si on clique sur l'ancre d'une forme
    pforme->setAncre(mouse_x,mouse_y);
    Polygone * poly;
    poly = dynamic_cast<Polygone*>(pforme);
    if(poly!=nullptr) {
      diff_x = poly->getAncre().getX() - ancre_x;
      diff_y = poly->getAncre().getY() - ancre_y;
      for(uint i = 0; i < poly->getNbpoints(); i++)
      {
        Point * p = new Point(poly->getPoint(i)->getX()+diff_x,poly->getPoint(i)->getY()+diff_y);
        poly->setPoint(p, i);      
      }
      ancre_x = poly->getAncre().getX();
      ancre_y = poly->getAncre().getY();
    }// on la bouge.
  }
  if(button!=3) point = -1;
  if(button == 3 && pforme != nullptr && point > -1){
    Polygone * poly;
    poly = dynamic_cast<Polygone*>(pforme);
    if(poly!=nullptr){
      Point * p = new Point(mouse_x, mouse_y); //On crée un nouveau point
      poly->setPoint(p, point); //On associe remplace le point donc l'indice est stocké dans point par le nouveau point p
      poly->setRegular(false); //Si on déplace un poitn du Polygone on change l'attribut en indiquant qu'il est irrégulier
    }
    
  }
  //pour scale le polygone
  if(button == 2 && pforme){
    Polygone * poly;
    poly = dynamic_cast<Polygone*>(pforme);
    if(poly != nullptr){
      poly->scale(mouse_x,mouse_y);
    }
    
  }
  
  //Pour scale les autres formes
  if(button == 3 && pforme) 
    pforme->scale(mouse_x, mouse_y);
  sendExpose();
}

void MyWindow::buttonRelease(int mouse_x,int mouse_y,int button)
{
    setXY(mouse_x,mouse_y);
  if(button == 1 && pforme != nullptr){ // Si on clique sur l'ancre d'une forme
    pforme->setAncre(mouse_x,mouse_y);
    Polygone * poly;
    poly = dynamic_cast<Polygone*>(pforme);
    if(poly!=nullptr) {
      diff_x = poly->getAncre().getX() - ancre_x;
      diff_y = poly->getAncre().getY() - ancre_y;
      for(uint i = 0; i < poly->getNbpoints(); i++)
      {
        Point * p = new Point(poly->getPoint(i)->getX()+diff_x,poly->getPoint(i)->getY()+diff_y);
        poly->setPoint(p, i);      
      }
      ancre_x = poly->getAncre().getX();
      ancre_y = poly->getAncre().getY();
    }// on la bouge.
  }
  if(button!=3) point = -1;
  if(button == 3 && pforme != nullptr && point > -1){
    Polygone * poly;
    poly = dynamic_cast<Polygone*>(pforme);
    if(poly!=nullptr){
      Point * p = new Point(mouse_x, mouse_y);
      poly->setPoint(p, point);
    }
    
  }
  //pour scale les formes
  if(button == 3 && pforme)
    pforme->scale(mouse_x, mouse_y);
  sendExpose();
}

void MyWindow::keyPress(EZKeySym keysym) // Une touche du clavier a ete enfoncee ou relachee
{
  switch (keysym)
    {
      case EZKeySym::Escape:
      case EZKeySym::q :       EZDraw::quit (); break;
      case EZKeySym::s:
        cout << calques;
        break;  //si aucune forme n'est sélectionnée, celàsauvegarde tout le calque

      case EZKeySym::S:  //Sauvegarde un calque si la forme est sélectionnée / sinon la liste entière
      {
        if(pforme){
          ofstream f("formes.txt");
          calques.sauverCalque(f);
          listeCalques();

        }else{
          ofstream c("calques.txt");
          calques.sauver(c);
          listeCalques();
        }
      } break;

      case EZKeySym::v: //charger un calque
      {
        ifstream f("formes.txt");
        calques.chargerCalque(f);
        startTimer(delay);
        listeCalques();

      } break;

      case EZKeySym::V:  //charger la liste des calques
      {
        ifstream c("calques.txt");
        calques.charger(c);
        listeCalques();

      } break;

      //modification du délai pour l'animation
      case EZKeySym::colon: if (delay <= 975) delay += 25; break;
      case EZKeySym::exclam: if (delay >= 50) delay -= 25; break;


      case EZKeySym::k:  //modification nb point Polygone
      {
        if(pforme)
        {
          Polygone * poly;
          poly = dynamic_cast<Polygone*>(pforme);
          if(poly!=nullptr) {
            poly->addPoint();
            Point * tempP = new Point(poly->getAncre().getX(), poly->getAncre().getY());
            poly->setPoint(tempP, poly->getNbpoints()-1);
            poly->setRayon(poly->getRayon());
          }
        } break;
      }
      case EZKeySym::l:
      {
        if(pforme)
        {
          Polygone * poly;
          poly = dynamic_cast<Polygone*>(pforme);
          if(poly!=nullptr) {
            poly->removePoint();
            poly->setRayon(poly->getRayon());
          }
        } break;
      }

      case EZKeySym::_0: if(pforme) {
        if(pforme->getAnimation() > 0) pforme->setAnimationCouleur(ez_black); //Si la Forme est animé on change la variable ou est stocké la couleur avant animation
        else pforme->setCouleur(ez_black);                                    //Sinon on change directement la couleur de la forme
        break;
      }
      case EZKeySym::_1: if(pforme) {
        if(pforme->getAnimation() > 0) pforme->setAnimationCouleur(ez_grey); 
        else pforme->setCouleur(ez_grey);   
        break;
      }
      case EZKeySym::_2: if(pforme) {
        if(pforme->getAnimation() > 0) pforme->setAnimationCouleur(ez_red); 
        else pforme->setCouleur(ez_red);   
        break;
      }
      case EZKeySym::_3: if(pforme) {
        if(pforme->getAnimation() > 0) pforme->setAnimationCouleur(ez_green); 
        else pforme->setCouleur(ez_green);   
        break;
      }
      case EZKeySym::_4: if(pforme) {
        if(pforme->getAnimation() > 0) pforme->setAnimationCouleur(ez_blue); 
        else pforme->setCouleur(ez_blue);   
        break;
      }
      case EZKeySym::_5: if(pforme) {
        if(pforme->getAnimation() > 0) pforme->setAnimationCouleur(ez_yellow); 
        else pforme->setCouleur(ez_yellow);   
        break;
      }
      case EZKeySym::_6: if(pforme) {
        if(pforme->getAnimation() > 0) pforme->setAnimationCouleur(ez_cyan); 
        else pforme->setCouleur(ez_cyan);   
        break;
      }
      case EZKeySym::_7: if(pforme) {
        if(pforme->getAnimation() > 0) pforme->setAnimationCouleur(ez_magenta); 
        else pforme->setCouleur(ez_magenta);   
        break;
      }
      case EZKeySym::plus: if(pforme) {
        //On augmente l'épaisseur de la forme avant et après animation
        pforme->setAnimationEpaisseur(pforme->getAnimationEpaisseur()+1); pforme->setAncre(pforme->getAncre().getTaille()+pforme->getAnimationEpaisseur()); 
        pforme->setEpaisseur(pforme->getEpaisseur()+1); pforme->setAncre(pforme->getAncre().getTaille()+pforme->getEpaisseur());
        break;
      }
      case EZKeySym::minus: {
        //On diminue l'épaisseur de la forme avant et après animation
        pforme->setAnimationEpaisseur(pforme->getAnimationEpaisseur()-1); pforme->setAncre(pforme->getAncre().getTaille()+pforme->getAnimationEpaisseur()); 
        pforme->setEpaisseur(pforme->getEpaisseur()-1); pforme->setAncre(pforme->getAncre().getTaille()+pforme->getEpaisseur()); 
        break;
      }
      case EZKeySym::F: if(pforme) pforme->setFilled(! pforme->getFilled()); break;
      case EZKeySym::Delete: if(pforme) calques.supprimerForme(pforme);  listeCalques(); pforme=nullptr; break;
      case EZKeySym::ugrave: {
        if(pforme)
        { 
          Image * img = dynamic_cast<Image*> (pforme); 
          if(img != nullptr)
            img->setRatio( img->getRatio()+0.1);
        }
      }  break;
      case EZKeySym::asterisk: {
        if(pforme)
        { 
          Image * img = dynamic_cast<Image*> (pforme); 
          if(img != nullptr)
            img->setRatio( img->getRatio()-0.1);
        }  
      } break;
      case EZKeySym::t: 
      if(pforme)
      { 
        Image * img = dynamic_cast<Image*> (pforme); 
        if(img != nullptr)
          img->setTransparence( !img->getTransparence() );
      } break;

      //appui des touches pour les calques :
      case EZKeySym::y: calques.creerCalque();   listeCalques(); break;
      case EZKeySym::Left: calques.monterCalque();   listeCalques(); break; 
      case EZKeySym::Right: calques.descendreCalque();   listeCalques(); break;
      case EZKeySym::Up: calques.setCalqueSelec(calques.getCalqueSelec()+1);   listeCalques(); break;
      case EZKeySym::Down: calques.setCalqueSelec(calques.getCalqueSelec()-1);   listeCalques(); break;
      case EZKeySym::a:  calques.setCalqueVisible( !calques.getCalqueVisible(calques.getCalqueSelec()));   listeCalques(); break;
      case EZKeySym::d: calques.supprimerCalque(calques.getCalqueSelec());   listeCalques(); break;
      case EZKeySym::F1: calques.fusionner(); listeCalques(); break;
      case EZKeySym::w: calques.swapFormeCalque(pforme,calques.getCalqueSelec()+1);   listeCalques(); break;
      case EZKeySym::x: calques.swapFormeCalque(pforme,calques.getCalqueSelec()-1);   listeCalques(); break;
      case EZKeySym::n: switchAnimation(); break;
      case EZKeySym::h:
      cout 
            << "--------------------------------------------------------" << endl
            << "----------------------SAUVEGARDE------------------------" << endl
            
            << "s : ecrire la liste des formes sur la console" << endl
            << "S : sauve un calque / la liste des calques sur le disque " << endl
            << "v : charger un calque depuis le disque" << endl
            << "V : charger la liste des calques depuis le disque" << endl

            << "--------------------------------------------------------" << endl
            << "----------------------FORMES----------------------------" << endl

            
            << "0 : met en noir la forme"    << endl
            << "1 : met en gris la forme"    << endl
            << "2 : met en rouge la forme"   << endl
            << "3 : met en vert la forme"    << endl
            << "4 : met en bleu la forme"    << endl
            << "5 : met en jaune la forme"   << endl
            << "6 : met en cyan la forme"    << endl
            << "7 : met en magenta la forme" << endl
            << "+ : augmente l'épaisseur"    << endl
            << "- : diminue l'épaisseur"     << endl
            << "F : switch entre le contour et le remplissage" <<endl
            << "r : crée un rectangle" << endl
            << "e : crée une ellipse" << endl
            << "s : crée un carré" << endl
            << "c : crée un cercle" << endl
            << "p : crée un polygone régulier" << endl
            << "i : crée une image" << endl
            << "Suppr : supprime la forme" << endl
            << "Clic droit sur l'affichage pour déplacer le coin inférieur droit" << endl

            << "--------------------------------------------------------" << endl
            << "----------------------POLYGONE--------------------------" << endl
            << "p : crée un polygone régulier" << endl
            << "k : rajouter 1 point au polynome sélectionné" <<endl
            << "l : enlever 1 point du polynome sélectionné" <<endl
            << "Clic  droit : pour déplacer un sommet" << endl
            << "Clic mollette pour agrandir le polygome régulier" << endl
            
            << "--------------------------------------------------------" << endl
            << "----------------------IMAGE-----------------------------" << endl
            << "i : crée une image" << endl
            << "t : ajouter/supprimer la tranparence de l'image" << endl
            << "ù : agrandit l'image'" << endl                      
            << "* : rapetisse l'image'" << endl  // changer avec un scale
            << "--------------------------------------------------------" << endl
            << "----------------------ANIMATION-------------------------" << endl
            << "n : changer d'animation" << endl
            << "':' : Diminue le délai de transition entre les animations" << endl
            << "! : Augmente le délai de transition entre les animations" << endl 
            
            << "--------------------------------------------------------" << endl 
            << "------------------------CALQUES-------------------------" << endl
            << "y : crée un nouveau calque" << endl
            << "d : supprime le calque selectionné" << endl
            << "a : affiche / masquer le calque sélectionné" << endl
            << "← : monte le calque selectionné" << endl
            << "→ : descends le calque selectionné" << endl
            << "↑ : sélectionne le calque au dessus" << endl 
            << "↓ : sélectionne le calque en dessous" << endl
            << "F1 : fusionner le calque sélectionné avec celui du dessus"<<endl
            << "w : envoie la forme sélectionnée sur le calque du dessus" <<endl
            << "x : envoie la forme sélectionnée sur le calque du dessous"<<endl
            << "--------------------------------------------------------" << endl 
            ;
            listeCalques();
      break;
      //majuscule + touche forme pour entrer les coordonnées;
      case EZKeySym::r: if(calques.getNbCalques()>0) creerForme("Rectangle", true); listeCalques(); break;
      case EZKeySym::R: if(calques.getNbCalques()>0) creerForme("Rectangle", false); listeCalques(); break;
      case EZKeySym::e: if(calques.getNbCalques()>0) creerForme("Ellipse", true); listeCalques(); break;
      case EZKeySym::E: if(calques.getNbCalques()>0) creerForme("Ellipse", false); listeCalques(); break;
      case EZKeySym::c: if(calques.getNbCalques()>0) creerForme("Carre", true); listeCalques(); break;
      case EZKeySym::C: if(calques.getNbCalques()>0) creerForme("Carre", false); listeCalques(); break;
      case EZKeySym::o: if(calques.getNbCalques()>0) creerForme("Cercle", true); listeCalques();break;
      case EZKeySym::O: if(calques.getNbCalques()>0) creerForme("Cercle", false); listeCalques(); break;
      case EZKeySym::p: if(calques.getNbCalques()>0) creerForme("Polygone", true); listeCalques(); break;
      case EZKeySym::P: if(calques.getNbCalques()>0) creerForme("Polygone", false); listeCalques(); break;
      case EZKeySym::i: if(calques.getNbCalques()>0) creerForme("Image", true); listeCalques();break;
      case EZKeySym::I: if(calques.getNbCalques()>0) creerForme("Image", false); listeCalques(); break;

      default: break;
    }
  sendExpose();
}


//affichage dans la console des calques
void MyWindow::listeCalques(){
    cout << "-------------------LISTE CALQUES------------------------" << endl;
    for(int i=calques.getNbCalques()-1; i>-1; --i){
        cout << "Calque " << i+1 << "[";
        if(i==calques.getCalqueSelec())
            cout << "✓";
        cout << "]";
        if(calques.getCalqueVisible(i))
            cout << " Visible ";
        else
            cout << " Caché ";

        cout << "("<<calques.getNbForme(i)<<" Formes)"<< endl;
    }
    cout << "--------------------------------------------------------"<<endl;
}


void MyWindow::creerForme(string forme, bool coordAuto)
{
  if(forme=="Rectangle"){
    if(coordAuto){
        if(isMouseWindow(mouseX ,mouseY))   //On crée un rectangle au coordonnées du pointeur si il est dans la fenêtre
          calques.ajouterForme(new Rectangle(ez_black,mouseX,mouseY,150,200));
        else                                //Sinon on le place au centre
          calques.ajouterForme(new Rectangle(ez_black,getWidth()/2-25,getHeight()/2-25,150,200));
    }
    else{
      cout << endl << "Vous êtes sur le point de créer un Rectangle. "<< endl << "Entrez la longueur et la largeur : " ;
      uint longueur, largeur;
        cin >> longueur >> largeur;
        //On vérifie que les dimensions soient correctes
        while(longueur<0 || longueur > getHeight()) {
          cerr << "La longueur doit être comprise entre 0 et "<<getHeight(); cout << ". Entrez la longueur "; cin >> longueur;
        }
        while(largeur<0 || largeur > getWidth()) {
          cerr << "La largeur doit être comprise entre 0 et "<<getWidth(); cout << ". Entrez la largeur : "; cin >> largeur;
        } 
        //on ajoute le rectangle dans le calque aux coordonnées en fonction du curseur
        if(isMouseWindow(mouseX ,mouseY))
          calques.ajouterForme(new Rectangle(ez_black,mouseX,mouseY,longueur,largeur));
        else
          calques.ajouterForme(new Rectangle(ez_black,getWidth()/2-25,getHeight()/2-25,longueur,largeur));   
    }
  }

  else if(forme=="Ellipse"){
    if(coordAuto){
        if(isMouseWindow(mouseX ,mouseY))
          calques.ajouterForme(new Ellipse(ez_black,mouseX,mouseY,150,200));
        else
          calques.ajouterForme(new Ellipse(ez_black,getWidth()/2-25,getHeight()/2-15,150,200));
    }
    else{
      cout << endl << "Vous êtes sur le point de créer une Ellipse. "<< endl << "Entrez la demi-longueur et la demi-largeur : " ;
      uint demilongueur, demilargeur;
        cin >> demilongueur >> demilargeur;
        while(demilongueur<0 || demilongueur > getHeight()) {
          cerr << "La demi-longueur doit être comprise entre 0 et "<<getHeight()<<endl; cout << ". Entrez la demi-longueur :"; cin >> demilongueur;
        }
        while(demilargeur<0 || demilargeur > getWidth()){ 
          cerr << "La demi-largeur doit être comprise entre 0 et "<<getWidth()<<endl; cout << ". Entrez la demi-largeur :"; cin>>demilargeur;
        }
        if(isMouseWindow(mouseX ,mouseY))
          calques.ajouterForme(new Ellipse(ez_black,mouseX,mouseY,demilongueur,demilargeur));
        else
          calques.ajouterForme(new Ellipse(ez_black,getWidth()/2-25,getHeight()/2-25,demilongueur,demilargeur));   
    }
  }

  if(forme=="Carre"){
    if(coordAuto){
        if(isMouseWindow(mouseX ,mouseY))   
          calques.ajouterForme(new Carre(ez_black,mouseX,mouseY,150));
        else
          calques.ajouterForme(new Carre(ez_black,getWidth()/2-25,getHeight()/2-25,150));
    }
    else{
      cout << endl << "Vous êtes sur le point de créer un Carré. "<< endl << "Entrez le côte : " ;
      uint cote;
        cin >> cote;
        while(cote<0 || cote>getWidth() || cote>getHeight()){
          uint plusBas = ( getWidth()<getHeight() ? getWidth() : getHeight() ); 
          cerr << "Le coté doit être compris entre 0 et "<<plusBas;
          cout << ". Entrez le côte : ";
          cin >> cote;
        } 
        if(isMouseWindow(mouseX ,mouseY))
          calques.ajouterForme(new Carre(ez_black,mouseX,mouseY,cote));
        else
          calques.ajouterForme(new Carre(ez_black,getWidth()/2-25,getHeight()/2-25,cote));   
    }
  }

  if(forme=="Cercle"){
    if(coordAuto){
        if(isMouseWindow(mouseX ,mouseY))
          calques.ajouterForme(new Cercle(ez_black,mouseX,mouseY,75));
        else
          calques.ajouterForme(new Cercle(ez_black,getWidth()/2-25,getHeight()/2-25,75));
    }
    else{
      cout << endl << "Vous êtes sur le point de créer un Cercle. "<< endl << "Entrez le rayon : " ;
      uint rayon;
        cin >> rayon;
        while(rayon<0 || rayon*2>getWidth() || rayon*2>getHeight()){
          uint plusBas = ( getWidth()<getHeight() ? getWidth()/2 : getHeight()/2 ); 
          cerr << "Le rayon doit être compris entre 0 et "<<plusBas;
          cout << ". Entrez le rayon : ";
          cin >> rayon;
        } 
        if(isMouseWindow(mouseX ,mouseY))
          calques.ajouterForme(new Cercle(ez_black,mouseX,mouseY,rayon));
        else
          calques.ajouterForme(new Cercle(ez_black,getWidth()/2-25,getHeight()/2-25,rayon));   
    }
  }

  if(forme=="Polygone"){
    if(coordAuto){
        if(isMouseWindow(mouseX ,mouseY))
          calques.ajouterForme(new Polygone(ez_black,mouseX,mouseY,150,6));
        else
          calques.ajouterForme(new Polygone(ez_black,getWidth()/2-25,getHeight()/2-25,150,6));
    }
    else{
      cout << endl << "Vous êtes sur le point de créer un Polygone. "<< endl << "Entrez le rayon et le nombre de sommets : " ;
      uint rayon, nbsommet;
      cin >> rayon >> nbsommet;
        while(rayon<0 || rayon*2>getWidth() || rayon*2>getHeight()){
          uint plusBas = ( getWidth()<getHeight() ? getWidth()/2 : getHeight()/2 ); 
          cerr << "Le rayon doit être compris entre 0 et "<<plusBas;
          cout << ". Entrez le rayon : ";
          cin >> rayon;
        } 
        if(isMouseWindow(mouseX ,mouseY))
          calques.ajouterForme(new Polygone(ez_black,mouseX,mouseY,rayon,nbsommet));
        else
          calques.ajouterForme(new Polygone(ez_black,getWidth()/2-25,getHeight()/2-25,rayon,nbsommet));   
    }
  }

  if(forme=="Image"){
    if(coordAuto){
        if(isMouseWindow(mouseX ,mouseY))   
          calques.ajouterForme(new Image(ez_black,mouseX,mouseY,"Fallout_logo.png",1,true));
        else
          calques.ajouterForme(new Image(ez_black,getWidth()/2-25,getHeight()/2-25,"Fallout_logo.png",1,true));
    }
    else{
      cout << endl << "Vous êtes sur le point de créer une Image. "<< endl << "Entrez le fichier source et le ratio : " ;
      uint ratio;
      string path;
      try{cin >> path;}
        catch(std::runtime_error &re){ cerr << "Vous n'avez pas entré un nom d'image valide"<<endl;}
        cin >> ratio;
        while(ratio<0){
          cerr << "Ratio inférieur à 0";
          cout << ". Entrez le ratio :";
          cin >> ratio;
        }
        if(isMouseWindow(mouseX ,mouseY))
          calques.ajouterForme(new Image(ez_black,mouseX,mouseY,path,ratio,true));
        else
          calques.ajouterForme(new Image(ez_black,getWidth()/2-25,getHeight()/2-25,path,ratio,true));  
    }
  }

}

void MyWindow::animationReset(Forme * f)
{
  if(f){
    f->setCouleur(f->getAnimationCouleur()); //Reset la couleur
    f->setEpaisseur(f->getAnimationEpaisseur()); //Reset l'épaisseur
  }
}

void MyWindow::animationRainbow(Forme * f)
{
  if(f && f->getAnimation()==1){
    f->setEpaisseur(f->getAnimationEpaisseur()); //On récupère l'épaisseur avant animation
    //Si la couleur de la forme n'est pas un couleur de l'arc en ciel on le change la couleur en cyan
    if((f->getCouleur()!=ez_cyan) && (f->getCouleur()!=ez_blue) && (f->getCouleur()!=ez_magenta) && (f->getCouleur()!=ez_red) && (f->getCouleur()!=ez_yellow) && (f->getCouleur()!=ez_green)){
      f->setCouleur(ez_cyan);
    }
    //Sinon on change de couleur à chaque entré dans la fonction
    else if(f->getCouleur()==ez_cyan) f->setCouleur(ez_blue);
    else if(f->getCouleur()==ez_blue) f->setCouleur(ez_magenta);
    else if(f->getCouleur()==ez_magenta) f->setCouleur(ez_red);    
    else if(f->getCouleur()==ez_red) f->setCouleur(ez_yellow);    
    else if(f->getCouleur()==ez_yellow) f->setCouleur(ez_green);    
    else if(f->getCouleur()==ez_green) f->setCouleur(ez_cyan);  
  }
}

void MyWindow::animationBlink(Forme * f)
{
  if(f && f->getAnimation()==2){
    f->setEpaisseur(f->getAnimationEpaisseur()); //On récupère l'épaisseur avant animation
    if(f->getCouleur()==ez_white) f->setCouleur(f->getAnimationCouleur()); //Si la forme est blanche on la met dans la couleur stocké avant animation
    else f->setCouleur(ez_white); //Sinon on  la met en blanc
  }
}

void MyWindow::animationBounce(Forme * f)
{
  if(f->getAnimation()==3){
    f->setCouleur(f->getAnimationCouleur()); //On récupère la couleur avant animation
    if(f) f->setEpaisseur(EZDraw::random(f->getAnimationEpaisseur()*2)+1); //On modifie l'épaisseur aléatoirement entre 1 et 2 fois l'épaisseur de la forme
  }
}


void MyWindow::timerNotify() // declenchee a chaque fois que le timer est ecoule.
{
  for(uint i = 0; i < calques.getNbCalques(); i++){ //On parcours tout chaque calque
    for(uint j = 0; j < calques.getNbForme(i); j++) //On parcours chaque Forme
    {
      if(calques.getCalque(i)->getFormes(j)->getAnimation() == 0) animationReset(calques.getCalque(i)->getFormes(j)); //On applique une animation selon la valeur de 
      else                                                                                                            // l'attribut animation de la classe forme
      {
        if(calques.getCalque(i)->getFormes(j)->getAnimation() == 1) animationRainbow(calques.getCalque(i)->getFormes(j));
        if(calques.getCalque(i)->getFormes(j)->getAnimation() == 2) animationBlink(calques.getCalque(i)->getFormes(j));
        if(calques.getCalque(i)->getFormes(j)->getAnimation() == 3) animationBounce(calques.getCalque(i)->getFormes(j));
      sendExpose();
      startTimer(delay);  //On relance la boucle
      }   
    }    
  }
}

void MyWindow::switchAnimation()
{
  if(pforme){
    animationReset(pforme); // On reset l'animation
    startTimer(delay); //On relance la boucle d'animation
    uint anim = pforme->getAnimation(); 
    anim = (anim + 1) % 4; //On fait boucler la valeur de l'animation 
    pforme->setAnimation(anim); //On applique la nouvelle valeur de l'animation
  }  
}
// MyWindow.cpp
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "ez-draw++.hpp"
#include "MyWindow.hpp"

#include "formes.hpp"
#include "point.hpp"   // Uniquement pour le constructeur qui peuple la fenêtre
#include "ellipse.hpp" // avec quelques formes.
#include "cercle.hpp"
#include "rectangle.hpp"
#include "carre.hpp"
#include "triangle.hpp"
#include "image.hpp"
#include "calques.hpp"
#include "polygone.hpp"

static unsigned int delay = 200;

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
  drawText(EZAlign::TL,3,3,"h : affiche l'aide sur la console");
  setDoubleBuffer(true); // pour éviter le scintillement de l'image
}

void MyWindow::buttonPress(int mouse_x,int mouse_y,int button)
{
  if(button==1){
     pforme = calques.isOver(mouse_x,mouse_y);
    if(pforme)
    {
    Polygone * poly;
    poly = dynamic_cast<Polygone*>(pforme);
    if(poly!=nullptr) 
      {
        ancre_x = poly->getAncre().getX();
        ancre_y = poly->getAncre().getY();
      }
    }
  }    
  else if (button==3){
    if(pforme)
    {
      Polygone * poly;
      poly = dynamic_cast<Polygone*>(pforme);
      if(poly!=nullptr) 
      {
        ancre_x = poly->getAncre().getX();
        ancre_y = poly->getAncre().getY();
        point=-1;
        for(uint i = 0; i < poly->getNbpoints(); i++)
        {
          if(poly->getPoint(i)->isOver(mouse_x, mouse_y)) point = i;
        }
      }
    }
  }
}

// Deplacement de la souris :
void MyWindow::motionNotify(int mouse_x,int mouse_y,int button)
{
  if(button == 1 && pforme != nullptr){ // Si on clique sur l'ancre d'une forme
    pforme->setAncre(mouse_x,mouse_y);
    Polygone * poly;
    poly = dynamic_cast<Polygone*>(pforme);
    if(poly!=nullptr && poly->getIsRegular()) 
    {
      for(uint i = 0; i < poly->getNbpoints(); i++)
      {
        Point * p = new Point(mouse_x+poly->getRayon()*cos(i*(360/poly->getNbpoints())*PI/180.0),mouse_y+poly->getRayon()*sin(i*(360/poly->getNbpoints())*PI/180.0));
        poly->setPoint(p, i);      
      }
    } 
    if(poly!=nullptr && !poly->getIsRegular()) 
    {
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
      poly->setIsRegular(false);
    } 
  }
  sendExpose();
}

void MyWindow::buttonRelease(int mouse_x,int mouse_y,int button)
{
  if(button == 1 && pforme != nullptr) // Si on clique sur l'ancre d'une forme
    pforme->setAncre(mouse_x,mouse_y);
  sendExpose();
}

void MyWindow::animationReset()
{
  pforme->setCouleur(pforme->getAnimationCouleur());
  pforme->setEpaisseur(pforme->getAnimationEpaisseur());
}

void MyWindow::animationRainbow()
{
  pforme->setEpaisseur(pforme->getAnimationEpaisseur());
  if((pforme->getCouleur()!=ez_cyan) && (pforme->getCouleur()!=ez_blue) && (pforme->getCouleur()!=ez_magenta) && (pforme->getCouleur()!=ez_red) && (pforme->getCouleur()!=ez_yellow) && (pforme->getCouleur()!=ez_green)){
    pforme->setCouleur(ez_cyan);
  }
  else if(pforme->getCouleur()==ez_cyan) pforme->setCouleur(ez_blue);
  else if(pforme->getCouleur()==ez_blue) pforme->setCouleur(ez_magenta);
  else if(pforme->getCouleur()==ez_magenta) pforme->setCouleur(ez_red);    
  else if(pforme->getCouleur()==ez_red) pforme->setCouleur(ez_yellow);    
  else if(pforme->getCouleur()==ez_yellow) pforme->setCouleur(ez_green);    
  else if(pforme->getCouleur()==ez_green) pforme->setCouleur(ez_cyan);    
}

void MyWindow::animationBlink()
{
  if(pforme->getCouleur()==ez_white) pforme->setCouleur(pforme->getAnimationCouleur());
  else pforme->setCouleur(ez_white);
}

void MyWindow::animationBounce()
{
  pforme->setCouleur(pforme->getAnimationCouleur());
  if(pforme) pforme->setEpaisseur(EZDraw::random(pforme->getEpaisseur()*2)+1);
}

void MyWindow::timerNotify() // declenchee a chaque fois que le timer est ecoule.
{
  if(pforme->getAnimation()==0) animationReset();
  else{
    if(pforme->getAnimation()==1) animationRainbow();
    if(pforme->getAnimation()==2) animationBlink();
    if(pforme->getAnimation()==3) animationBounce();
    sendExpose();
    startTimer(delay);  
  }   
}

void MyWindow::switchAnimation()
{
  if(pforme){
    pforme->setCouleur(pforme->getAnimationCouleur());
    pforme->setEpaisseur(pforme->getAnimationEpaisseur());
    startTimer(delay);
    uint anim = pforme->getAnimation();
    anim = (anim + 1) % 4;
    pforme->setAnimation(anim);
  }  
}

void MyWindow::keyPress(EZKeySym keysym) // Une touche du clavier a ete enfoncee ou relachee
{
  switch (keysym)
    {
      case EZKeySym::Escape:
      case EZKeySym::q :       EZDraw::quit (); break;
      case EZKeySym::E:
        cout << calques;
        break;
      case EZKeySym::S:
      {
        ofstream f("formes.txt");
        calques.sauverCalque(f);
      } break;
      case EZKeySym::C:
      {
        ifstream f("formes.txt");
        calques.chargerCalque(f);
      } break;

      case EZKeySym::F1:
      {
        ofstream c("calques.txt");
        calques.sauver(c);
      } break;
      case EZKeySym::F2:
      {
        ifstream c("calques.txt");
        calques.charger(c);
      } break;

      //modification du délai pour l'animation
      case EZKeySym::F3: if (delay <= 975) delay += 25; break;
      case EZKeySym::F4: if (delay >= 50) delay -= 25; break;

      case EZKeySym::_0: if(pforme) pforme->setCouleur(ez_black);   break;
      case EZKeySym::_1: if(pforme) pforme->setCouleur(ez_grey);    break;
      case EZKeySym::_2: if(pforme) pforme->setCouleur(ez_red);     break;
      case EZKeySym::_3: if(pforme) pforme->setCouleur(ez_green);   break;
      case EZKeySym::_4: if(pforme) pforme->setCouleur(ez_blue);    break;
      case EZKeySym::_5: if(pforme) pforme->setCouleur(ez_yellow);  break;
      case EZKeySym::_6: if(pforme) pforme->setCouleur(ez_cyan);    break;
      case EZKeySym::_7: if(pforme) pforme->setCouleur(ez_magenta); break;

      case EZKeySym::plus: if(pforme) pforme->setEpaisseur(pforme->getEpaisseur()+1); pforme->setAncre(pforme->getAncre().getTaille()+pforme->getEpaisseur());  break;
      case EZKeySym::minus: if(pforme) pforme->setEpaisseur(pforme->getEpaisseur()-1); pforme->setAncre(pforme->getAncre().getTaille()+pforme->getEpaisseur()); break;
      case EZKeySym::o: if(pforme) pforme->setFilled(! pforme->getFilled()); break;
      case EZKeySym::Delete: if(pforme) calques.supprimerForme(pforme);      break;
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
      case EZKeySym::y: calques.creerCalque(); break;
      case EZKeySym::Left: calques.monterCalque(); break; 
      case EZKeySym::Right: calques.descendreCalque(); break;
      case EZKeySym::Up: calques.setCalqueSelec(calques.getCalqueSelec()+1); break;
      case EZKeySym::Down: calques.setCalqueSelec(calques.getCalqueSelec()-1); break;
      case EZKeySym::a:  calques.setCalqueVisible( !calques.getCalqueVisible(calques.getCalqueSelec())); break;
      case EZKeySym::d: calques.supprimerCalque(calques.getCalqueSelec()); break;
      case EZKeySym::f: calques.fusionner(); break;
      case EZKeySym::w: calques.swapFormeCalque(pforme,calques.getCalqueSelec()+1); break;
      case EZKeySym::x: calques.swapFormeCalque(pforme,calques.getCalqueSelec()-1); break;
      case EZKeySym::n: switchAnimation(); break;
      case EZKeySym::h:
      cout 
            << endl << "---------------------------AIDE-------------------------" << endl
            << "q : quitter" << endl
            << "h : cette aide" << endl
            << "E : ecrire la liste des formes sur la console" << endl
            << "S : sauve la liste des formes sur disque" << endl
            << "C : charge la liste des formes depuis le disque" << endl
            << "+ : augmente l'épaisseur"    << endl
            << "- : diminue l'épaisseur"     << endl
            << "o : switch entre le contour et le remplissage" <<endl
            << "0 : met en noir la forme"    << endl
            << "1 : met en gris la forme"    << endl
            << "2 : met en rouge la forme"   << endl
            << "3 : met en vert la forme"    << endl
            << "4 : met en bleu la forme"    << endl
            << "5 : met en jaune la forme"   << endl
            << "6 : met en cyan la forme"    << endl
            << "7 : met en magenta la forme" << endl
            << "r : crée un rectangle" << endl
            << "e : crée une ellipse" << endl
            << "s : crée un carré" << endl
            << "c : crée un cercle" << endl
            << "t : crée un triangle" << endl
            << "i : crée une image" << endl
            << "t : ajouter/supprimer la tranparence de l'image" << endl
            << "ù : agrandit la forme" << endl                      
            << "* : rapetisse la forme" << endl
            << "n : changer d'animation" << endl
            << "Suppr : supprime la forme" << endl
            
            << "--------------------------------------------------------" << endl << endl
            << "------------------------CALQUES-------------------------" << endl
            << "y : crée un nouveau calque" << endl
            << "d : supprime le calque selectionné" << endl
            << "a : affiche / masquer le calque sélectionné" << endl
            << "← : monte le calque selectionné" << endl
            << "→ : descends le calque selectionné" << endl
            << "↑ : sélectionne le calque au dessus" << endl 
            << "↓ : sélectionne le calque en dessous" << endl
            << "f : fusionner le calque sélectionné avec celui du dessus"<<endl
            << "w : envoie la forme sélectionnée sur le calque du dessus" <<endl
            << "x : envoie la forme sélectionnée sur le calque du dessous"<<endl
            ;
      break;
      case EZKeySym::r: calques.ajouterForme(new Rectangle(ez_black,getWidth()/2-25,getHeight()/2-25,getWidth()/2+25,getHeight()/2+25)); break;
      case EZKeySym::e: calques.ajouterForme(new Ellipse(ez_black,getWidth()/2-25,getHeight()/2-15,50,30)); break;
      case EZKeySym::s: calques.ajouterForme(new Carre(ez_black,getWidth()/2-25,getHeight()/2-25,50)); break;
      case EZKeySym::p: {
        uint nbpoints, rayon;
        cout << endl << "Vous êtes sur le point de créer un Polygone : "
             << endl << "Choisir le nombre de côtés : " ;
        cin >> nbpoints;
        while(nbpoints<=2){
          cout << "Erreur !, choisir un nombre de côtés > 2 : " ;
          cin >> nbpoints;
        }
        cout << endl << "Choisir le rayon : ";
        cin >> rayon;
        while(rayon<0){
          cout << "Erreur !, choisir un rayon positif : " ;
          cin >> rayon;
        }
        calques.ajouterForme(new Polygone(ez_black,getWidth()/2-25,getHeight()/2-25,rayon,nbpoints)); break;
      }
      case EZKeySym::c: calques.ajouterForme(new Cercle(ez_black,getWidth()/2-25,getHeight()/2-25,25)); break;
      case EZKeySym::i: calques.ajouterForme(new Image(ez_black,getWidth()/2-25,getHeight()/2-25,"Fallout_logo.png",1,true)); break;
      //Faudra rajouter ce constructeur pour le triangle 
      //case EZKeySym::t: formes.ajouter(new Triangle(ez_black,getWidth()/2,getHeight()/2-50,getWidth()/2-25,getHeight()/2-30,getWidth()/2+25,getHeight()/2-30)); break;
      default: break;
    }
  sendExpose();
  listeCalques();
}

//affichage dans la console des calques
void MyWindow::listeCalques(){
    cout << "------------LISTE CALQUES-----------------------" << endl;
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
    cout << "--------------------------------------------------"<<endl;
    //cout << calques.getNbCalques() << " , select :" << calques.getCalqueSelec() << endl;

}

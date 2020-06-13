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


MyWindow::MyWindow(int w, int h,const char *name)
 : EZWindow(w,h,name),calques(20),pforme(nullptr)
{}

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
  if(button==1)
    pforme = calques.isOver(mouse_x,mouse_y);
}

// Deplacement de la souris :
void MyWindow::motionNotify(int mouse_x,int mouse_y,int button)
{
  if(button == 1 && pforme != nullptr) // Si on clique sur l'ancre d'une forme
    pforme->setAncre(mouse_x,mouse_y); // on la bouge.
  sendExpose();
}

void MyWindow::buttonRelease(int mouse_x,int mouse_y,int button)
{
  if(button == 1 && pforme != nullptr) // Si on clique sur l'ancre d'une forme
    pforme->setAncre(mouse_x,mouse_y);
  sendExpose();
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
        calques.sauver(f);
      } break;
      case EZKeySym::C:
      {
        ifstream f("formes.txt");
        calques.charger(f);
      } break;
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
      case EZKeySym::Left: calques.monterCalque(); cout << "Calque monté avec succès"<<endl; break; 
      case EZKeySym::Right: calques.descendreCalque(); cout << "Calque descendu avec succès"<<endl; break;
      case EZKeySym::Up: calques.setCalqueSelec(calques.getCalqueSelec()+1); break;
      case EZKeySym::Down: calques.setCalqueSelec(calques.getCalqueSelec()-1); break;
      case EZKeySym::a:  calques.setCalqueVisible( !calques.getCalqueVisible()); break;
      case EZKeySym::f: calques.fusionner(); break;
      case EZKeySym::w: calques.swapFormeCalque(pforme,calques.getCalqueSelec()+1); break;
      case EZKeySym::x: calques.swapFormeCalque(pforme,calques.getCalqueSelec()-1); break;
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
      case EZKeySym::c: calques.ajouterForme(new Cercle(ez_black,getWidth()/2-25,getHeight()/2-25,25)); break;
      case EZKeySym::i: calques.ajouterForme(new Image(ez_black,getWidth()/2-25,getHeight()/2-25,1.0,"Fallout_logo.png")); break;
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

}

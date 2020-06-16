// MyWindow.hpp

#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP

#include "calques.hpp"

class MyWindow : public EZWindow {
  Calques calques;
  Forme  *pforme;
  uint mouseX, mouseY; //coordonnées du pointeur de la souris
  const uint marge=10;
  int point;
  uint ancre_x, ancre_y;
  int diff_x, diff_y;
 public:
  MyWindow(int w, int h,const char *name);
  ~MyWindow();

  void expose();
  void keyPress(EZKeySym keysym);
  void buttonPress(int mouse_x,int mouse_y,int button);
  void motionNotify(int mouse_x,int mouse_y,int button);
  void buttonRelease(int mouse_x,int mouse_y,int button);
  
  inline void setXY(int x, int y) { mouseX=x; mouseY=y; }
  inline bool isMouseWindow(uint x,uint y) const { return x>=marge && x<=getWidth()-marge && y>marge && y<getHeight()-marge; }

  void creerForme(string forme, bool coordAuto);

  void listeCalques();

  //méthodes relatives aux animations
  void switchAnimation();
  void animationRainbow();
  void animationBlink();
  void animationBounce();
  void animationReset();
  void timerNotify();

};

#endif

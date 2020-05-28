// main.cpp
#include <iostream>

using namespace std;

#include "ez-draw++.hpp"
#include "MyWindow.hpp"

int main()
{
 EZDraw ezDraw;
 MyWindow myWindow(800,500,"Des formes");

 ezDraw.mainLoop();

 return 0;
}

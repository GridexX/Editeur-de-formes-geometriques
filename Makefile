# Makefile pour EZ-Draw++ : version pour UNIX
#
# 01/02/2017 - Eric.Remy@univ-amu.fr

# Variables pour Unix/X11

ifeq ($(CXX),)
CXX=g++
endif
CFLAGS   = -g -Wall -pedantic -O2
CXXFLAGS = $(CFLAGS) -std=c++11
LIBS     = -lX11 -lXext
RM       = rm -f
EXE      =

OBJECTS= Point.o Forme.o Rectangle.o Formes.o
OBJECTS+= Ellipse.o Carre.o Cercle.o
OBJECTS+= MyWindow.o main.o ez-draw++.o

.PHONY:: all clean distclean

# Rajoutez vos executables C++ a la fin de EXECSPP =
#
EXECSPP = Formes$(EXE)

all :: $(EXECSPP)

# Règle générale qui indique comment compiler n'importe quel fichier XXX.cpp en un fichier XXX.o.
.cpp.o :
	$(CXX) -c $(CXXFLAGS) $*.cpp


Formes$(EXE) : $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)

depends :
	$(CXX) -MM $(CXXFLAGS) *.cpp >depends

clean ::
	$(RM) *.o core

distclean :: clean
	$(RM) $(EXECSPP)

include depends


# Makefile pour EZ-Draw++ : version pour UNIX
#
# 01/02/2017 - Eric.Remy@univ-amu.fr

# Variables pour Unix/X11

ifeq ($(CXX),)
CXX=g++
endif
CFLAGS   = -g -Wall -pedantic -O2
#Pour windows test -g -Wall -O0 -D_WIN32
CXXFLAGS = $(CFLAGS) -std=c++17
LIBS     = -lX11 -lXext
RM       = rm -f
EXE      = .exe

OBJECTS= point.o forme.o rectangle.o formes.o
OBJECTS+= ellipse.o carre.o cercle.o triangle.o polygone.o
OBJECTS+= image.o calques.o
OBJECTS+= MyWindow.o main.o ez-draw++.o


.PHONY:: all clean distclean

# Rajoutez vos executables C++ a la fin de EXECSPP =
#
EXECSPP = formes$(EXE)

all :: $(EXECSPP)

# Règle générale qui indique comment compiler n'importe quel fichier XXX.cpp en un fichier XXX.o.
.cpp.o :
	$(CXX) -c $(CXXFLAGS) $*.cpp


formes$(EXE) : $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)

depends :
	$(CXX) -MM $(CXXFLAGS) *.cpp >depends

clean ::
	$(RM) *.o core

distclean :: clean
	$(RM) $(EXECSPP)

include depends


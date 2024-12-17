# Ceci est un commentaire  
IDIR= .
ODIR= .
APPSDIR= .
CC=g++
CFLAGS=   -Wall -I$(IDIR) -c # CFLAGS défini les options de compilation.
_DEPS= $(IDIR)/robot.h $(IDIR)/graphe.h $(IDIR)/explorateur.h

_OBJS=robot.o graphe.o main.o explorateur.o

all: main.exe

main.exe: $(_OBJS)  
	$(CC) $(_OBJS) -o main.exe   

%.o: $(ODIR)/%.cpp $(_DEPS) 
	$(CC) -o $@  $(CFLAGS) $< 

%.o: $(APPSDIR)/%.cpp $(_DEPS) 
	$(CC) -o $@   $(CFLAGS) $< 

.PHONY : clean build #

clean:  
	rm -rf   *.o

build:
	mkdir build
	cp Makefile build/ #Ceci est un commentaire 
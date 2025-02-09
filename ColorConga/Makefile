# Author: Gabriel Clark \
Date: 11-26-23 \
Description: Zombie Conga Makefile \
Usage:make, make clean\


OBJS = hw5_clark_gabriel.o zombie_clark.o conga_clark.o
EXE = exe
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAG = -Wall $(DEBUG)

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)


hw5_clark_gabriel.o: linkedlist_clark.hpp zombie_clark.h zombie_clark.cpp conga_clark.h conga_clark.cpp
			$(CC) $(CFLAGS) hw5_clark_gabriel.cpp

conga_clark.o:  conga_clark.h zombie_clark.h linkedlist_clark.hpp
			$(CC) $(CFLAGS) conga_clark.cpp

zombie_clark.o: zombie_clark.h
		$(CC) $(CFLAGS) zombie_clark.cpp


clean:
	rm *.o $(EXE) -v

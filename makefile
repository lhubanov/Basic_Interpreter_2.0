# my very own makefile

main: main.o database.o GoTo.o ifclass.o
	g++ main.o database.o GoTo.o ifclass.o -o main

main.o: main.cpp 
	g++ -g -c main.cpp

database.o: database.h database.cpp
	g++ -g -c database.cpp

GoTo.o: GoTo.cpp GoTo.h
	g++ -g -c GoTo.cpp
	
ifclass.o: ifclass.cpp ifclass.h
	g++ -g -c ifclass.cpp


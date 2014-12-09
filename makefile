main: main.o program.o print.o node.o
	g++ main.o program.o print.o node.o -o main

main.o: main.cc program.h
	g++ -g -c main.cc
	
program.o: program.cc program.h
	g++ -g -c program.cc
	
print.o: print.cc print.h
	g++ -g -c print.cc

node.o: node.cc node.h
	g++ -g -c node.cc

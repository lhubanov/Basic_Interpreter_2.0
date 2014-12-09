main: main.o program.o print.o node.o input.o goto.o let.o
	g++ main.o program.o print.o node.o input.o goto.o let.o -o main

main.o: main.cc program.h
	g++ -g -c main.cc
	
program.o: program.cc program.h
	g++ -g -c program.cc
	
goto.o: goto.cc goto.h	
	g++ -g -c goto.cc
	
print.o: print.cc print.h
	g++ -g -c print.cc

let.o: let.cc let.h
	g++ -g -c let.cc
	
input.o: input.cc input.h
	g++ -g -c input.cc

node.o: node.cc node.h
	g++ -g -c node.cc

main: main.o program.o print.o node.o input.o goto.o let.o ifendif.o endif.o errors.o
	g++ main.o program.o print.o node.o input.o goto.o let.o ifendif.o endif.o errors.o -o main

main.o: main.cc program.h
	g++ -g -c main.cc
	
program.o: program.cc program.h
	g++ -g -c program.cc
	
goto.o: goto.cc goto.h
	g++ -g -c goto.cc
	
print.o: print.cc print.h
	g++ -g -c print.cc

endif.o: endif.cc endif.h
	g++ -g -c endif.cc
	
ifendif.o: ifendif.cc ifendif.h
	g++ -g -c ifendif.cc

let.o: let.cc let.h
	g++ -g -c let.cc
	
input.o: input.cc input.h
	g++ -g -c input.cc

errors.o: errors.cc errors.h
	g++ -g -c errors.cc

node.o: node.cc node.h
	g++ -g -c node.cc
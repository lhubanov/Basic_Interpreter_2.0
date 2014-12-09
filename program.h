#ifndef DATABASE_H_
#define DATABASE_H_

//contains declarations
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

#include "node.h"
#include "print.h"
#include "input.h"
#include "goto.h"
#include "let.h"

//class Node;

class Program {
	
	private:
	
	//int ThisCounter;
	
	//testing starts here
	//int FileIndex;

	//testing ends here

	public:
	
	//constructors and destructors
	Program(); //default constructor; make private, when the custom one is finished
	
	~Program(); //destructor

	//operations
	//void sort_file_to_map(std::ifstream& other); //maybe redundant, considering we have read_file
	//void evaluate_command(); //should take string command? discuss with others
		
	static std::map < int, Node* > program_map;
	static std::map < std::string, int > variable_map;
	static std::map <int, Node*>::iterator iterator_map;

	friend std::istream& operator>> (std::istream& in, Program& p);
	
	void Run();
	
	void Print_map();
};

#endif

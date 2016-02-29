/************************************************************************
 * 
 * Filename:		program.h
 * Authors:			YL,LH,PH
 * 
 * Description:		Header for the 'program.cc' file. It includes all
 * 					headers and libraries required for the execution of
 * 					the main operations within the BASIC interpreter.
 * 
 * **********************************************************************/
 
#ifndef DATABASE_H_
#define DATABASE_H_

//contains declarations
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <cctype>
//#include <locale>

#include "errors.h"
#include "node.h"
#include "print.h"
#include "input.h"
#include "goto.h"
#include "let.h"
#include "ifendif.h"
#include "endif.h"


//class Node;

class Program {
	
	private:
	
	public:
	
	//constructors and destructors
	Program();
	
	//destructor
	~Program();

		
	static std::map < int, Node* > program_map;
	static std::map < std::string, int > variable_map;
	static std::map <int, Node*>::iterator iterator_map;

	friend std::istream& operator>> (std::istream& in, Program& p);
	
	void Run();
	void Run(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i);
	
	bool is_Number (std::string& s);
	void Print_map();
};

#endif



//includes?
#ifndef NODE_H_
#define NODE_H_

#include <iostream>
//#include <fstream>
//#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

class Node {
	
	public:
		
		Node(int i, std::string f, std::string d):Instruction(i), Function(f), Data(d){};
		
		virtual void Execute(std::map<int, Node*> m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i) = 0;
		
	
	protected: 
	
		int Instruction;
		std::string Function;
		std::string Data;	
			
};

#endif

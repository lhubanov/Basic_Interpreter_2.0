#ifndef NODE_H_
#define NODE_H_

/************************************************************************
 * 
 * Filename:		node.h
 * Authors:			YL,LH,PH
 * 
 * Description:		Header for the 'Node' base-class. 
 * 					
 * **********************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>
#include "errors.h"
#include <cctype>
//#include <locale>

class Node {
	
	public:
		
		Node(int i, std::string f, std::string d):Instruction(i), Function(f), Data(d){};
		~Node(){};
		virtual void Execute(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i) = 0;
		
		void Print_Data();
		bool is_Number(std::string& s);
		bool Compare_Func(std::string data);
		bool Compare_Data(std::string data);
		
		bool FindOperatorVals(std::size_t found, int &LeftVal, int &RightVal, std::string StoredData, std::map<std::string, int> &v);

		

	protected: 

		int Instruction;
		std::string Function;
		std::string Data;
			
};

#endif

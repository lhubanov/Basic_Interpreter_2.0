/************************************************************************
 * 
 * Filename:		input.h
 * Authors:			YL,LH,PH
 * 
 * Description:		Header for the 'Input' class. 
 * 					
 * **********************************************************************/


#include <iostream>
//#include <fstream>
//#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include "node.h"
#include "errors.h"


class Input : public Node {
	
	public:
	
		Input(int temp_Inst, std::string temp_Func, std::string temp_Data);
		~Input(){};
		void Execute(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i);
		
	private:
	
	
};

//#endif

/************************************************************************
 * 
 * Filename:		goto.h
 * Authors:			YL,LH,PH
 * 
 * Description:		Header for the 'Goto' class. 
 * 					
 * **********************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "node.h"
#include "errors.h"

class Goto : public Node {
	
	public:
	
		Goto(int temp_Inst, std::string temp_Func, std::string temp_Data);
		~Goto(){};
		void Execute(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i);
		
	private:
	
	
};

//#endif

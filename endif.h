/************************************************************************
 * 
 * Filename:		endif.h
 * Authors:			YL,LH,PH
 * 
 * Description:		Header for the 'Endif' class. 
 * 					
 * **********************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "node.h"

class Endif : public Node {
	
	public:
	
		Endif(int temp_Inst, std::string temp_Func, std::string temp_Data);
		~Endif(){};
		void Execute(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i);
		
	};

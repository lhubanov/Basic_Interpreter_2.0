/************************************************************************
 * 
 * Filename:		let.h
 * Authors:			YL,LH,PH
 * 
 * Description:		Header for the 'Let' class. 
 * 					
 * **********************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "node.h"
#include <algorithm>
#include "errors.h"

class Let : public Node {
	
	public:
	
		Let(int temp_Inst, std::string temp_Func, std::string temp_Data);
		~Let(){};
		void Execute(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i);
		
	private:
	
	
};

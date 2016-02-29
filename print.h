/************************************************************************
 * 
 * Filename:		print.h
 * Authors:			YL,LH,PH
 * 
 * Description:		Header for the 'Print' class. 
 * 					
 * **********************************************************************/

#include "node.h"

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "errors.h"


//class Node;

class Print: public Node {
	
	public:
		
		Print(int temp_Inst, std::string temp_Func, std::string temp_Data);
		~Print(){};
		void Execute(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i);
		
		//friend std::ostream& operator<< (std::ostream& out, std::string Data);
	
	protected:
	
	
	private:
	
	
		
	
};


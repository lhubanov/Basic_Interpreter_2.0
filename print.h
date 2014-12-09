#include "node.h"

#include <iostream>
//#include <fstream>
//#include <sstream>
#include <string>
#include <map>
#include <cstdlib>



//class Node;

class Print: public Node {
	
	public:
		
		Print(int temp_Inst, std::string temp_Func, std::string temp_Data);
		
		void Execute(std::map<int, Node*> m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i);
	
	protected:
	
	
	private:
	
	
		
	
};

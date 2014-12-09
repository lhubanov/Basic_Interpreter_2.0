//#ifndef input_H
//#define input_H

#include <iostream>
//#include <fstream>
//#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include "node.h"
#include <algorithm>

class Let : public Node {
	
	public:
	
		Let(int temp_Inst, std::string temp_Func, std::string temp_Data);
		
		void Execute(std::map<int, Node*> m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i);
		
	private:
	
	
};

//#endif

#include <iostream>
//#include <fstream>
//#include <sstream>
#include <string>
#include <map>
#include <cstdlib>


class Input{
	
	public:
		Input(int temp_Inst, std::string temp_Func, std::string temp_Data);
		
		void Execute(std::map<int, Node*> m, std::map<std::string, int> v);
		
	private:
	
	
};

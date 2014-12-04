#include "ifclass.h"



ifclass::ifclass(STL_Map map, std::string data)
{
	//first thing to do is evaluate the string for data
	
	std::string CheckOperator;
	
	//first check for the '=' sign
	
	
	CheckOperator = "=";
	std::size_t found;
	found = data.find(CheckOperator);
	
	if(found!=std::string::npos)
	{
		//found the '=' operator
		//separate the contents of the data.
		
		std::string var1, var2;
		
		//var1.copy(data, 1, found);
		
		var1 = data.substr(0, (int)found);
		std::cout << "Data is: " << data << " var1 is :" << var1 << std::endl;
		
	}
	
}

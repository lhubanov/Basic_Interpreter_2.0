#include "input.h"

Input::Input(int temp_Inst, std::string temp_Func, std::string temp_Data):Node(temp_Inst, temp_Func, temp_Data) 
{
	std::cout << "Input Constructor- inst, func, data are: " << temp_Inst << temp_Func << temp_Data << std::endl;	
}

void Input::Execute(std::map<int, Node*> m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i )
{
	std::cout << "Input Execute called" << std::endl;		
	
	std::string temp;
	std::cin >> temp;
	Data.erase((Data.length()-1), 1);
	
	if (atoi(temp.c_str()) != 0) //if correct
	{
		//check if the (data) already exists..
		int temp_val = atoi(temp.c_str());
		v[Data] = temp_val;
		
		std::cout << "I set v[Data] now" << std::endl;
		std::cout << v[Data] << std::endl;
	}
	else
	{
		std::cout << "ERROR: INPUT HAS TO BE AN INTEGER" << std::endl;
	}
	
	//std::cout << Data << std::endl; 

}

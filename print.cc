#include "print.h"

Print::Print(int temp_Inst, std::string temp_Func, std::string temp_Data):Node(temp_Inst, temp_Func, temp_Data) 
{
	std::cout << "Print Constructor- inst, func, data are: " << temp_Inst << temp_Func << temp_Data << std::endl;	
}

void Print::Execute(std::map<int, Node*> m, std::map<std::string, int> v)
{
	std::cout << "Print Execute called" << std::endl;		
	
	std::cout << Data << std::endl; 

}

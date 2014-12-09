#include "goto.h"

Goto::Goto(int temp_Inst, std::string temp_Func, std::string temp_Data):Node(temp_Inst, temp_Func, temp_Data) 
{
	std::cout << "Goto Constructor- inst, func, data are: " << temp_Inst << temp_Func << temp_Data << std::endl;	
}

void Goto::Execute(std::map<int, Node*> m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i )
{
	int temp;
	

	
	if (atoi(Data.c_str()) != 0)
	{

		temp = atoi(Data.c_str());
	
		if(m.find(temp) != m.end())
		{
			i = m.find(temp);
		}
	}
	
	else
	{
		std::cout << "I AM SO MAD" << std::endl;
	}

}

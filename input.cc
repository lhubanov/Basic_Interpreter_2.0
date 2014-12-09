#inlude "input.h"

Input::Input(int temp_Inst, std::string temp_Func, std::string temp_Data):Node(temp_Inst, temp_Func, temp_Data) 
{
	std::cout << "Input Constructor- inst, func, data are: " << temp_Inst << temp_Func << temp_Data << std::endl;	
}

void Input::Execute(std::map<int, Node*> m, std::map<std::string, int> v)
{
	std::cout << "Input Execute called" << std::endl;		
	
	std::string temp;
	
	
	std::cin >> temp;
	
	if (atoi(temp.c_str()) != 0) //if correct
	{
		//check if the (data) already exists..
		int temp_val = atoi(temp.c_str())
		v[temp_Data] = temp_val;
	}
	else
	{
		std::cout << "ERROR: INPUT HAS TO BE AN INTEGER" << std::endl;
	}
	
	std::cout << Data << std::endl; 

}

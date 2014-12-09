#include "program.h"

std::map < int, Node* > Program::program_map;
std::map < std::string, int > Program::variable_map;

int trace = 1;

Program::Program()
{
	//set to null?
	if (trace)
		std::cout << "Default constructor called" << std::endl;
}


Program::~Program()
{
	//stuff?

	if (trace)
		std::cout << "Destructor called" << std::endl;
		
	
	/*
	for (std::map<int, *Node>::iterator it = Program_Map.begin(); it != Program_Map.end(); it++)
	{
		delete Program_Map[it->first];
	}
	*/
	
};



std::istream& operator >> (std::istream& in, Program& p)
{
	std::string temp_string;
	std::string temp_iss;

	int temp_Inst;
	std::string temp_Func;
	std::string temp_Data;

	while (true)
	{
		//break if eof
		//Note: still doesn't break on time and creates one more instance in the map
		if (in.eof()) break;

		//sort file to map
		int while_counter = 1;

		getline(in, temp_string);
		std::istringstream iss(temp_string);

		while (iss >> temp_iss)
		{
			if (while_counter == 1 && atoi(temp_iss.c_str()) != 0)
			{
				temp_Inst = atoi(temp_iss.c_str());

				if (trace)
					std::cout << "Insts: " << temp_Inst << std::endl;
			}

			if (while_counter == 2)
			{
				temp_Func = temp_iss;

				if (trace)
					std::cout << "Functs: " << temp_Func << std::endl;
			}

			if (while_counter > 2)
			{
				temp_Data.append(temp_iss);
				temp_Data.append(" ");

				if (trace)
					std::cout << "Data: " << temp_Data << std::endl;
			}
			while_counter++;
		}

		/*
		if (p.temp_Func == "GOTO")
		{
			
		
			p.Program_Map[p.temp_Inst] = new GOTO(p.temp_Inst, p.temp_Func, p.temp_Data);
		
		}
		
		if (p.temp_Func == "IF")
		{
			
			
			p.Program_Map[p.temp_Inst] = new IFELSE(p.temp_Inst, p.temp_Func, p.temp_Data);
		}
		
		*/
		
		if (temp_Func == "PRINT")
		{
			//PRINT Print(p.temp_Inst, p.tempFunc, p.temp_Data);
			
			p.program_map[temp_Inst] = new Print(temp_Inst, temp_Func, temp_Data);
		}
		
		if (temp_Func == "INPUT")
		{
			p.program_map[temp_Inst] = new Input(temp_Inst, temp_Func, temp_Data);
		}

	};

}

void Program::Run()
{
	if (trace)
		std::cout << "Calling Program Run" << std::endl;
		
	//Node test_p (1,"2","3");
	//test_p = &program_map[10];	
	program_map[10]->Execute(program_map, variable_map);
}





void Program::Print_map()
{
	if (trace)
		std::cout << "Map printing function called" << std::endl;

	//This check should exist somewhere else anyway
	if (program_map.empty())
		std::cout << "WE HAVE A PROBLEM!!!" << std::endl;


	for (std::map<int, Node*>::iterator it = program_map.begin(); it != program_map.end(); it++)
	{
		std::cout << it->first << " " << it->second;
		
		std::cout << "\n";
	}
	
	
	if (variable_map.empty())
		std::cout << "WE HAVE A PROBLEM!!!" << std::endl;


	for (std::map<std::string, int>::iterator it = variable_map.begin(); it != variable_map.end(); it++)
	{
		std::cout << it->first << " " << it->second;
		
		std::cout << "\n";
	}
	
	
	
}





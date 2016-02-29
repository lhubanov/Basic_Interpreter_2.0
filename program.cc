/************************************************************************
 * 
 * Filename:		program.cc
 * Authors:			YL,LH,PH
 * 
 * Description:		Most of the functionality of the interpreter is 
 * 					handled here. The file is sorted and stored through
 * 					the overloaded input operator. 
 * 
 * 					The Execution of the code in BASIC from the file
 * 					is handled within the 'Run' function. 
 * 					The file also contains a secondary 'Run' function
 * 					which is only called, when an IF statement is found.
 * 					It takes references to the arguments, used by the 
 * 					top-level 'Run' (maps and iterator).
 * 
 * 					Additionally, the 'is_Number' function is used for
 * 					evaluating if a given argument is an integer or not,
 * 					as the built-in 'atoi' function is unreliable in some
 * 					cases. The 'Print_map' function is used only for
 * 					debugging purposes.
 * 
 * **********************************************************************/
#include "program.h"
 
std::map < int, Node* > Program::program_map;
std::map < std::string, int > Program::variable_map;
std::map < int, Node* >::iterator Program::iterator_map;

int trace = 0;
static int depth = 0;

//Default Constructor
Program::Program()
{
	if (trace)
		std::cout << "Default constructor called" << std::endl;
}

//Destructor
Program::~Program()
{
	if (trace)
		std::cout << "Destructor called" << std::endl;
		
	//Destroy the map content only within the base program
	if (depth == 0)
	{
		for (std::map<int, Node*>::iterator it = program_map.begin(); it != program_map.end(); ++it)
		{
			delete it->second;
			it->second = 0;
		}
	}
	
}

//Function evaluating if a string is an int
bool Program::is_Number(std::string& s)
{
	std::string::const_iterator it = s.begin();
    while (it != s.end() && (std::isdigit(*it))) ++it;
    return !s.empty() && it == s.end();
}

//INPUT FILE SORTING
std::istream& operator >> (std::istream& in, Program& p)
{
	std::string temp_string;
	std::string temp_iss;

	int temp_Inst;
	std::string temp_Func;
	std::string temp_Data;

	while (!in.eof())
	{
		int while_counter = 1;

		getline(in, temp_string);
		std::istringstream iss(temp_string);

		while (iss >> temp_iss)
		{
			if (while_counter == 1 && p.is_Number(temp_iss))
			{
				//std::cout << "1 temp_Inst: " << temp_Inst << std::endl;
				temp_Inst = atoi(temp_iss.c_str());

				if (trace)
					std::cout << "Insts: " << temp_Inst << std::endl;
			}

			else if (while_counter == 2)
			{
				temp_Func = temp_iss;

				if (trace)
					std::cout << "Functs: " << temp_Func << std::endl;
			}

			else if (while_counter > 2)
			{
				temp_Data.append(temp_iss);
				temp_Data.append(" ");

				if (trace)
					std::cout << "Data: " << temp_Data << std::endl;
			}
			
			else if (!p.is_Number(temp_iss))
			{
			std::string errorMessage = "FILE ERROR: Line number is either missing or not an integer!";
			BadFileException ex(1, errorMessage);
			throw ex;
			}		
			while_counter++;
		}

		if(temp_Data == "" && !in.eof() && temp_Func != "ENDIF")
		{
			std::string errorMessage = "SYNTAX ERROR: Data missing! Check if you've entered a blank line.";
			BadFileException ex(1, errorMessage);
			throw ex;
		}
				
		if (temp_Func == "PRINT")
		{		
			p.program_map[temp_Inst] = new Print(temp_Inst, temp_Func, temp_Data);
		}
		
		else if (temp_Func == "INPUT")
		{
			p.program_map[temp_Inst] = new Input(temp_Inst, temp_Func, temp_Data);
		}
		
		else if(temp_Func == "GOTO")
		{

			p.program_map[temp_Inst] = new Goto(temp_Inst, temp_Func, temp_Data);
		}
		
		else if(temp_Func == "LET")
		{
			p.program_map[temp_Inst] = new Let(temp_Inst, temp_Func, temp_Data);
		}
		
		else if(temp_Func == "IF")
		{
			p.program_map[temp_Inst] = new Ifendif(temp_Inst, temp_Func, temp_Data);
		}
		
		else if(temp_Func == "ENDIF")
		{
			p.program_map[temp_Inst] = new Endif(temp_Inst, temp_Func, temp_Data);
		}
		
		else if(!in.eof())
		{
			std::string errorMessage = "FILE ERROR: File contains unknown instruction!";
			BadFileException ex(1, errorMessage);
			throw ex;
		}
		
		temp_Inst = 0;
		temp_Func.clear();
		temp_Data.clear();
	};

}

//PRIMARY RUN
void Program::Run()
{
	depth++;
	if (trace)
	{
		std::cout << "Calling Program Run" << std::endl;
		std::cout << "Current depth of the program is: " << depth << std::endl;		
	}
	
	//check for endif statement - if found report an error in this func	
	//this is because this instance of 'Run' does not expect to see an 'ENDIF' line.
	bool temp = 1; //used for comparison
	
	for (iterator_map = program_map.begin(); iterator_map != program_map.end();)
	{
		if(temp == program_map[iterator_map->first]->Compare_Data("ENDIF"))  //checks if there's an ENDIF without an IF
		{
			std::string errorMessage = "SYNTAX ERROR: ENDIF found without an IF!";
			BadIfException ex(1, errorMessage);
			throw ex;
		}
		else
		{
		program_map[iterator_map->first]->Execute(program_map, variable_map, iterator_map);		//execute instruction
		}
	}
	
	if (trace)
		std::cout << "Exiting Current Depth " << depth  << std::endl;
	depth--;
}

//NESTED RUN
void Program::Run(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i)
{
	depth++;
	
	if (trace)
	{
		std::cout << "Calling Nested Program Run!" << std::endl;
		std::cout << "Current Depth - Program " << depth  << std::endl;	
	}
		
	bool True = 1;		//used for comparison

	while ((i != m.end()) && (True != m[i->first]->Compare_Data("ENDIF")))
	{
		program_map[i->first]->Execute(m, v, i);
	
	}
	
	if (i == m.end())
	{
		std::string errorMessage = "SYNTAX ERROR: No ENDIF was found for a previously set IF!";
		BadIfException ex(1, errorMessage);
		throw ex;
	}
	
	if (True == m[i->first]->Compare_Data("ENDIF"))
	{
		program_map[i->first]->Execute(m, v, i);
	}
	

	if(trace)
		std::cout << "Exiting Current Depth - Program " << depth  << std::endl;
	depth--;
	
}

//DEBUG ONLY
void Program::Print_map()
{
	if (trace)
		std::cout << "Map printing function called" << std::endl;

	//This check should exist somewhere else anyway
	if (program_map.empty())
		std::cout << "Map is empty, we have a problem!!!" << std::endl;


	for (std::map<int, Node*>::iterator it = program_map.begin(); it != program_map.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
		program_map[it->first]->Print_Data();
		
		std::cout << "\n";
	}
	
	
	if (variable_map.empty())
		std::cout << "Map is empty, we have a problem!!!" << std::endl;


	for (std::map<std::string, int>::iterator it = variable_map.begin(); it != variable_map.end(); it++)
	{
		std::cout << it->first << " " << it->second;
		
		std::cout << "\n";
	}	
}

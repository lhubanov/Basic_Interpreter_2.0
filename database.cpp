#include "database.h"

int trace = 0;

Database::Database()
{
	//set to null?
	if (trace)
		std::cout << "Default constructor called" << std::endl;
}

Database::Database(std::ifstream& other)
{
	int test_size = 0;
	if (trace)
		std::cout << "Custom constructor called" << std::endl;
	
	STL_Map test_map;		//is this how you call a default constructor?
	sort_file_to_map(other, test_map);

	test_map.Print_map();

	test_size = test_map.Get_Size_of_Ctr_to_Inst();
	int cntr = test_map.Get_Ctr_by_Inst(40);

	int testingIf;
	testingIf = test_map.Find_Next_Endif(test_map.Get_Ctr_by_Inst(30));

	std::cout << "testing if, ENDIF on: " << testingIf << std::endl;

}

Database::~Database()
{
	//stuff?

	if (trace)
		std::cout << "Destructor called" << std::endl;
};

//-------------------------------------------------------------

void Database::sort_file_to_map(std::ifstream& other, STL_Map& map)
{
	i = 0;//description

	while (true)
	{
		//break if eof
		//Note: still doesn't break on time and creates one more instance in the map
		if (other.eof()) break;

		//sort file to map
		int while_counter = 1;

		getline(other, temp_string);
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

		map.Set_Inst_by_Ctr(i, temp_Inst);
		map.Set_Func_by_Inst(temp_Inst, temp_Func);
		map.Set_Data_by_Inst(temp_Inst, temp_Data);

		temp_Inst = 0;
		temp_Func.clear();
		temp_Data.clear();

		i++;

	};

	map.Set_Variable("Dave", 5);

}


//*************************************************
//Map stuff
//*************************************************

STL_Map::STL_Map()
{
	if (trace)
		std::cout << "Map Default constructor called" << std::endl;
};

STL_Map::~STL_Map()
{
	if (trace)
		std::cout << "Map Default destructor called" << std::endl;
}


//All of the three below could be a template func,
//which takes a map and a key and contents, the latter two, can be templated

void STL_Map::Set_Inst_by_Ctr(int key, int contents)
{
	Ctr_to_Inst[key] = contents;

	if (trace)
		std::cout << "Map Set_Inst_by_Ctr called" << std::endl;
}

void STL_Map::Set_Func_by_Inst(int key, std::string contents)
{
	Inst_to_Func[key] = contents;

	if (trace)
		std::cout << "Map Set_Func_by_Inst called" << std::endl;
}

void STL_Map::Set_Data_by_Inst(int key, std::string contents)
{
	Inst_to_Data[key] = contents;

	if (trace)
		std::cout << "Map Set_Data_by_Inst called" << std::endl;
}

void STL_Map::Print_map()
{
	if (trace)
		std::cout << "Map printing function called" << std::endl;

	//This check should exist somewhere else anyway
	if (Ctr_to_Inst.empty())
		std::cout << "WE HAVE A PROBLEM!!!" << std::endl;


	for (std::map<int, int>::iterator it = Ctr_to_Inst.begin(); it != Ctr_to_Inst.end(); it++)
	{
		std::cout << it->first << " " << it->second;
		std::cout << " " << Inst_to_Func[it->second];
		std::cout << " " << Inst_to_Data[it->second];
		std::cout << "\n";
	}
}

//int Get_Inst_by_Ctr(int key, int contents);
//std::string Get_Func_by_Inst(int key, std::string contents);
//std::string Get_Data_by_Inst(int key, std::string contents);

//Variables map
void STL_Map:: Set_Variable(std::string key, int contents)
{
	variables[key] = contents;

	if (trace)
		std::cout << "Map Set_Variables called" << std::endl;
		std::cout << variables[key] << std::endl;
}

//TODO: Template these
int STL_Map::Get_Size_of_Ctr_to_Inst ()
{
	if (trace)
		std::cout << "Map Get_Size_of_Ctr_to_Inst called" << std::endl;

	return Ctr_to_Inst.size();
}


//Template or reference?
int STL_Map::Get_Ctr_by_Inst(int Inst)
{
	int sizesize = Get_Size_of_Ctr_to_Inst();
	
	for (int j(0); j <= sizesize; j++)
	{
		if (Ctr_to_Inst[j] == Inst)
		{
			if (trace)
				std::cout << "Map Found Ctr by Inst" << std::endl;
		
			std::cout << "return i, data is " << Ctr_to_Inst[j] << std::endl;
			return j;
		}	
	}

	if (trace)
		std::cout << "Map Did not find Ctr by Inst, ERROR" << std::endl;
	
	return Get_Size_of_Ctr_to_Inst();	
}


int STL_Map::Find_Next_Endif(int Inst)
{

	int size1 = Get_Size_of_Ctr_to_Inst(); //perhaps make this -1 (do test)
	int size2 = Get_Inst_by_Ctr(size1-1);
	std::cout << size1 << " " << size2 << std::endl;

	int Counter = Inst;
	int IteratorInstruction = Get_Inst_by_Ctr(Counter);

	std::cout << IteratorInstruction << std::endl;
	std::cout << Counter << std::endl;	
	
	for (IteratorInstruction; IteratorInstruction <= size2;  )
	{
		std::cout << Inst_to_Func[IteratorInstruction] << std::endl;
		std::cout << "The iterator value: " << Counter << "Instruction is: " << IteratorInstruction << std::endl;
		if (Inst_to_Func[IteratorInstruction] ==  "ENDIF")
		{
			if (trace)
				std::cout << "Map Found Ctr by Inst" << std::endl;

			//std::cout << "return counter, data is " << Inst_to_Func[counter] << std::endl;
			return Counter; //return counter OR Instruction
		}

		Counter++;
		IteratorInstruction = Get_Inst_by_Ctr(Counter);
	}

	if (trace)
		std::cout << "Map Did not find Ctr by Inst, ERROR" << std::endl;

	return Get_Size_of_Ctr_to_Inst(); //throw error / else return last counter.
}

int STL_Map::Get_Inst_by_Ctr(int Ctr)
{
	return Ctr_to_Inst[Ctr];
}

//contains declarations
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>


class STL_Map {
protected:
	//maps; could be protected also; doesn't matter?

	std::map < int, int >			Ctr_to_Inst;
	std::map < int, std::string >	Inst_to_Func;
	std::map < int, std::string >	Inst_to_Data;
	std::map < std::string, int >	variables;


public:
	//constructors and destructors

	STL_Map();//Default constructor
	~STL_Map();//Destructor

	void Print_map();

	//Functions to change the value of a map member
	void Set_Inst_by_Ctr(int key, int contents);
	void Set_Func_by_Inst(int key, std::string contents);
	void Set_Data_by_Inst(int key, std::string contents);
	void Set_Variable(std::string key, int contents);

	//Functions to read the maps

	//TODO: make more general for checking the size all of the maps in the STL_Map class
	int Get_Size_of_Ctr_to_Inst();			
	int Get_Ctr_by_Inst(int Inst);

	int			Get_Inst_by_Ctr(int Ctr);
	std::string Get_Func_by_Inst(int Inst);	//should return the Func - a String?
	std::string Get_Data_by_Inst(int Inst);	//should return the Data - a String?

	int Find_Next_Endif(int Inst);	


	//get/set VARIABLES map functions?
};

class Database {
private:

	//testing starts here
	int i;
	std::string temp_string;
	std::string temp_iss;

	int temp_Inst;
	std::string temp_Func;
	std::string temp_Data;
	//testing ends here

public:
	//constructors and destructors
	Database(); //default constructor; make private, when the custom one is finished
	Database(std::ifstream& other); //custom constructor; Will this work?
	//Database(const Database& other); //copy constructor?
	~Database(); //destructor

	//operations
	void sort_file_to_map(std::ifstream& other, STL_Map& map); //maybe redundant, considering we have read_file
	//void evaluate_command(); //should take string command? discuss with others
};

/************************************************************************
 * 
 * Filename:		input.cc
 * Authors:			YL,LH,PH
 * 
 * Description:		Input.cc is responsible for processing input and
 * 					storing it into variables set in the BASIC code.
 * 
 * 					The c file includes the default constructor.
 * 					All operations are done in the Execute function.
 * 
 * **********************************************************************/
 
#include "input.h"

Input::Input(int temp_Inst, std::string temp_Func, std::string temp_Data):Node(temp_Inst, temp_Func, temp_Data) 
{
	//std::cout << "Input Constructor- inst, func, data are: " << temp_Inst << temp_Func << temp_Data << std::endl;	
}

void Input::Execute(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i )
{	
	std::string StoredData = Data;
	
	//input is stored temporarily as a string
	std::string temp;
	std::cin >> temp;
	StoredData.erase((StoredData.length()-1), 1); //removing last white space.
	
	//check if the provided data is an int
	if (is_Number(temp))
	{
		//stored if check is successful
		int temp_val = atoi(temp.c_str());
		v[StoredData] = temp_val;
	}
	
	//input is not an int, error is thrown
	else
	{
		std::string errorMessage = "INPUT ERROR: Input can only be a non-zero integer value!";
		BadInputException ex(1, errorMessage);
		throw ex;
	}
	
	i++;
}

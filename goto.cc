/************************************************************************
 * 
 * Filename:		goto.cc
 * Authors:			YL,LH,PH
 * 
 * Description:		Goto.cc is responsible for executing the correct
 * 					sequence based on a given line number. This is done
 * 					through comparing the stored line numbers with
 * 					the given line number in the BASIC code.
 * 
 * 					The c file includes the default constructor.
 * 					All operations are done in the Execute function.
 * 
 * **********************************************************************/
 
#include "goto.h"

Goto::Goto(int temp_Inst, std::string temp_Func, std::string temp_Data):Node(temp_Inst, temp_Func, temp_Data) 
{
	//std::cout << "Goto Constructor- inst, func, data are: " << temp_Inst << temp_Func << temp_Data << std::endl;	
}

void Goto::Execute(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i )
{
	int temp;

	std::string StoredData = Data; //temp data to not alter stored data
		
	std::string::iterator end_pos = std::remove(StoredData.begin(), StoredData.end(), ' ');
	StoredData.erase(end_pos, StoredData.end());	//remove any ws from the data for processing

	//evaluates if the given line number is an integer
	if (is_Number(StoredData))
	{
		temp = atoi(StoredData.c_str());
		//finds the provided line number
		if(m.find(temp) != m.end())
		{
			i = m.find(temp);
		}
		
		else
		{
			std::string errorMessage = "GOTO ERROR: Given line number does not exist!";
			BadGotoException ex(1, errorMessage);
			throw ex;
		}
	}
	
	else
	{
		std::string errorMessage = "GOTO ERROR: Line numbers can only be integers!";
		BadGotoException ex(1, errorMessage);
		throw ex;
	}
	
	
}

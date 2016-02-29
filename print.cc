/************************************************************************
 * 
 * Filename:		print.cc
 * Authors:			YL,LH,PH
 * 
 * Description:		Print.cc is responsible for printing out the stored
 * 					data requested in the BASIC code. The c file includes
 * 					the default constructor. All operations are done in
 * 					the Execute function.
 * 
 * **********************************************************************/
#include "print.h"

Print::Print(int temp_Inst, std::string temp_Func, std::string temp_Data):Node(temp_Inst, temp_Func, temp_Data) 
{
	//std::cout << "Print Constructor- inst, func, data are: " << temp_Inst << temp_Func << temp_Data << std::endl;	
}

void Print::Execute(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i)
{
	//copies the data string and uses a local copy for the operation
	std::string StoredData = Data;
	StoredData.erase((StoredData.length()-1), 1); //removing white space
	
	//checks for quotation marks
	if (StoredData.compare(0,1,"\"") == 0 && StoredData.compare((StoredData.length()-1),1,"\"") == 0)
	{
		StoredData.erase((StoredData.length()-1), 1);
		StoredData.erase(0,1);
		
		if(StoredData == "") //null?
		{
			std::string errorMessage = "SYNTAX ERROR: Empty string!";
			BadPrintException ex(1, errorMessage);
			throw ex;
		}
		
		//print character by character and check for new lines
		for (int charCounter(0); charCounter < (StoredData.length()); charCounter++)
		{
	
			if(StoredData.compare(charCounter, 1, "\\") == 0 && charCounter < StoredData.length())
			{
				if(StoredData.compare((charCounter+1), 1, "n") == 0)
				{
					std::cout << "\n";
					charCounter++;
				}
			}
			else
			{
				std::cout << StoredData.at(charCounter);
			}	
		}
	}
	
	else
	{
		std::map<std::string, int>::iterator iter;
		iter = v.find(StoredData);
	
		if(iter != v.end())
		{
			int temp_value = v[StoredData];
			std::cout << temp_value;
		}
		
		else
		{
			//double quotation marks are missing
			std::string errorMessage = "PRINT SYNTAX ERROR: Either quotation marks are missing in the PRINT function or a variable of that name does not exist!";
			BadPrintException ex(1, errorMessage);
			throw ex;
		}
	}
	i++;
}

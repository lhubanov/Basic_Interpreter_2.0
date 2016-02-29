/************************************************************************
 * 
 * Filename:		ifendif.cc
 * Authors:			YL,LH,PH
 * 
 * Description:		Ifendif.cc is responsible for executing the correct
 * 					sequence based on a given condition. This is done
 * 					through evaluating the '=', '<' and the '>' cases of
 * 					the stored variables named in the BASIC code.
 * 
 * 					The c file includes the default constructor.
 * 					All operations are done in the Execute function.
 * 
 * **********************************************************************/
 
#include "ifendif.h"

Ifendif::Ifendif(int temp_Inst, std::string temp_Func, std::string temp_Data):Node(temp_Inst, temp_Func, temp_Data) 
{
	//std::cout << "Ifendif Constructor- inst, func, data are: " << temp_Inst << temp_Func << temp_Data << std::endl;	
}

void Ifendif::Execute(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i )
{
	std::string StoredData = Data;
	
	//Search if a "THEN" exists
	std::string findThen = "THEN";
	std::size_t foundThen = StoredData.find(findThen);
	if (foundThen!=std::string::npos)
	{
		//we have the starting position of 'THEN'
		//we check to see if there's anything else written after 'THEN'.
		if((foundThen + 5) != StoredData.length())
		{
			//there is something written after THEN. Therefore an error is found.
			std::string errorMessage = "IF SYNTAX ERROR: Unexpected character found";
			BadIfException ex(1, errorMessage);
			throw ex;
		}
		else
		{
			 //remove 'THEN'
			 StoredData.erase (foundThen,4);  
		}
	}
	else
	{   
		//if 'THEN' is not found, throw an error
		std::string errorMessage = "IF SYNTAX ERROR: THEN is missing";
		BadIfException ex(1, errorMessage);
		throw ex;
	}
	
	//remove unnecessary spaces from the data	
	std::string::iterator end_pos = std::remove(StoredData.begin(), StoredData.end(), ' ');
	StoredData.erase(end_pos, StoredData.end());
	
	//temporary variables used to interpret the IF conditions
	std::string Ev_Val;
	std::string Left_Val;
	std::string Right_Val;
	
	std::map<std::string, int>::iterator i_temp; 	//iterator of the variable map, used for searching
	int iLeftVal, iRightVal, Result;				//integer values of the evaluated strings
	
	//search for the operators
	std::size_t found_equal = StoredData.find("=");			//search for the = operator
	std::size_t found_greaterT = StoredData.find(">");		//search for the > operator
	std::size_t found_smallerT = StoredData.find("<");		//search for the < operator
	
	bool IfTrue = false;
	
	//evaluation if the values are equal to each other
	if (found_equal!=std::string::npos)		//if the equals is found	
	{
		
		if(FindOperatorVals(found_equal, iLeftVal, iRightVal, StoredData, v) == 0)		//provide the position of the equals and evaluate data
		{
			std::string errorMessage = "IF SYNTAX ERROR: Problem with the provided conditions!";
			BadIfException ex(1, errorMessage);
			throw ex;
		}
		//evaluated result

		IfTrue = iRightVal == iLeftVal;
	}
	
	//evaluation if one value is greater than the other
	else if (found_greaterT!=std::string::npos)
	{

		if(FindOperatorVals(found_greaterT, iLeftVal, iRightVal, StoredData, v) == 0)
		{
			std::string errorMessage = "IF SYNTAX ERROR: Problem with the provided conditions!";
			BadIfException ex(1, errorMessage);
			throw ex;
		}
		//evaluated result
		IfTrue = iLeftVal > iRightVal;
	}
	
	//evaluation if one value is smaller than the other
	else if (found_smallerT!=std::string::npos)
	{
		if(FindOperatorVals(found_smallerT, iLeftVal, iRightVal, StoredData, v) == 0)
		{
			std::string errorMessage = "IF SYNTAX ERROR: Problem with the provided conditions!";
			BadIfException ex(1, errorMessage);
			throw ex;
		}
		
		//evaluated result
		IfTrue =  iLeftVal < iRightVal;	
	}
	
	//no operation was recognized
	else
		{	
			std::string errorMessage = "IF SYNTAX ERROR: Unexpected condition!";
			BadIfException ex(1, errorMessage);
			throw ex;
		}
		
	//if the condition is true
	//instantiate a new Program object, which will handle all operations between this IF call and the first ENDIF found
	if (IfTrue)
	{
		//create new program with the iterator reference passed.
		Program Ifp;
		i++;
		Ifp.Run(m, v, i);	
	}
	
	//if the condition is false
	//increment the iterator until an ENDIF is found
	else
	{	
		//create new program with the iterator reference passed.
		int ifCtr = 1;
		bool temp = 1;
		bool j = 1;
		
			
		while (i != m.end() && ifCtr > 0) 
		{
			i++;
			
			if(temp == m[i->first]->Compare_Data("ENDIF"))
			{
				ifCtr--;
			}
			
			if(temp == m[i->first]->Compare_Func("IF"))
			{
				ifCtr++;
			}

		}
		
		if(i != m.end())
		{
			i++;
		}
		
		else
		{	
			std::string errorMessage = "IF ERROR: No ENDIF found!";
			BadIfException ex(1, errorMessage);
			throw ex;
		}
		
	}
}

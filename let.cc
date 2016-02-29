/************************************************************************
 * 
 * Filename:		let.cc
 * Authors:			YL,LH,PH
 * 
 * Description:		Let.cc is responsible for all math operations with
 * 					the stored variables requested in the BASIC code.
 * 					Those include +, -, *, /, and basic assignment.
 * 
 * 					The c file includes the default constructor.
 * 					All operations are done in the Execute function.
 * 
 * **********************************************************************/
#include "let.h"

Let::Let(int temp_Inst, std::string temp_Func, std::string temp_Data):Node(temp_Inst, temp_Func, temp_Data) 
{
	//std::cout << "Let Constructor- inst, func, data are: " << temp_Inst << temp_Func << temp_Data << std::endl;	
}

void Let::Execute(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i )
{
	std::string StoredData = Data; //temp data to not alter stored data
		
	std::string::iterator end_pos = std::remove(StoredData.begin(), StoredData.end(), ' ');
	StoredData.erase(end_pos, StoredData.end());	//remove any ws from the data for processing
	
	//check if Ev_Val is a string..
	std::string Ev_Val;
	std::map<std::string, int>::iterator i_temp;
	int iLeftVal, iRightVal, Result;
	
	std::size_t found_equal = StoredData.find("=");

	
	if (found_equal!=std::string::npos)
	{
		Ev_Val = StoredData.substr(0, found_equal);
		StoredData.erase (0, found_equal+1); 
	}
	else
	{
		//equals not found in let - error 
		std::string errorMessage = "LET SYNTAX ERROR: no equals found";
		BadLetException ex(1, errorMessage);
		throw ex;
	}
	
	std::size_t found_plus = StoredData.find("+");
	std::size_t found_minus = StoredData.find("-");
	std::size_t found_times = StoredData.find("*");
	std::size_t found_divide = StoredData.find("/");
	
	std::string Left_Val;
	std::string Right_Val;
	
	//addition found
	if (found_plus!=std::string::npos)
	{

		if(FindOperatorVals(found_plus, iLeftVal, iRightVal, StoredData, v) == 0)
		{
			std::string errorMessage = "LET ERROR: Problem with addition operation";
			BadLetException ex(1, errorMessage);
			throw ex;
		}
		
		Result = iLeftVal + iRightVal;	
		
		v[Ev_Val] = Result;	
		
	}
	
	//subtraction found
	else if(found_minus!=std::string::npos)
	{
		
		if(FindOperatorVals(found_minus, iLeftVal, iRightVal, StoredData, v) == 0)
		{
			std::string errorMessage = "LET ERROR: Problem with subtraction operation";
			BadLetException ex(1, errorMessage);
			throw ex;
		}
		
		Result = iLeftVal - iRightVal;	
		
		v[Ev_Val] = Result;
	
	}
	
	//multiplication found
	else if(found_times!=std::string::npos)
	{
		
		if(FindOperatorVals(found_times, iLeftVal, iRightVal, StoredData, v) == 0)
		{
			std::string errorMessage = "LET ERROR: Problem with multiplication operation";
			BadLetException ex(1, errorMessage);
			throw ex;
		}
		Result = iLeftVal * iRightVal;
		v[Ev_Val] = Result;
		
	}
	
	//division found
	else if(found_divide!=std::string::npos)
	{
		
		if(FindOperatorVals(found_divide, iLeftVal, iRightVal, StoredData, v) == 0)
		{
			std::string errorMessage = "LET ERROR: Problem with division operation";
			BadLetException ex(1, errorMessage);
			throw ex;
		}
		
		Result = iLeftVal / iRightVal;	
		v[Ev_Val] = Result;
		
	}
	
	//no operation found
	//just equate
	else
	{
		std::string Result = StoredData;
			
		if(v.find(Result) != v.end())
		{
			std::map<std::string, int>::iterator i_temp = v.find(Result);
			v[Ev_Val] = v[i_temp->first];
		}
		else if(is_Number(Result))
		{
			v[Ev_Val] = atoi(Result.c_str());
		}
		else
		{
			std::string errorMessage = "LET SYNTAX ERROR: Problem with equation operation (function only handles integers and already defined values)";
			BadLetException ex(1, errorMessage);
			throw ex;
		}
	}
	i++;
}

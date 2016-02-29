/************************************************************************
 * 
 * Filename:		node.cc
 * Authors:			YL,LH,PH
 * 
 * Description:		Node.cc is the base class, from which all operations
 * 					inherit common variables and functions. 
 * 
 * 					This base class contains the 'virtual' Execute function
 * 					through which run-time polymorphism is achieved.
 * 					
 * 					The file also contains helper functions used for 
 * 					comparing common information. An additional function
 * 					for printing out the stored variables is also included
 * 					for debugging purposes.
 * 
 * **********************************************************************/
 
#include "node.h"


//DEBUG
void Node::Print_Data()
{
	std::cout << Function << std::endl;
	std::cout << Data << std::endl;
}

bool Node::Compare_Data(std::string data)
{
	bool j;
	//removes all spaces
	std::string temp = Data;
	std::string::iterator end_pos = std::remove(temp.begin(), temp.end(), ' ');
	temp.erase(end_pos, temp.end());
	
	j = (data==temp);
	return j;
}

bool Node::Compare_Func(std::string data)
{
	bool j;
	//removes all spaces
	std::string temp = Function;
	std::string::iterator end_pos = std::remove(temp.begin(), temp.end(), ' ');
	temp.erase(end_pos, temp.end());
	
	j = (data==temp);
	return j;
}

bool Node::FindOperatorVals(std::size_t found, int &iLeftVal, int &iRightVal, std::string StoredData, std::map<std::string, int> &v)
{
	
	
	std::string Left_Val;
	std::string Right_Val;

	Left_Val = StoredData.substr(0, found);  //place content to Left_Val (string)
	StoredData.erase (0, found+1); 
	Right_Val = StoredData;					//place content to Right_Val (string)
	std::map<std::string, int>::iterator i_temp;	//used to search through the variable map
	
	
	//assessment of value on the left hand side
	if(v.find(Left_Val) != v.end())
	{
		i_temp = v.find(Left_Val);
		iLeftVal = v[i_temp->first];
	}
	else if(is_Number(Left_Val))
	{
		iLeftVal = atoi(Left_Val.c_str());
	}
	else
	{	
		return 0; //return false - (error)
	}
		
	//assessment of the value on the right hand side
	if(v.find(Right_Val) != v.end())
	{
		i_temp = v.find(Right_Val);
		iRightVal = v[i_temp->first];
	}
	else if(is_Number(Right_Val))
	{
		iRightVal = atoi(Right_Val.c_str());
	
	}	
	else
	{	
		return 0; //return false - error
	}

	return 1; //returns true - success
}

bool Node::is_Number(std::string& s)
{
	//helper function to check if the entered string is a number
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

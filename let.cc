#include "let.h"

Let::Let(int temp_Inst, std::string temp_Func, std::string temp_Data):Node(temp_Inst, temp_Func, temp_Data) 
{
	std::cout << "Let Constructor- inst, func, data are: " << temp_Inst << temp_Func << temp_Data << std::endl;	
}

void Let::Execute(std::map<int, Node*> m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i )
{
	std::string::iterator end_pos = std::remove(Data.begin(), Data.end(), ' ');
	Data.erase(end_pos, Data.end());
	
	//check if Ev_Val is a string..
	std::string Ev_Val;
	std::map<std::string, int>::iterator i_temp;
	int iLeftVal, iRightVal, Result;
	
	std::size_t found_equal = Data.find("=");
	
	
	
	if (found_equal!=std::string::npos)
	{
		
		Ev_Val = Data.substr(0, found_equal);
		Data.erase (0, found_equal+1); 
			
	}
	
	std::size_t found_plus = Data.find("+");
	std::size_t found_minus = Data.find("-");
	std::size_t found_times = Data.find("*");
	std::size_t found_divide = Data.find("/");
	
	std::string Left_Val;
	std::string Right_Val;
	
	if (found_plus!=std::string::npos)
	{
		Left_Val = Data.substr(0, found_plus);
		Data.erase (0, found_plus+1); 
		Right_Val = Data.substr(0, Data.length());
		
		
		
		
		if(v.find(Left_Val) != v.end())
		{
			i_temp = v.find(Left_Val);
			iLeftVal = v[i_temp->first];
		}
		else
			iLeftVal = atoi(Left_Val.c_str());
		
		if(v.find(Right_Val) != v.end())
		{
			i_temp = v.find(Right_Val);
			iRightVal = v[i_temp->first];
		}
		else
			iRightVal = atoi(Right_Val.c_str());
		
		//do more error checks here!
		
		Result = iLeftVal + iRightVal;
		
		v[Ev_Val] = Result;
		
		
	}
	else if(found_minus!=std::string::npos)
	{
		Left_Val = Data.substr(0, found_minus);
		Data.erase (0, found_minus+1); 
		Right_Val = Data.substr(0, Data.length());
		
		
		if(v.find(Left_Val) != v.end())
		{
			i_temp = v.find(Left_Val);
			iLeftVal = v[i_temp->first];
		}
		else
			iLeftVal = atoi(Left_Val.c_str());
		
		if(v.find(Right_Val) != v.end())
		{
			i_temp = v.find(Right_Val);
			iRightVal = v[i_temp->first];
		}
		else
			iRightVal = atoi(Right_Val.c_str());
		
		//do more error checks here!
		
		Result = iLeftVal - iRightVal;
		
		v[Ev_Val] = Result;
		
		
		
	}
	else if(found_times!=std::string::npos)
	{
		Left_Val = Data.substr(0, found_times);
		Data.erase (0, found_times+1); 
		Right_Val = Data.substr(0, Data.length());
		
		
		
		
		if(v.find(Left_Val) != v.end())
		{
			i_temp = v.find(Left_Val);
			iLeftVal = v[i_temp->first];
		}
		else
			iLeftVal = atoi(Left_Val.c_str());
		
		if(v.find(Right_Val) != v.end())
		{
			i_temp = v.find(Right_Val);
			iRightVal = v[i_temp->first];
		}
		else
			iRightVal = atoi(Right_Val.c_str());
		
		//do more error checks here!
		
		Result = iLeftVal * iRightVal;
		
		v[Ev_Val] = Result;
		
		
		
		
		
		
	}
	else if(found_divide!=std::string::npos)
	{
		Left_Val = Data.substr(0, found_divide);
		Data.erase (0, found_divide+1); 
		Right_Val = Data.substr(0, Data.length());
		
		
		if(v.find(Left_Val) != v.end())
		{
			i_temp = v.find(Left_Val);
			iLeftVal = v[i_temp->first];
		}
		else
			iLeftVal = atoi(Left_Val.c_str());
		
		if(v.find(Right_Val) != v.end())
		{
			i_temp = v.find(Right_Val);
			iRightVal = v[i_temp->first];
		}
		else
			iRightVal = atoi(Right_Val.c_str());
		
		//do more error checks here!
		
		Result = iLeftVal / iRightVal;
		
		v[Ev_Val] = Result;
		
		
	}
	else
	{
		//do standard

		std::string Result = Data;
		
		if(v.find(Result) != v.end())
		{
			std::map<std::string, int>::iterator i_temp = v.find(Result);
			v[Ev_Val] = v[i_temp->first];
		}
		else if(atoi(Result.c_str()) != 0)
		{
			v[Ev_Val] = atoi(Result.c_str());
		}
		else
		{
			//error
			std::cout<<"LET ERROR" << std::endl;
		}
				
		
	}
	
	std::cout << "Ev_Val is: " << Ev_Val << " Left_Val is " << Left_Val << " Right_Val is: " << Right_Val << std::endl;
	std::cout << "Data is: " << Data << std::endl;
}

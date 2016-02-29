/************************************************************************
 * 
 * Filename:		endif.cc
 * Authors:			YL,LH,PH
 * 
 * Description:		Endif.cc only increments the global iterator when
 * 					the Execute function of the class is called. All
 * 					error checking for the ENDIF statement given in the
 * 					BASIC program is handled within the 'program.cc' and
 * 					'ifendin.cc' files.
 * 
 * 					The c file includes the default constructor.
 * 
 * **********************************************************************/

#include "endif.h"

Endif::Endif(int temp_Inst, std::string temp_Func, std::string temp_Data):Node(temp_Inst, temp_Func, temp_Func) 
{
	//std::cout << "Endif Constructor- inst, func, data are: " << temp_Inst << temp_Func << temp_Data << std::endl;	
}

void Endif::Execute(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i)
{
	i++;
}

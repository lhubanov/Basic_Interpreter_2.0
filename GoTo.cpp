#include "GoTo.h"
#include <stdlib.h>

GoTo::GoTo(STL_Map map, std::string data){
	
	//first convert the string data to a integer instruction.
	
	int GoToInstruction = atoi(data.c_str());
	
	int ReturnCounter = 0;
	
	ReturnCounter = map.Get_Ctr_by_Inst(GoToInstruction);
	
	//Do Error checks here
	
	EvaluatedIterator = ReturnCounter;
	
}


int GoTo::GetIterator()
{
	return EvaluatedIterator;
}

#include "database.h"

class GoTo{
	
	public:
		GoTo(STL_Map map, std::string data);

		~GoTo(){};
		
		int GetIterator();
	
	private:
		
		int EvaluatedIterator;
	
	
};


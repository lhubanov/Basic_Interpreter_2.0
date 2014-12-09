//main function
#include <iostream>
//#include <string> //?
#include "program.h"


int main(int argc, char* argv[])
{
	if (argc != 2) //? + use exceptions + try to put this check in a separate function
	{
		std::cerr << "Error 33: Problem reading file. Please pass only 1 command line argument- the name of the file you want to process." << std::endl;
	}

	else
	{
		//create database
		//read file through database function
		std::ifstream iFile(argv[1]);

		//Program p(iFile);

		Program p;
		
		iFile >> p;
		
		iFile.close();
		
		p.Run();
		
		p.Print_map();
		
		//if (trace)
		std::cout << "All is fine here. Move along." << std::endl;
	}
	return 0;
}

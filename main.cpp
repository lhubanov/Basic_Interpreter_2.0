//main function
#include <iostream>
//#include <string> //?
#include "database.h"


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
		std::ifstream dave(argv[1]);

		Database test(dave);

		//if (trace)
			std::cout << "All is fine here. Move along." << std::endl;
	}

	//For the sake of the terminal window not to close.
	std::cout << "\n" << std::endl;
	std::cout << "Will it ever stop?" << std::endl;
	system("pause");
	return(0);
}

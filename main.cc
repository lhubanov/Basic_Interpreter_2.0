/************************************************************************
 * 
 * Filename:		main.cc
 * Authors:			YL,LH,PH
 * 
 * Description:		The main.c file executes all of the top-level operations
 * 					of the BASIC interpreter. A file is read through
 * 					the command line and then sorted/stored within the 
 * 					instantiated Program object. The BASIC
 * 					commands are then executed in the object's 
 * 					Run function.
 * 				
 * 					Additionally, all exceptions are handled here.
 * 					
 * **********************************************************************/
 
#include <iostream>
#include "program.h"


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "FILE ERROR: Problem reading file from command line." << std::endl;
		std::cerr << "Check, the given command line args [should be of the form: ./PROGNAME INPUTFILE.txt]" << std::endl;
		exit(0);
	}

	else
	{
		try{
		std::ifstream iFile(argv[1]);
		
		Program p;

		//reading and sorting of the input file is handled within the input operator
		iFile >> p;
		iFile.close();
		p.Run();
		}
		
		//any problems regarding the file are handled here
		catch( BadFileException &e)
		{
			std::cerr << "\nEncountered an error reading file:" << std::endl;
			e.PrintMyException();

			//std::cout << argc << std::endl;
			//std::cout << argv[1] << std::endl;
			//system("pause");
			exit(0);
		}
		
		//any problems related to the PRINT function are handled here
		catch( BadPrintException &e)
		{
			std::cerr << "\nEncountered an error in PRINT function:" << std::endl;
			e.PrintMyException();
		}
		
		//any problems related to the GOTO function are handled here
		catch( BadGotoException &e)
		{
			std::cerr << "\nEncountered an error in GOTO function:" << std::endl;
			e.PrintMyException();
		}
		
		//any problems related to the INPUT function are handled here
		catch( BadInputException &e)
		{
			std::cerr << "\nEncountered an error in INPUT function:" << std::endl;
			e.PrintMyException();
		}
		
		//any problems related to the LET function are handled here
		catch( BadLetException &e)
		{
			std::cerr << "\nEncountered an error in Let function:" << std::endl;
			e.PrintMyException();
		}
		
		//any problems related to the IF function are handled here
		catch( BadIfException &e)
		{
			std::cerr << "\nEncountered an error in IF function:" << std::endl;
			e.PrintMyException();
		}
	}
	
	return 0;

	system("pause");
}

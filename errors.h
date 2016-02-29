#ifndef ERRORS_H_
#define ERRORS_H_

/************************************************************************
 * 
 * Filename:		errors.h
 * Authors:			YL,LH,PH
 * 
 * Description:		Header for the 'Error' class. 
 * 					
 * **********************************************************************/

#include <iostream>
#include <string>

class BaseException
{
	private:
		BaseException(){};
	
	protected:
		int state;
		std::string name;

	
	public:
		BaseException(int s, std::string n):state(s),name(n){};
		~BaseException(){};
		void PrintMyException();
		
};


//Sub-Exceptions

//If
class BadIfException:public BaseException
{
	public:
		BadIfException(int s, std::string n):BaseException(s,n){};
		~BadIfException(){};
};


//Let
class BadLetException: public BaseException
{	
	public:
		BadLetException(int s, std::string n):BaseException(s,n){};
		~BadLetException(){};	
};


//GoTo
class BadGotoException: public BaseException
{
	public:
		BadGotoException(int s, std::string n):BaseException(s,n){};
		~BadGotoException(){};
};


//Print
class BadPrintException: public BaseException
{
	public:
		BadPrintException(int s, std::string n):BaseException(s,n){};	
		~BadPrintException(){};
};


//Input
class BadInputException: public BaseException
{
	public:
		BadInputException(int s, std::string n):BaseException(s,n){};
		~BadInputException(){};
};

//File
class BadFileException: public BaseException
{
	public:
		BadFileException(int s, std::string n):BaseException(s,n){};
		~BadFileException(){};
};

#endif

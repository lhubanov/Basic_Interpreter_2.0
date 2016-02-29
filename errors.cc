/************************************************************************
 * 
 * Filename:		errors.cc
 * Authors:			YL,LH,PH
 * 
 * Description:		Errors.cc is holds all functions carried out by
 * 					the exception classes declared in the 'errors.h'
 * 					file.
 * 
 * 					The c file includes the default constructor.
 * 					All operations are done in the Execute function.
 * 
 * **********************************************************************/
 
#include "errors.h"

void BaseException::PrintMyException()
{
	std::cout << name << std::endl;
}

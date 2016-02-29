#ifndef ifendif_H
#define ifendif_H

/************************************************************************
 * 
 * Filename:		ifendif.h
 * Authors:			YL,LH,PH
 * 
 * Description:		Header for the 'Ifendif' class. 
 * 					
 * **********************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "node.h"
#include <algorithm>
#include "program.h"
#include "errors.h"

class Ifendif : public Node {
	
	public:
	
		Ifendif(int temp_Inst, std::string temp_Func, std::string temp_Data);
		~Ifendif(){};
		void Execute(std::map<int, Node*> &m, std::map<std::string, int> &v, std::map<int, Node*>::iterator &i);
		
		
	private:
	
	
};

#endif


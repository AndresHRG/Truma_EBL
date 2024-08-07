/* *******************************************************************************
 *       @file              ErrorManager.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "ErrorManager.h"
#include <vector>

std::vector<errors> errorList;

namespace Errors
{

bool errorExists(short classId, short code)
{
	bool result = false;
	
	for(int i = 0; i < errorList.size(); i++)
	{
		if((errorList[i].classId == classId) && (errorList[i].code == code))
		{
			result = true;
			break;
		}
	}
	
	return result;
}

void addError(short classId, short code)
{
	if(errorExists(classId, code))
		return;
	
	errors error;
	
	error.classId = classId;
	error.code = code;
	
	errorList.push_back(error);
}

void cleanError(short classId, short code)
{
	for(int i = 0; i < errorList.size(); i++)
	{
		if((errorList[i].classId == classId) && (errorList[i].code == code))
		{
			errorList.erase(errorList.begin() + i);
		}
	}
}

errors getError()
{
	errors error;

	error.classId = 0;
	error.code = 0;

	if(!errorList.empty())
	{
			error.classId = errorList[0].classId;
			error.code = errorList[0].code;
			
			errorList.erase(errorList.begin());
			errorList.push_back(error);
	}

	return error;
}

short getNumErrors()
{
	return errorList.size();
}

}
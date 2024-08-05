/* *******************************************************************************
 *       @file              ErrorManager.h
 *       @expl              Proof of concept
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _ERROR_MANAGER_H
#define _ERROR_MANAGER_H

// Definición de la estructura de errores
struct errors {
    short classId;
    short code;
};

namespace Errors
{

bool errorExists(short classId, short code);
void addError(short classId, short code);
void cleanError(short classId, short code);
errors getError();
short getNumErrors();
}
#endif
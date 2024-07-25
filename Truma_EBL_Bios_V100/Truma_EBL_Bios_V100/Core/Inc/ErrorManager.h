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
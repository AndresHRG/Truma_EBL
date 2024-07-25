#include "TrumaCombiState.h"

short boilerState = 0;
short heaterState = 0;
short airConditioner = 0;

void setBoilerState(short state)
{
	boilerState = state;
}

void setHeaterState(short state)
{
	heaterState = state;
}

void setAirCoditionerState(short state)
{
	airConditioner = state;
}

short getBoilerState()
{
	return boilerState;
}

short getHeaterState()
{
	return heaterState;
}

short getAirConditionerState()
{
	return airConditioner;
}
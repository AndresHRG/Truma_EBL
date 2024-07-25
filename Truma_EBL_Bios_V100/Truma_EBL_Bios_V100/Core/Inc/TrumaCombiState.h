#ifndef _TRUMA_COMBI_STATE_H
#define _TRUMA_COMBI_STATE_H

#define ID_CONTROL_AC				0x08
#define ID_CONTROL_BOILER   0x37
#define ID_CONTROL_HEATER   0x39
#define ID_INFO_AC          0x17
#define ID_INFO_BOILER      0x38
#define ID_INFO_HEATER			0x3A

void setBoilerState(short state);
void setHeaterState(short state);
void setAirCoditionerState(short state);
short getBoilerState();
short getHeaterState();
short getAirConditionerState();

#endif
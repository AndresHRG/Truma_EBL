#ifndef ADDRESIO_H
#define ADDRESIO_H

//Los parametros del IOParameters representan bloque y pin del HW, {blk, pin}
typedef struct {
    int block;
    int pin;
}IOParameters;

const IOParameters EXTERNAL_LIGHTS  = {11,2};//salida
const IOParameters LIGHT1 = {11,1};//salida
const IOParameters LIGHT2 = {11,4};//salida
const IOParameters LIGHT3 = {11,7};//salida
const IOParameters LIGHT4 = {11,3};//salida
const IOParameters LIGHT5 = {11,6};//salida
const IOParameters LIGHT6 = {11,9};//salida
const IOParameters SWITCH1 = {5,1};//entrada
const IOParameters SWITCH2 = {5,2};//entrada
const IOParameters SWITCH3 = {5,3};//entrada
const IOParameters SWITCH4 = {5,4};//entrada
const IOParameters SWITCH5 = {5,5};//entrada
const IOParameters SWITCH6 = {5,6};//entrada
const IOParameters DRAIN_VALVE = {3,1};//salida
const IOParameters MULTIMEDIA_1 = {3,4};//salida
const IOParameters MULTIMEDIA_2 = {3,5};//salida
const IOParameters MULTIMEDIA_3 = {3,6};//salida
const IOParameters LIGHTS_GROUP_D = {3,7};//salida
const IOParameters BOILER_CTRL = {3,11};//salida
const IOParameters BOILER_POWER = {2,5};//salida
const IOParameters HEATER_POWER = {2,4};//salida
const IOParameters GAS_PIEZO = {2,6};//salida
const IOParameters SAT = {2,6};//salida
const IOParameters FRIDGE_CTRL = {2,3};//salida
const IOParameters FRIDGE_POWER = {2,1};//salida
const IOParameters STEP = {11,8};//salida
const IOParameters FWATERPUMP = {11,5};//salida
const IOParameters EMPTY_VALVE_ON = {3,2};//salida
const IOParameters EMPTY_VALVE_OFF = {3,3};//salida
const IOParameters FWATER25 = {6,2};//entrada
const IOParameters FWATER50 = {6,3};//entrada
const IOParameters FWATER75 = {6,4};//entrada
const IOParameters FWATER100 = {6,5};//entrada
const IOParameters FWATERON = {6,1};//salida
const IOParameters GWATER25 = {7,2};//entrada
const IOParameters GWATER50 = {7,3};//entrada
const IOParameters GWATER75 = {7,4};//entrada
const IOParameters GWATER100 = {7,5};//entrada
const IOParameters GWATERON = {7,1};//salida
const IOParameters INVERTER = {3,10};//salida
const IOParameters DOORSTEP = {11,8};//salida
const IOParameters FLOOR_HEATING_1 = {3,7};//salida
const IOParameters FLOOR_HEATING_2 = {3,8};//salida
const IOParameters FLOOR_HEATING_3 = {3,9};//salida
const IOParameters ENGINE_BATTERY = {3,12};//entrada
const IOParameters TEST = {0,0};

#endif /* ADDRESIO_H */
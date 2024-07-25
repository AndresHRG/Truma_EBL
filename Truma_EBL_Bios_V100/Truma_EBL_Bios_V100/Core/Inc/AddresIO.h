#ifndef ADDRESIO_H
#define ADDRESIO_H

//Los parametros del IOParameters representan bloque y pin del HW, {blk, pin}
typedef struct {
    int block;
    int pin;
}IOParameters;

const IOParameters INTERNAL_LIGTHS_1 = {4,1};
const IOParameters INTERNAL_LIGTHS_2 = {4,2};
const IOParameters INTERNAL_LIGTHS_3 = {4,3};
const IOParameters NIGHT_LIGTHS_1 = {5,1};
const IOParameters NIGHT_LIGTHS_2= {5,2};
const IOParameters EXTERNAL_LIGTHS  = {5,3};
const IOParameters MULTIMEDIA  = {25,1};
const IOParameters INVERTER = {0,0};
const IOParameters FLOOR_HEATING = {25,3};
const IOParameters FRIDGE = {24,3};
const IOParameters TV = {25,3};
const IOParameters FWATERPUMP = {22,0};
const IOParameters GWVALVE_ON = {21,1};
const IOParameters GWVALVE_OFF = {21,3};
const IOParameters FWATER25 = {15,1};
const IOParameters FWATER50 = {15,2};
const IOParameters FWATER75 = {15,3};
const IOParameters FWATER100 = {15,4};
const IOParameters FWATERON = {15,5};
const IOParameters GWATER25 = {16,1};
const IOParameters GWATER50 = {16,2};
const IOParameters GWATER75 = {16,3};
const IOParameters GWATER100 = {16,4};
const IOParameters GWATERON = {16,5};
const IOParameters TEST = {0,0};


#endif /* ADDRESIO_H */
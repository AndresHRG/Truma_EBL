/* *******************************************************************************
 *       @file              Utils.cpp
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#include "Utils.h"
#include "string.h"

namespace Utils
{
int ascci2Integer(char value)
{
    if (value >= '0' && value <= '9') 
        return value - '0';
    else 
				return -1;
}

bool emptyBuffer(char* buffer)
{
	bool result = false;
	char empty[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  
	if(memcmp(buffer, empty, 8) == 0)//proteccion ante mensajes vacios
		result = true;
	
	return result;
}

void initialize2Zero(uint8_t* buffer)
{
	buffer[0] = 0;
	buffer[1] = 0;
	buffer[2] = 0;
	buffer[3] = 0;
	buffer[4] = 0;
	buffer[5] = 0;
	buffer[6] = 0;
	buffer[7] = 0;
}

int ioDigitalWrite(const IOParameters& params, short value)
{
	int output = 0;
	
	if((params.block == 2) && (params.pin == 3)) 
	{
		output = BLK2_3;
	}
	else if((params.block == 3) && (params.pin == 1)) 
	{
		output = BLK3_1;
	}
	else if((params.block == 3) && (params.pin == 2))
	{
		output = BLK3_2;
	}
	else if((params.block == 3) && (params.pin == 3))
	{
		output = BLK3_3;
	}
	else if((params.block == 3) && (params.pin == 4))
	{
		output = BLK3_4;
	}
	else if((params.block == 3) && (params.pin == 5))
	{
		output = BLK3_5;
	}
	else if((params.block == 3) && (params.pin == 6))
	{
		output = BLK3_6;
	}
	else if((params.block == 3) && (params.pin == 7))
	{
		output = BLK3_7;
	}
	else if((params.block == 3) && (params.pin == 8))
	{
		output = BLK3_8;
	}
	else if((params.block == 3) && (params.pin == 9))
	{
		output = BLK3_9;
	}
	else if((params.block == 3) && (params.pin == 10))
	{
		output = BLK3_10;
	}
	else if((params.block == 3) && (params.pin == 11))
	{
		output = BLK3_11;
	}
	else if((params.block == 4))
	{
		output = BLK4;
	}
	else if((params.block == 6) && (params.pin == 1))
	{
		output = BLK6_C_1;
	}
	else if((params.block == 7) && (params.pin == 1))
	{
		output = BLK7_C_1;
	}
	else if((params.block == 11) && (params.pin == 1))
	{
		output = BLK11_1;
	}
	else if((params.block == 11) && (params.pin == 2))
	{
		output = BLK11_2;
	}
	else if((params.block == 11) && (params.pin == 3))
	{
		output = BLK11_3;
	}
	else if((params.block == 11) && (params.pin == 4))
	{
		output = BLK11_4;
	}
	else if((params.block == 11) && (params.pin == 5))
	{
		output = BLK11_5;
	}
	else if((params.block == 11) && (params.pin == 6))
	{
		output = BLK11_6;
	}
	else if((params.block == 11) && (params.pin == 7))
	{
		output = BLK11_7;
	}
	else if((params.block == 11) && (params.pin == 9))
	{
		output = BLK11_9;
	}

	
	return ArviSet(output,value);

}

int ioDigitalRead(const IOParameters& params)
{
	//esta funcion es compatible con los bloques: B21, B22, B23, B24, B25, B27
	int input;
	
	if((params.block == 6) && (params.pin == 2))
	{
		input = BLK6_C_2;
	}
	else if((params.block == 6) && (params.pin == 3))
	{
		input = BLK6_C_3;
	}
	else if((params.block == 6) && (params.pin == 4))
	{
		input = BLK6_C_4;
	}
	else if((params.block == 6) && (params.pin == 5))
	{
		input = BLK6_C_5;
	}
	else if((params.block == 7) && (params.pin == 2))
	{
		input = BLK7_C_2;
	}
	else if((params.block == 7) && (params.pin == 3))
	{
		input = BLK7_C_3;
	}
	else if((params.block == 7) && (params.pin == 4))
	{
		input = BLK7_C_4;
	}
	else if((params.block == 7) && (params.pin == 5))
	{
		input = BLK7_C_5;
	}
	
	return ArviGet_AD(input);
	
}


byte setBits(unsigned short bitInit, unsigned short bitEnd, short value) 
{
		byte aux = 0;
    // M�scara para los bits de inicio a fin, todos en 1
    unsigned char mask = ((1 << (bitEnd - bitInit + 1)) - 1) << bitInit;
    // Limpiamos los bits de inicio a fin en byte
    aux &= ~mask;
    // Ponemos los bits de inicio a fin en byte con el valor dado
    aux |= (value << bitInit) & mask;
    return aux;
}

int round_float_to_nearest(float num) 
{
    //return floor(x + 0.5);
 // Extraer la parte entera y decimal del n?mero
    int integer_part = (int)num;
    float decimal_part = num - integer_part; 

    // Redondear la parte decimal al entero m?s cercano
    int rounded_decimal = (decimal_part < 0.5) ? 0 : 1;

    // Retornar la suma de la parte entera y la parte decimal redondeada
    return integer_part + rounded_decimal;
}

void delay_ms(short mSeg)
{
	uint64_t time = GetMilliSec();
	
	while((time + mSeg) > GetMilliSec());
}

bool compareAnalog(long oldValue, long newValue, short rate)
{
    bool result = false;
		int aux = (oldValue - newValue);
		
		if(aux < 0)
			aux *=-1; 
			
    if(aux > rate) // si la diferencia de valores es mayor al rate devolvemos true sino false
    {
        result = true;
    }
    return result;
}

}
	
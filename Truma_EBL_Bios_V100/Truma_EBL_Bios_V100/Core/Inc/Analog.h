#ifndef __ANALOG_H
#define __ANALOG_H

#ifdef __cplusplus
extern "C" {
#endif
	
#include <stdint.h>
	
extern uint16_t convAD1[];
extern uint16_t convAD2[];
extern uint16_t Conversion_MUX_LIGHT[];
extern uint16_t Conversion_MUX_WATER[];
extern uint16_t Conversion_MUX_FUSE_1[];
extern uint16_t Conversion_MUX_FUSE_2[];

void ScanMultiplexores(void);

#ifdef __cplusplus
}
#endif

#endif /* __ANALOG_H */

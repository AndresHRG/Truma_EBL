#ifndef __COMM_H
#define __COMM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
	
#define	ADD_IO_EXPANDER		0x38
#define	IO_EXPANDER_READ	1
#define	IO_EXPANDER_WRITE	0

void Arvi_printf(char *s,...);
void Write_IO_Expander(uint8_t output);
uint8_t Read_IO_Expander(void);

#ifdef __cplusplus
}
#endif

#endif /* __COMM_H */

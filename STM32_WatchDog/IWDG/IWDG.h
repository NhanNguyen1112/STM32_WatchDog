
#ifndef __IWDG__
#define __IWDG__

#include "main.h"
#include "IWDG_Register.h"

void IWDG_Init(void);
void IWDG_START(void);
void IWDG_SetTimeOut_Mili(unsigned int MiliSeconds);
void IWDG_SetTimeOut_Second(unsigned int Seconds);

#endif /*__IWDG__*/


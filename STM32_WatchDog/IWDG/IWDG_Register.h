
#ifndef __IWDG_Register__
#define __IWDG_Register__

#include "IWDG.h"

typedef struct
{
  volatile unsigned int IWDG_KR;
  volatile unsigned int IWDG_PR;
  volatile unsigned int IWDG_RLR;
  volatile unsigned int IWDG_SR;
}IWDG_typedef;

#define IWDG_BASE_ADDRESS   ( (unsigned int)0x40003000UL )
#define IWDG                ((IWDG_typedef *)IWDG_BASE_ADDRESS)

#endif /*__IWDG__*/

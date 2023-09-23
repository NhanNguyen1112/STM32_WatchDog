
#include "IWDG.h"

#define LSI_CLOCK (40000UL)

/* LSI= 40KHz */
void IWDG_Init(void)
{
  /* Do nothing! *_* >< */
}

/* Bật chế độ bảo vệ chống ghi đè */
static void Overwrite_Protection(void)
{
  IWDG->IWDG_KR = 0xAAAA;
}

void IWDG_START(void)
{
  IWDG->IWDG_KR = 0xCCCC;
}

/* MiliSecond: 1ms -> 400ms */
void IWDG_SetTimeOut_Mili(unsigned int MiliSeconds)
{
  /*
  time_out = ((Prescaler div)*(Reload value)) / F_lsi

  (time_out/1000) * F_lsi = (Prescaler div)*(Reload value)

  Reload value = ((time_out * F_lsi)/1000) /Prescaler div

    ex: ((1ms*40000)/1000)/4 = 10
    ex: ((400ms*40000)/1000)/4 = 4000

  */
  unsigned int Reload_Value;
  
  Reload_Value = ( ((MiliSeconds*LSI_CLOCK)/1000)/4 );

  IWDG->IWDG_KR = 0x5555;
  IWDG->IWDG_PR &= 0x7u;
  IWDG->IWDG_RLR = (Reload_Value-1);
  Overwrite_Protection();
}

/* Seconds: 1s -> 25s */
void IWDG_SetTimeOut_Second(unsigned int Seconds)
{
  /*
  time_out = ((Prescaler div)*(Reload value)) / F_lsi

  time_out * F_lsi = (Prescaler div)*(Reload value)
  Reload value = (time_out * F_lsi)/Prescaler div
    ex: (1s*40000)/256 = 156
    ex: (25*40000)/256 = 3906

  Reload = (Time_out/Prescaler)*F_lsi
        ex: (1s/256)*40000 = 156
        ex: (25s/256)*40000 = 3906
  */

  unsigned int Reload_Value;
  
  Reload_Value = ((Seconds*LSI_CLOCK)/256);

  IWDG->IWDG_KR = 0x5555;
  IWDG->IWDG_PR = 0x7u;
  IWDG->IWDG_RLR = (Reload_Value-1);
  Overwrite_Protection();
}



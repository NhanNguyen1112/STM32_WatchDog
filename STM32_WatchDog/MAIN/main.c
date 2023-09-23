
#include "main.h"

int main(void)
{
  InitClockHSE();
  Init_TIM2_CH1_Delay();

  Enable_Disable_Clock_PortC(Enable);
  SetPinOutput(PORTC, PIN13, PushPull);

  WritePin(PORTC, PIN13, LOW);
  Delay_TIM2_CH1_ms(5000);

  static int a,b;

  // IWDG_SetTimeOut_Mili(400);
  // IWDG_START();
	
  IWDG_SetTimeOut_Second(2);
  IWDG_START();

  while (1)
  {
    for(a=0; a<=10; a++)
    {
      WritePin(PORTC, PIN13, LOW);
      Delay_TIM2_CH1_ms(100);
      WritePin(PORTC, PIN13, HIGH);
      Delay_TIM2_CH1_ms(100);
    }

    WritePin(PORTC, PIN13, HIGH);
    Delay_TIM2_CH1_ms(5000);
  }
  
}



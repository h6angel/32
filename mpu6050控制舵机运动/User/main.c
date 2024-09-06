#include "stm32f10x.h"                  // Device header"
#include "OLED.h"
#include "Delay.h"
#include "inv_mpu.h"
#include"pwm.h"
#include"serve.h"
#include"Key.h"
#include<math.h>

float angelx,angely,angelz;

int main(void)
{
	delay_init();
	OLED_Init();
	MPU6050_DMP_Init();
	serve_init();
	serve_setangels1(0);
	serve_setangels2(0);
	while(1)
	{
		MPU6050_DMP_Get_Data(&angelx,&angely,&angelz);
		OLED_ShowChar(1,1,'x');
		OLED_ShowChar(2,1,'y');
		OLED_ShowChar(3,1,'z');
		OLED_ShowSignedNum(1,3,angelx,5);
		OLED_ShowSignedNum(2,3,angely,5);
		OLED_ShowSignedNum(3,3,angelz,5);
		serve_setangels2(angelz+90);
		if(angelx >= 0)
	    {
			serve_setangels1(90-angelx);
		}
			
		else if(angelx <0)
		{
			float a = abs(angelx);
			serve_setangels2(a+90);
		}

	}
}

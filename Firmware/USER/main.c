#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "usb_lib.h"
#include "hw_config.h"
#include "usb_pwr.h"
#include "servo.h"

int main(void)
{
	u8 usbstatus=0;
	
	//Initialize UART and system
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	uart_init(115200);
	SystemInit();
	
	//Initialize LED
	LED_Init();
	delay_ms(1800);
	
	//Initiate TIM4 for PWM output
	TIM4_PWM_Init(199,7199);
	
	//Disconnect and reconnect USB
	USB_Port_Set(0);
	delay_ms(700);
	USB_Port_Set(1);
	
	//Initialize USB
 	Set_USBClock();
 	USB_Interrupts_Config();
 	USB_Init();
	
	//while(1);
	
	while(1)
	{
		if(usbstatus!=bDeviceState) //USB status changed
		{
			usbstatus=bDeviceState;
			if(usbstatus==CONFIGURED) //USB configured as device
			{
				LED0=0;
			}else
			{
				LED0=1;
			}
		}
		
		if(USB_USART_RX_STA&0x8000) //Received message
		{
			set_servo(USB_USART_RX_BUF);
			USB_USART_RX_STA=0;
		}else //Wait for message
		{
			delay_ms(10);
		}
	}
}


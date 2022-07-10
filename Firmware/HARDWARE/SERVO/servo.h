#ifndef __SERVO_H
#define __SERVO_H
#include "sys.h"

void TIM4_PWM_Init(u16 arr,u16 psc);
void set_servo(u8 buffer[]);
#endif

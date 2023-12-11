

/**
 * main.c
 */
/******************************< SYSTEM ***************************/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/******************************< LIB ******************************/
#include "../LIB/STD_TYPES.h"
/******************************< MCAL *****************************/
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/STK/STK_interface.h"
#include "../MCAL/UART/UART_interface.h"
/******************************< HAL ******************************/

#include "../HAL/magnetic sensor/MAGNETIC_interface.h"
#include "../HAL/smoke sensor/SMOKE_interface.h"
#include "../HAL/ultrasonic/ULTRASONIC_interface.h"
/******************************< APP ******************************/
/*#include "../APP/APP.h"*/
/******************************< Global Variables *****************/
f64 distance;
/******************************< main *****************************/
int main(void)
 {
    ULTRASONIC_Init(DIO_u8_PORTF,DIO_u8_PORTF, DIO_u8_PIN4, DIO_u8_PIN5);
    

    /******************************< Super loop **********************************************/

    while(1)
    {
        distance = get_ULTRASONIC_Distance(4000000);
        if (distance>0)
        {
            LED_voidLedOn(1);
        }
        else if (distance>15)
        {
            LED_voidLedOn(2);
        }
        else if (distance>18)
        {
            LED_voidLedOn(3);
        }        
    }
    return 0;
}
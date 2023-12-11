//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3		*************
//********** Date    : 10/12/2023              	*************
//********** SWC     : HAL_ULTRASONIC                *************
//********** Version : 1.0                    	*************
//***********************************************************

/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TM4C123GH6PM.h"
/**< MCAL_DIO */
#include "DIO_interface.h"
/**< MCAL_STK */
#include "STK_interface.h"
/**< ULTRASONIC_HAL */
#include "ULTRASONIC_private.h"
#include "ULTRASONIC_interface.h"
#include "ULTRASONIC_config.h"


u32 status, ticks_NUM, Old_status = DIO_u8_LOW;
void ULTRASONIC_Init(u8 trig_port, u8 echo_port, u8 trig_pin, u8 echo_pin)
{
    DIO_u8SetPinDirection(trig_port, trig_pin ,DIO_u8_OUTPUT);
    DIO_u8SetPinValue(trig_port, trig_pin ,DIO_u8_HIGH);
    DIO_u8SetPinDirection(echo_port, echo_pin ,DIO_u8_INPUT);
    DIO_u8GetPinValue(echo_port, echo_pin ,&status);
    if (status == DIO_u8_HIGH && Old_status == DIO_u8_LOW)
    {
        STK_voidConfig(Desired_Ticks);
    }
    Old_status = status;
    if (status == DIO_u8_LOW && Old_status == DIO_u8_HIGH)
    STK_voidGetCurrentValue(&ticks_NUM);
    STK_voidHandler();
}

f64 get_ULTRASONIC_Distance(u32 STK_CLOCK_FREQUENCY)
{
    f64 distance ;
    distance = ((100000000 * ticks_NUM) /STK_CLOCK_FREQUENCY)/58;
    return distance;
}
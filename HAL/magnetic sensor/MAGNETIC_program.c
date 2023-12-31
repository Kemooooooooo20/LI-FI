//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3		*************
//********** Date    : 10/12/2023              	*************
//********** SWC     : HAL_MAGNETIC                *************
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
/**< MAGNETIC_HAL */
#include "MAGNETIC_private.h"
#include "MAGNETIC_interface.h"
#include "MAGNETIC_config.h"

void MAGNETIC_Init(void)
{
    DIO_u8SetPinDirection(DIO_u8_PORTF, MAGNETIC_pin ,DIO_u8_INPUT);
}

u8 get_MAGNETIC_status(u8 pin)
{
    u32 status ;
    DIO_u8GetPinValue(DIO_u8_PORTF, pin ,&status);
    return status;
}
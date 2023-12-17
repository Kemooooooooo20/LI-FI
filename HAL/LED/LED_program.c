//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3		*************
//********** Date    : 26/04/2023              	*************
//********** SWC     : HAL_LED                  *************
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
/**< LED_HAL */
#include "LED_private.h"
#include "LED_interface.h"
#include "LED_config.h"


void LED_voidLedInit(u8 port, u8 pin)
{
    DIO_voidInit(port);
	DIO_u8SetPinDirection(port, pin ,DIO_u8_OUTPUT);   /**< then initialize the LED direction */
	DIO_u8SetPinDirection(port, pin ,DIO_u8_OUTPUT);  /**< then initialize the LED direction */  
	DIO_u8SetPinDirection(port, pin ,DIO_u8_OUTPUT);    /**< then initialize the LED direction */
}

void LED_voidLedOn(u8 copy_u8PortId, u8 copy_u8PinId )
{
    u8 Local_u8ErrorState = STD_TYPES_OK;
	if((copy_u8PortId<=DIO_u8_PORTF&&copy_u8PortId>=DIO_u8_PORTA)&&(copy_u8PinId<=DIO_u8_PIN7&&copy_u8PinId>=DIO_u8_PIN0))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:
            DIO_u8SetPinValue(DIO_u8_PORTA, copy_u8PinId ,DIO_u8_HIGH);
			break;

			case DIO_u8_PORTB:
			DIO_u8SetPinValue(DIO_u8_PORTB, copy_u8PinId ,DIO_u8_HIGH);
			break;

			case DIO_u8_PORTC:
			DIO_u8SetPinValue(DIO_u8_PORTC, copy_u8PinId ,DIO_u8_HIGH);
			break;

			case DIO_u8_PORTD:	
			DIO_u8SetPinValue(DIO_u8_PORTD, copy_u8PinId ,DIO_u8_HIGH);
			break;

			case DIO_u8_PORTE:
			    if(copy_u8PinId<=DIO_u8_PIN4)
			    {
			        DIO_u8SetPinValue(DIO_u8_PORTE, copy_u8PinId ,DIO_u8_HIGH);
			    }
			    else
			    {
			        Local_u8ErrorState = STD_TYPES_NOK;
			    }
			break;
			case DIO_u8_PORTF:
			    if(copy_u8PinId<=DIO_u8_PIN4)
			    {
			        DIO_u8SetPinValue(DIO_u8_PORTF, copy_u8PinId ,DIO_u8_HIGH);
			    }
			    else
			    {
			        Local_u8ErrorState = STD_TYPES_NOK;
			    }
			break;
			default:Local_u8ErrorState = STD_TYPES_NOK; break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;

}

void LED_voidLedOff(u8 copy_u8PortId, u8 copy_u8PinId)
{
    u8 Local_u8ErrorState = STD_TYPES_OK;
	if((copy_u8PortId<=DIO_u8_PORTF&&copy_u8PortId>=DIO_u8_PORTA)&&(copy_u8PinId<=DIO_u8_PIN7&&copy_u8PinId>=DIO_u8_PIN0))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:
            DIO_u8SetPinValue(DIO_u8_PORTA, copy_u8PinId ,DIO_u8_LOW);
			break;

			case DIO_u8_PORTB:
			DIO_u8SetPinValue(DIO_u8_PORTB, copy_u8PinId ,DIO_u8_LOW);
			break;

			case DIO_u8_PORTC:
			DIO_u8SetPinValue(DIO_u8_PORTC, copy_u8PinId ,DIO_u8_LOW);
			break;

			case DIO_u8_PORTD:	
			DIO_u8SetPinValue(DIO_u8_PORTD, copy_u8PinId ,DIO_u8_LOW);
			break;

			case DIO_u8_PORTE:
			    if(copy_u8PinId<=DIO_u8_PIN4)
			    {
			        DIO_u8SetPinValue(DIO_u8_PORTE, copy_u8PinId ,DIO_u8_LOW);
			    }
			    else
			    {
			        Local_u8ErrorState = STD_TYPES_NOK;
			    }
			break;
			case DIO_u8_PORTF:
			    if(copy_u8PinId<=DIO_u8_PIN4)
			    {
			        DIO_u8SetPinValue(DIO_u8_PORTF, copy_u8PinId ,DIO_u8_LOW);
			    }
			    else
			    {
			        Local_u8ErrorState = STD_TYPES_NOK;
			    }
			break;
			default:Local_u8ErrorState = STD_TYPES_NOK; break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

void LED_voidLedTog(u8 copy_u8LedColour)
{
	switch(copy_u8LedColour)
	{
	case LED_BLUE:
	    DIO_u8TogglePinValue(DIO_u8_PORTF, LED_BLUE_PIN);
	    break;
	case LED_GREEN:
	    DIO_u8TogglePinValue(DIO_u8_PORTF, LED_GREEN_PIN);
	    break;
	case LED_RED:
	    DIO_u8TogglePinValue(DIO_u8_PORTF, LED_RED_PIN);
	    break;
	default : /**< Error State */ break;
	}
}

void LED_voidLedBlinkOnce(u8 copy_u8LedColour)
{
    switch(copy_u8LedColour)
    {
    case LED_BLUE:
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_BLUE_PIN, DIO_u8_HIGH);
        STK_voidDelay(LED_TIME_ON);
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_BLUE_PIN, DIO_u8_LOW);
        break;
    case LED_GREEN:
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_GREEN_PIN, DIO_u8_HIGH);
        STK_voidDelay(LED_TIME_ON);
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_GREEN_PIN, DIO_u8_LOW);
        break;
    case LED_RED:
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_RED_PIN, DIO_u8_HIGH);
        STK_voidDelay(LED_TIME_ON);
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_RED_PIN, DIO_u8_LOW);
        break;
    default :/**< Error State */ break;
    }
}

void LED_voidLedBlinkTwice(u8 copy_u8LedColour)
{
    LED_voidLedBlinkOnce(copy_u8LedColour);
	STK_voidDelay(LED_TIME_ON);
	LED_voidLedBlinkOnce(copy_u8LedColour);
}

void LED_voidLedOff(void)
{
	DIO_u8SetPinValue(DIO_u8_PORTF, LED_BLUE_PIN, DIO_u8_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTF, LED_RED_PIN, DIO_u8_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTF, LED_GREEN_PIN, DIO_u8_LOW);
}
//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3		*************
//********** Date    : 10/12/2023              	*************
//********** SWC     : HAL_ULTRASONIC           *************
//********** Version : 1.0                    	*************
//***********************************************************
#ifndef _HAL_ULTRASONIC_INTERFACE_H_
#define _HAL_ULTRASONIC_INTERFACE_H_


/** \brief	This is a function called ULTRASONIC_Init that intialize the ULTRASONIC sensor trig pin as an output and 
 * echo pin as an input and gets the value of ticks number when echo pin is high .
 *
 *			
 *
 * \param[in]	trig_port
 * \param[in]   echo_port
 * \param[in]   trig_pin
 * \param[in]   echo_pin
 * \return  void
 *
 */
void ULTRASONIC_Init(u8 trig_port, u8 echo_port, u8 trig_pin, u8 echo_pin);

/** \brief	This is a function called get_ULTRASONIC_Distance that know the Distance of the ULTRASONIC sensor in cm .
 *
 *			The function first calls another function get pin direction to know the pin status whether high or low then store it in status variable.
 *          
 * \param	The the stk clock frequency it is either STK_CLOCK_FREQUENCY_1 or STK_CLOCK_FREQUENCY_4 in stk_config.h file 
 * \return  distance in cm 
 *
 */
f64 get_ULTRASONIC_Distance(u32 STK_CLOCK_FREQUENCY);




#endif //_HAL_ULTRASONIC_INTERFACE_H_ 
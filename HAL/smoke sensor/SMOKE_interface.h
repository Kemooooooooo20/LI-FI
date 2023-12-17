//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3		*************
//********** Date    : 10/12/2023              	*************
//********** SWC     : HAL_SMOKE                *************
//********** Version : 1.0                    	*************
//***********************************************************
#ifndef _HAL_SMOKE_INTERFACE_H_
#define _HAL_SMOKE_INTERFACE_H_


/** \brief	This is a function called SMOKE_Init that intialize the smoke sensor pin as in input.
 *
 *			
 *
 * \param[1]	The_smoke_sensor_port_id
 * \param[1]	The_smoke_sensor_pin_id
 * 
 * \return  void
 *
 */
void SMOKE_Init(u8 port, u8 pin);

/** \brief	This is a function called get_SMOKE_status that know the status of the smoke sensor .
 *
 *			The function first calls another function get pin direction to know the pin status whether high or low then store it in status variable.
 *          
 * \param[1]	The_smoke_sensor_port_id
 * \param[1]	The_smoke_sensor_pin_id
 * \return  unsigned_int HIGH or LOW
 *
 */
u32 get_smoke_status(u8 port, u8 pin);




#endif //_HAL_SMOKE_INTERFACE_H_ 
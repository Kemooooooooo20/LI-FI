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
 * \param	void
 * \return  void
 *
 */
void SMOKE_Init(void);

/** \brief	This is a function called get_SMOKE_status that know the status of the smoke sensor .
 *
 *			The function first calls another function get pin direction to know the pin status whether high or low then store it in status variable.
 *          
 * \param	The smoke pin
 * \return  character HIGH or LOW
 *
 */
u8 get_smoke_status(u8 smoke_pin);




#endif //_HAL_SMOKE_INTERFACE_H_ 
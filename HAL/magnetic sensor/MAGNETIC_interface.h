//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3		*************
//********** Date    : 10/12/2023              	*************
//********** SWC     : HAL_MAGNETIC             *************
//********** Version : 1.0                    	*************
//***********************************************************
#ifndef _HAL_MAGNETIC_INTERFACE_H_
#define _HAL_MAGNETIC_INTERFACE_H_


/** \brief	This is a function called MAGNETIC_Init that intialize the MAGNETIC sensor pin as in input.
 *
 *			
 *
 * \param	void
 * \return  void
 *
 */
void MAGNETIC_Init(void);

/** \brief	This is a function called get_MAGNETIC_status that know the status of the MAGNETIC sensor .
 *
 *			The function first calls another function get pin direction to know the pin status whether high or low then store it in status variable.
 *          
 * \param	The MAGNETIC pin
 * \return  character HIGH or LOW
 *
 */
u8 get_MAGNETIC_status(u8 MAGNETIC_pin);




#endif //_HAL_MAGNETIC_INTERFACE_H_ 
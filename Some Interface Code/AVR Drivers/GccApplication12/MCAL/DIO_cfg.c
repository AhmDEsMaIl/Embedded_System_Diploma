/*
 * DIO_cfg.c
 *
 * Created: 11/2/2022 4:24:43 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "DIO_interface.h"
const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS]={
	OUTPUT,      /* Port A Pin 0 ADC0*/
	OUTPUT,      /* Port A Pin 1 ADC1*/
	OUTPUT,      /* Port A Pin 2 */
	OUTPUT,      /* Port A Pin 3 */
	INPULL,      /* Port A Pin 4 */
	INPULL,      /* Port A Pin 5 */
	INPULL,      /* Port A Pin 6 */
	INPULL,      /* Port A Pin 7 ADC7*/
	OUTPUT,      /* Port B Pin 0   / */
	OUTPUT,      /* Port B Pin 1   /*/
	OUTPUT,		 /* Port B Pin 2 / INT2*/
	OUTPUT,		 /* Port B Pin 3   /OC0*/
	OUTPUT,		 /* Port B Pin 4 /ss*/
	OUTPUT,		 /* Port B Pin 5 //mosi*/
	OUTPUT,		 /* Port B Pin 6 /miso*/
	OUTPUT,		 /* Port B Pin 7 clk*/
	OUTPUT,		 /* Port C Pin 0 */
	INPULL,		 /* Port C Pin 1 */
	INPULL,		 /* Port C Pin 2 */
	INPULL,		 /* Port C Pin 3 */
	OUTPUT,		 /* Port C Pin 4 */
	OUTPUT,		 /* Port C Pin 5 */
	OUTPUT,		 /* Port C Pin 6 */
	OUTPUT,		 /* Port C Pin 7 */
	INPULL,		 /* Port D Pin 0 */
    OUTPUT,		 /* Port D Pin 1 */
    OUTPUT,      /* Port D Pin 2 /INT0*/
	OUTPUT,      /* Port D Pin 3 / INT1 */
	OUTPUT,		 /* Port D Pin 4  OC1B*/
	OUTPUT,		 /* Port D Pin 5 OC1A*/
	OUTPUT,		 /* Port D Pin 6 /   ICP*/
	OUTPUT,		 /* Port D Pin 7 */
	OUTPUT,      /* Port E Pin 0 */
	OUTPUT,      /* Port E Pin 1 */
	OUTPUT,		 /* Port E Pin 2 */ 
	OUTPUT,		 /* Port E Pin 3 */
	OUTPUT,		 /* Port E Pin 4 */
	OUTPUT,		 /* Port E Pin 5 */
	OUTPUT,		 /* Port E Pin 6 */
	OUTPUT,		 /* Port E Pin 7 */
	INFREE,		 /* Port F Pin 0 */
	INFREE,		 /* Port F Pin 1 */
	INFREE,		 /* Port F Pin 2 */
	INFREE,		 /* Port F Pin 3 */
	OUTPUT,		 /* Port F Pin 4 */
	OUTPUT,		 /* Port F Pin 5 */
	OUTPUT,		 /* Port F Pin 6 */
	OUTPUT,		 /* Port F Pin 7 */
	OUTPUT,		 /* Port G Pin 0 */
    OUTPUT,		 /* Port G Pin 1 */
    OUTPUT,      /* Port G Pin 2 */
	OUTPUT,      /* Port G Pin 3 */ 
	OUTPUT,		 /* Port G Pin 4 */
	OUTPUT,		 /* Port G Pin 5 */
	OUTPUT,		 /* Port G Pin 6 */
	OUTPUT,		 /* Port G Pin 7 */
};
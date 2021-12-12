/* Copyright 2016, Eric Pernia.
 * All rights reserved.
 *
 * This file is part sAPI library for microcontrollers.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * Date: 2016-04-26
 */

/*==================[inclusions]=============================================*/
#define SAPI_USE_INTERRUPTS

#include "sapi.h"              // <= sAPI header


/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
/*Función llamada cuando ocurre una hay un dato para leer en el rx de uartUSB
 * Va a elegir dependiendo del caracter leído que led va a prender o apagar
 * y finalmente escribe en el tx de la uart232 el valor leído
 */
void uartUSBreadHook(void *noUsado)
{
	static bool_t ledb_on = false;
	static bool_t led1_on = false;
	static bool_t led2_on = false;
	static bool_t led3_on = false;
	char uartReadBuff;

	uartReadByte(UART_USB, &uartReadBuff);
	switch(uartReadBuff)
	{
	  	 case 'B':
	  		 if(!ledb_on)
	  		 {
	  			 gpioWrite( LEDB, true);
	  			 ledb_on = true;
	  		 }
	  		 else
	  		 {
      			gpioWrite( LEDB, false);
      			ledb_on = false;
      		 }
       		 break;
       	 case '1':
      		 if(!led1_on)
      		 {
       			 led1_on = true;
       			 gpioWrite( LED1, true);
		     }
      		 else
      		 {
		     	 gpioWrite(LED1, false);
		     	 led1_on = false;
		     }
		     break;
		  case '2':
			 if(!led2_on)
		      {
		          gpioWrite( LED2, true);
		          led2_on = true;
		      }
		      else
		      {
		    	  gpioWrite( LED2, false);
		          led2_on = false;
		      }
		      break;
		   case '3':
			   if(!led3_on)
		       {
				   gpioWrite( LED3, true);
		            led3_on = true;
		        }
		        else
		        {
		        	gpioWrite( LED3, false);
		        	led3_on = false;
		        }
		        break;
		     default:
		     	 break;
		  }
	uartWriteByte(UART_232, uartReadBuff);
}

void uart232readHook(void *noUsado)
{
	char dato;
	uartReadByte(UART_232, &dato);
	uartWriteByte(UART_USB, dato);
}

/*==================[external functions definition]==========================*/

/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void){

   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

   gpioConfig( GPIO0, GPIO_INPUT );

   gpioConfig( GPIO1, GPIO_OUTPUT );

   // Inicializar UART_USB a 115200 baudios
   uartConfig( UART_USB, 115200 );

   // Inicializar UART_232 a 115200 baudios
   uartConfig( UART_232, 115200 );

   // Seteo un callback al evento de recepcion y habilito su interrupcion
   uartCallbackSet(UART_USB, UART_RECEIVE, uartUSBreadHook, NULL);
   uartCallbackSet(UART_232, UART_RECEIVE, uart232readHook, NULL);

   // Habilito todas las interrupciones de UART_USB
   uartInterrupt(UART_USB, true);
   uartInterrupt(UART_232, true);

   uartWriteString(UART_USB, "Ejercicio 8 \n\r");
   /* ------------- REPETIR POR SIEMPRE ------------- */
   while(1) {

   }

   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
	return 0 ;
}

/*==================[end of file]============================================*/

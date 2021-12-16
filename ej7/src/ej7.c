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
#include "sapi.h"         // <= sAPI header

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/* FUNCION que se ejecuta cada vez que ocurre un Tick. */
/*
void myTickHook( void *ptr )
{
   static bool_t ledState = OFF;

   gpioMap_t led = (gpioMap_t)ptr;

   if( ledState ) {
      ledState = OFF;
   } else {
      ledState = ON;
   }
   ledState = !gpioRead( led );
   gpioWrite( led, ledState );
}
*/

void onRx( void *noUsado )
{
   char c = uartRxRead( UART_232 );
   //printf( "Recibimos <<%c>> por UART\r\n", c );
   switch(c)
   	   {
   	   	   case '0':
   	   		   gpioWrite( LEDW, ON );
   	           break;
   	       case '1':
   	    	   gpioWrite( LEDW, OFF );
   	    	   break;
   	       case '2':
   	    	   gpioWrite( LED1, ON );
   	           break;
   	       case '3':
   	    	   gpioWrite( LED1, OFF );
   	           break;
   	       case '4':
   	    	   gpioWrite( LED2, ON );
   	           break;
   	       case '5':
   	    	   gpioWrite( LED2, OFF );
   	           break;
   	       case '6':
   	    	   gpioWrite( LED3, ON );
   	           break;
   	       case '7':
   	    	   gpioWrite( LED3, OFF );
   	           break;
   	       /*
   	       case '8':
   	           dacWrite( DAC, EIGHT_OPT);
   	           break;
   	       case '9':
   	           dacWrite( DAC, NINE_OPT);
   	           break;
   	       */
   	       default:
   	           break;
   	    }
}

/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void)
{
   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

   /* Inicializar UART_232 a 115200 baudios */
   uartConfig( UART_232, 115200 );

   // Seteo un callback al evento de recepcion y habilito su interrupcion
   uartCallbackSet(UART_232, UART_RECEIVE, onRx, NULL);
   // Habilito todas las interrupciones de UART_232
   uartInterrupt(UART_232, true);

   /* Inicializar el conteo de Ticks con resolucion de 50ms (se ejecuta
      periodicamente una interrupcion cada 50ms que incrementa un contador de
      Ticks obteniendose una base de tiempos). */
   //tickConfig( 50 );

   /* Se agrega ademas un "tick hook" nombrado myTickHook. El tick hook es
      simplemente una funcion que se ejecutara peri­odicamente con cada
      interrupcion de Tick, este nombre se refiere a una funcion "enganchada"
      a una interrupcion.
      El segundo parametro es el parametro que recibe la funcion myTickHook
      al ejecutarse. En este ejemplo se utiliza para pasarle el led a titilar.
   */
   //tickCallbackSet( myTickHook, (void*)LEDR );
   delay(1000);

   bool_t tec1Value = OFF;
   bool_t tec2Value = OFF;
   bool_t tec3Value = OFF;
   bool_t tec4Value = OFF;
   bool_t ledRValue = OFF;
   bool_t led1Value = OFF;
   bool_t led2Value = OFF;
   bool_t led3Value = OFF;

   //static char uartReadBuff[10];

   /* ------------- REPETIR POR SIEMPRE ------------- */
   while(1) {
	   	   tec1Value = !gpioRead( TEC1 );
	   	   tec2Value = !gpioRead( TEC2 );
	   	   tec3Value = !gpioRead( TEC3 );
	   	   tec4Value = !gpioRead( TEC4 );

	   	   if( tec4Value == ON ){

	   		   ledRValue = !ledRValue;
	   		   gpioWrite( LEDW, ledRValue );
	   		   delay(200);
	   		   uartWriteByte( UART_232, '0'+ ledRValue );
	   		   //uartWriteByte( UART_232, '\n' );
	   		   //delay(200);


	   	   }

	   	   if( tec1Value == ON ){

	   	   		   led1Value = !led1Value;
	   	   		   gpioWrite( LED1, led1Value );
	   	   		   uartWriteByte( UART_232, '2'+ led1Value );
	   	   		   //uartWriteByte( UART_232, '\n' );

	   	   }

	   	   if( tec2Value == ON ){

	   	   		   led2Value = !led2Value;
	   	   		   gpioWrite( LED2, led2Value );
	   	   		   uartWriteByte( UART_232, '4'+ led2Value );
	   	   		   //uartWriteByte( UART_232, '\n' );

	   	   }

	   	   if( tec3Value == ON ){

	   	   		   led3Value = !led3Value;
	   	   		   gpioWrite( LED3, led3Value );
	   	   		   uartWriteByte( UART_232, '6'+ led3Value );
	   	   		   //uartWriteByte( UART_232, '\n' );

	   	   }


      //delay(200);


   }

   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
   return 0 ;
}

/*==================[end of file]============================================*/

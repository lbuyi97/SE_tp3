# Ejercicio 3

Este ejercicio prácticamente consistía en hacer lo siguiente:

```
TECLA (PC) -> TERMINAL (PC) -> UART (USB).RX -> LED
```

Al revés que el ejercicio 2. Al recibir un caracter por UART se enciende o apaga un LED.

Primero esperando la lectura de un byte en la UART y luego por interrupción de la misma.

Las funciones más importantes para este ejercicio fueron:


```c
void uartInit( uartMap_t uart, uint32_t baudRate )

```

Inicializa la UART "uart" con un baudrate de valor "baudRate".

```c
bool_t gpioRead( gpioMap_t pin )

```

Lee el estado de "pin", se usó para leer a los pulsadores.

```c
bool_t gpioWrite( gpioMap_t pin, bool_t value )

```

Escribe el estado "value" en "pin", se usó para prender y apagar los LEDs.

```c
void uartWriteByte( uartMap_t uart, const uint8_t value )

```

Escribe el byte "value" en la "uart" que se le pase, se usó para enviar los caracteres a la terminal.

```c
void onRx( void *noUsado )
{
   char c = uartRxRead( UART_USB );
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
   	    	   gpioWrite( LEDW, OFF );
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

```

En la rutina/función que será llamada en cada interrupción de la UART_USB por Rx. Cada caracter tiene una función de apagar o prender cierto LED.

Esto se setea con las siguientes funciones:

```c
   // Seteo un callback al evento de recepcion y habilito su interrupcion
   uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL);
   // Habilito todas las interrupciones de UART_USB
   uartInterrupt(UART_USB, true);
```

Luego se combinó la funcionalidad de prender/apagar LEDs tanto por pulsador como por UART_USB Rx

```
TEXTO(PANTALLA) <- TERMINAL (PC) <- UART (USB).TX <- PULSADOR
TECLA (PC) -> TERMINAL (PC) -> UART (USB).RX -> LED
```

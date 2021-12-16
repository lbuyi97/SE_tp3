# Ejercicio 2

Este ejercicio prácticamente consistía en hacer lo siguiente:

```
PULSADOR -> LED -> UART (USB).TX -> TERMINAL (PC) -> TEXTO(PANTALLA)
```

Al presionar un pulsador se enciende o apaga un LED y, haciendo uso de la UART_USB, escribir un caracter en la terminal.

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

El programa consiste en leer el estado de los botones, cada uno asignado a un LED distinto, y en el caso de estar pulsados, cambiar el estado del LED asociado a ese pulsador.

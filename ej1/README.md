a)
Lo que se pide es que según las definiciones y directivas que se le dan al preprocesador.
Todo lo que esté dentro de una estructura como esta:
```
#ifdef X_MACRO
...
#endif
```


será compilado unicamente si X_MACRO ha sido definida.

También se admiten estructuras de este tipo:

```
#if X_MACRO == X_VALOR
...
#endif
```

en las cuales será compilado el bloque si X_MACRO está definido y vale X_VALOR.

De esta manera se pueden tener varios bloques de códigos (o programas enteros) dentro de un mismo archivo y "elegir" con un #define cuales de los bloques se quieren compilar.

Ejemplo:

![This is an image](./pre.png)


b)
Se ve a continuación una captura del código del archivo 'switches_led.c'

![This is an image](./ej2_01.png)

Primero tenemos a la función 'gpioConfig' que tiene la siguiente definición en el archivo 'sapi_gpio.h'
```
#define gpioConfig  gpioInit
```

'gpioInit' es una función que está desarrollada en 'sapi_gpio.c' con el siguiente prototipo:
```
bool_t gpioInit( gpioMap_t pin, gpioInit_t config )
```

El tipo 'gpioMap_t' está declarado en 'sapi peripheral_map.h' como tipo enumerativo en la cual le da un nombre a cada pin según número.

El tipo 'gpioInit_t' está declarado en 'sapi gpio.h' como tipo enumerativo en la cual le da un nombre a cada configuración posible de cada GPIO
```
typedef enum {
   GPIO_INPUT, GPIO_OUTPUT,
   GPIO_INPUT_PULLUP, GPIO_INPUT_PULLDOWN,
   GPIO_INPUT_PULLUP_PULLDOWN,
   GPIO_ENABLE
} gpioInit_t;
```

Lo que hace 'gpioInit' es configurar el 'pin' con la configuración 'config'.

La función 'gpioRead( gpioMap_t pin )' está desarrollada en el archivo 'sapi_gpio.c' y lo que hace el leer y devolver el estado del pin que se le pase como parámetro. Esto lo hace con la función 'Chip_GPIO_ReadPortBit' definida en 'gpio_18xx_43xx.h' cuyo código es: 
```
STATIC INLINE bool Chip_GPIO_ReadPortBit(LPC_GPIO_T *pGPIO, uint32_t port, uint8_t pin)
{
	return (bool) pGPIO->B[port][pin];
}
```
La estructura 'LPC_GPIO_T' está definida también en 'gpio_18xx_43xx.h':
```
typedef struct {				/*!< GPIO_PORT Structure */
	__IO uint8_t B[128][32];	/*!< Offset 0x0000: Byte pin registers ports 0 to n; pins PIOn_0 to PIOn_31 */
	__IO uint32_t W[32][32];	/*!< Offset 0x1000: Word pin registers port 0 to n */
	__IO uint32_t DIR[32];		/*!< Offset 0x2000: Direction registers port n */
	__IO uint32_t MASK[32];		/*!< Offset 0x2080: Mask register port n */
	__IO uint32_t PIN[32];		/*!< Offset 0x2100: Portpin register port n */
	__IO uint32_t MPIN[32];		/*!< Offset 0x2180: Masked port register port n */
	__IO uint32_t SET[32];		/*!< Offset 0x2200: Write: Set register for port n Read: output bits for port n */
	__O  uint32_t CLR[32];		/*!< Offset 0x2280: Clear port n */
	__O  uint32_t NOT[32];		/*!< Offset 0x2300: Toggle port n */
} LPC_GPIO_T;
```

La función 'gpioWrite( gpioMap_t pin, bool_t value )' está desarrollada en el archivo 'sapi_gpio.c' y lo que hace es escribir el estado 'value' en el 'pin' que se le pase como parámetro. Esto lo hace con la función 'Chip_GPIO_SetPinState' definida en 'gpio_18xx_43xx.h' cuyo código es: 
```
STATIC INLINE void Chip_GPIO_SetPinState(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin, bool setting)
{
	pGPIO->B[port][pin] = setting;
}
```

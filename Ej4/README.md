# Ejercicio 4

Para este ejercicio se utilizó como base el programa **rgb_led_uart** y se le agregó la funcionalidad de aumentar y disminuir el brillo. Para ello se hicieron uso de las siguientes funciones de la la librería de **sapi_rgb**:

```c
uint8_t rgbReadDutyRed( LedRgbMap_t rgbLed );

uint8_t rgbReadDutyGreen( LedRgbMap_t rgbLed );

uint8_t rgbReadDutyBlue( LedRgbMap_t rgbLed );
```

Las cuales leen el duty cycle de cada uno de los tres LEDs que componen a "rgbLed".

```c
void rgbWriteRaw( LedRgbMap_t rgbLed, int8_t dutyRed, int8_t dutyGreen, int8_t dutyBlue );
```

Establece el duty cycle de cada uno de los LEDs que componen a "rgbLed".

Adcionalmente, una función importante usada para otras inicializar el LED rgb es:

```c
bool_t rgbInit( LedRgbMap_t rgbLed, uint8_t pinRed, uint8_t pinGreen, uint8_t pinBlue );
```

En la cual se pasa como parámetro que LEDs se van a usar para cada uno de los colores y "rgbLed" puede tomar hasta nueve valores distintos (no se puede inicializar más de nueve LEDs rgb al mismo tiempo).


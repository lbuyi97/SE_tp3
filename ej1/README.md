Lo que se pide es que según las definiciones y directivas que se le dan al preprocesador.
Todo lo que esté dentro de una estructura como esta:
```
#ifdef X_MACRO
...
#endif
```

● uartConfig( UART_USB, 115200 );
Funciones invocadas: 'uartInit'; Chip_UART_Init; Chip_UART_SetBaud; Chip_UART_SetupFIFOS; Chip_UART_ReadByte; Chip_UART_TXEnable; Chip_SCU_PinMux; Chip_UART_SetRS485Flags; Chip_SCU_PinMux
Archivo se encuentran: definido en 'sapi_uart.h' y desarrollada en 'sapi_uart.c'
Descripción: Está defininada como 'uartInit', iniciliza la UART_USB con el baudrate indicado
Hardware: incide sobre la UART_USB del micro/EDU-CIAA

● adcConfig( ADC_ENABLE );
Funciones invocadas: 'adcInit', Chip_ADC_Init; Chip_ADC_SetBurstCmd; Chip_ADC_SetSampleRate; Chip_ADC_EnableChannel; Chip_ADC_Int_SetChannelCmd; Chip_SCU_ADC_Channel_Config; Chip_ADC_DeInit
Archivo se encuentran: definido en 'sapi_adc.h' y desarrollada en 'sapi_adc.c'
Descripción: Está defininada como 'adcInit', iniciliza el ADC
Hardware: activa el ADC interno del micro

● dacConfig( DAC_ENABLE );
Funciones invocadas: 'dacInit', Chip_Clock_EnableOpts; Chip_DAC_SetBias; Chip_DAC_ConfigDAConverterControl; Chip_DAC_UpdateValue; Chip_DAC_DeInit
Archivo se encuentran: definido en 'sapi_dac.h' y desarrollada en 'sapi_dac.c'
Descripción: Está defininada como 'dacInit', iniciliza el DAC
Hardware: activa el DAC interno del micro

● delayConfig( &delay, 500 );
Funciones invocadas: 'delayInit'
Archivo se encuentran: definido en 'sapi_delay.h' y desarrollada en 'sapi_delay.c'
Descripción: Está defininada como 'delayInit', configura el valor del delay, que es una estructura 'delay_t'
Hardware: 

● muestra = adcRead( CH1 );
Funciones invocadas: Chip_ADC_EnableChannel; Chip_ADC_SetStartMode; Chip_ADC_ReadStatus; Chip_ADC_ReadValue; Chip_ADC_EnableChannel
Archivo se encuentran: 'sapi_adc.c'
Descripción: Manda a convertir el ADC y espera hasta que termine de convertir y ese valor lo devuelve por retorno a 'muestra'
Hardware: Pone en acción al ADC del micro

● uartReadByte( UART_USB, &dato )
Funciones invocadas: uartRxReady; uartRxRead;
Archivo se encuentran: 'sapi_uart.c'
Descripción: lee un byte que se encuentre en la UART_USB  y lo guarda en 'dato'
Hardware: lee el RX de la UART_USB

● uartWriteByte( UART_USB, dato )
Funciones invocadas: uartTxReady; uartTxWrite;
Archivo se encuentran: 'sapi_uart.c'
Descripción: lescibe un byte eb UART_USB con el valor 'dato'
Hardware: escribe el TX de la UART_USB

● uartWriteString( UART_USB, "ADC CH1 value: " );
Funciones invocadas: uartWriteByte
Archivo se encuentran: 'sapi_uart.c'
Descripción: escribe todos los bytes (char) de una string en la UART_USB
Hardware: escribe el TX de la UART_USB varias veces

● dacWrite( DAC, muestra );
Funciones invocadas: Chip_DAC_UpdateValue
Archivo se encuentran:'sapi_dac.c'
Descripción: escribe un valor en el DAC
Hardware: setea un nivel de tensión en el DAC del micro

● uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL);
Funciones invocadas: Chip_UART_IntEnable
Archivo se encuentran: 'sapi_uart.c'
Descripción: Setea un callback al evento de recepción y habilita su interrupción
Hardware: 

● uartInterrupt(UART_USB, true);
Funciones invocadas: uartInterrupt
Archivo se encuentran: 'sapi_uart.c'
Descripción: activa la interrupción de la UART_USB
Hardware: activa o desactiva la interrupción del UART_USB

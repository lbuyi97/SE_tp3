# Ejercicio 7

Este ejercicio prácticamente consistía en hacer uso del ejercicio 2 y 3, en donde al presionar una tecla de la PC se encendía un LED (haciendo uso de la UART_USB). La diferencia está en que también se usa el pin Tx de la UART_232 para transmitir un caracter que representa esta operación. Además, como se conecta un resistor entre el pin Tx y Rx de la UART_232, por el pin Rx se va a recibir el mismo caracter que se transmite por Tx y, finalmente, se transmite por el pin Tx de la UART_USB lo recibido por el pin Rx de la UART_232 para observar el resultado por pantalla. En las siguientes imágenes se muestra un esquema de esta operación para que se entienda mejor y el resultado en la terminal al presionar la tecla 'B':

Hubo que reemplazar "UART_232" en donde decía "UART_USB" y puntear el RX y TX de la "UART_232" con una resistencia de 1 kOhm.

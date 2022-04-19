# **Smart Scale v1.0**

Este repositorio contiene el código correspondiente a un sistema de balanza inteligente. 

Autores: [Ariel SALASSA](https://www.linkedin.com/in/ariel-salassa/) y [Francisco TINELLI](https://www.linkedin.com/in/francisco-tinelli/)

Video del funcionamiento: https://youtu.be/6WA8JFrn00A

Repositorio mercurial en MBED: https://os.mbed.com/users/frank6/code/SmartScale/
 
## **Objetivo y descripción del proyecto**
 
El objetivo de este proyecto fue poner en practica los conocimientos adquiridos a lo largo del curso Introducción a los Sistemas Embebidos de la Especialización en Inteligencia Artificial de la Universidad de Buenos Aires (UBA).
 
El mismo consiste en un sistema de balanza inteligente. Al energizar, el micro-controlador realiza la tara de la balanza y comienza a mostrar el peso medido en la pantalla. Luego de colocar el objeto a pesar, el valor del peso se estabiliza y el usuario puede pulsar "A" para registrarlo. En ese momento, se pide el ingreso de un ID de 4 dígitos luego del cual se debe pulsar "#". Los datos son enviados a un servidor web mediante un modulo Wifi y el sistema vuelve al estado de medición inicial. 
 
En el estado de medición, se puede solicitar realizar la tara nuevamente pulsando el botón USER en la placa núcleo. También puede calibrarse el factor de escala colocando un peso conocido, pulsando "C" y utilizando el potenciómetro para obtener el valor exacto.
 
## **Componentes del sistema**
 
* El micro-controlador principal usado en este proyecto es una [Nucleo F411RE](https://www.st.com/en/evaluation-tools/nucleo-f411re.html).
* Para el pesaje se utiliza una celda de carga de 5kg junto con el integrado [HX711](https://articulo.mercadolibre.com.ar/MLA-860426429-celda-de-carga-5kg-con-amplificador-hx711-sensor-de-peso-_JM).
* Para la interaccion con el usuario, se utiliza un [teclado matricial](https://articulo.mercadolibre.com.ar/MLA-726324253-teclado-membrana-matricial-4x4-keypad-arduino-autoadhesivo-_JM#position=1&search_layout=grid&type=item&tracking_id=aec4933d-e79b-4880-9685-83439ee656b4) y un [display grafico](https://articulo.mercadolibre.com.ar/MLA-663750418-display-grafico-lcd-128x64-verde-bl-st7920-arduino-itytarg-_JM#position=19&;search_layout=grid&type=item&tracking_id=996fa9f1-7a5b-4bd5-bddd-67e793e2a35a).
* Los resultados son enviados a un servidor web mediante un modulo [ESP-01 (ESP-8266)](https://articulo.mercadolibre.com.ar/MLA-869705571-esp-01-modulo-wifi-esp8266-serie-stack-tcp-ip-wifi-antena-_JM#position=1&search_layout=grid&type=item&tracking_id=b49d5367-11c3-4ed5-8adb-2a1b012efb2a).
 
## **Diagrama en bloques**
 
![SE block diagram](https://user-images.githubusercontent.com/38406318/164114131-750e2149-da86-4ba7-85c3-9f2b2e28a117.png)
 
## **Maquina de estado del sistema**
 
![SE state machine (1)](https://user-images.githubusercontent.com/38406318/164114111-85b6e36f-4570-4d3b-82f4-aa17bdda1da4.png)
 
## **Conexionado del hardware**
 
![SE conexionado (1)](https://user-images.githubusercontent.com/38406318/164114086-8291930f-a432-4ca0-8c0a-d286a2d0f86c.jpg)

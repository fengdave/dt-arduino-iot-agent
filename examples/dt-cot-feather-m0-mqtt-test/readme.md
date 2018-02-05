# Example: Feather M0 with MQTT over WiFi

-------------------------------------------------------------------------------
## Description
This example is an Arduino sketch that implements an MQTT client over WiFi on an Adafruit Feather M0. At the moment this example cannot yet access the DT CoT. Instead, it shows the access of the Adafruit IO MQTT service.

-------------------------------------------------------------------------------
## Important Notes
Please check the following things before you try to compile any of the examples:
* Make sure to have all neccesary Arduino libraries and board support installed, [as described here](../../arduino_setup.md).
* This example comes with a specific configuration header file ("DTCoTSetup.h"). This file must be copied manually into the library directory ("src/") before the first compilation of this sketch.
* Each examples requires specific pieces of hardware, access to the Cloud of Things or credentials for usage of NB-IoT. Please find the details below.
* Each example requires a set of credentials to access the local WiFi or the MQTT service. These credentials need to be provided in a specific file ("secrets.h") before compilation.

-------------------------------------------------------------------------------
## Prerequisites

The following prerequisites are neccesary to run this example:
* Adafruit Feather M0
* Access to the [Adafruit IO MQTT service](https://learn.adafruit.com/adafruit-io/mqtt-api)


-------------------------------------------------------------------------------
## Step by Step Guide

* This example comes with a specific configuration header file ("DTCoTSetup.h"). This file must be copied manually into the library directory ("src/") before the first compilation of this sketch.
* Each example requires a set of credentials to access the local WiFi or the MQTT service. These credentials need to be provided in a specific file ("secrets.h") before compilation.
* Make sure to select "Adafruit Feather M0" board support in Arduino before compilation (menu: Tools->Board->"Adafruit Feather M0"). If you can't find the board [please re-check your Arduino IDE setup](../../arduino_setup.md).
* Make sure to select the correct serial interface (menu: Tools->Port...). If you can't find your Adafruit Feather M0 there check the connection between the board and your computer.
* Compile and flash the sketch onto the board.
* Open the serial monitor to see the device's activity (menu Tools->Serial Monitor)

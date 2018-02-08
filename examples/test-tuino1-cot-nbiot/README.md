# Example: Tuino1 with MQTT-SN over NB-IoT

-------------------------------------------------------------------------------
## Description
This example implements an MQTT-SN client over Narrowband Internet of Things (NB-IoT) on a Tuino1.

-------------------------------------------------------------------------------
## Important Notes
Please check the following things before you try to compile any of the examples:
* Make sure to have all neccesary Arduino libraries and board support installed, [as described here](../../arduino_setup.md).
* This example comes with a specific configuration header file ("DTCoTSetup.h"). This file must be copied manually into the library directory ("src/") before compilation of the related sketch.
* Each examples requires specific pieces of hardware, access to the Cloud of Things or credentials for usage of NB-IoT. Please find the details below.
* Each example requires a set of credentials to access the MQTT-SN service. These credentials need to be provided in a specific file ("secrets.h") before compilation.

-------------------------------------------------------------------------------
## Prerequisites

The following prerequisites are neccesary to run this example:
* [Gimasi Tuino1](http://www.tuino.io/)
* Gimasi NB-IoT module (based on Quectel BC95)
* NB-IoT compatible SIM card
* Access to a remote MQTT-SN service.

-------------------------------------------------------------------------------
## Step by Step Guide

* This example comes with a specific configuration header file ("DTCoTSetup.h"). This file must be copied manually into the library directory ("src/") before the first compilation of this sketch.
* Each example requires a set of credentials to access the MQTT-SN service. These credentials need to be provided in a specific file ("secrets.h") before compilation.
* Make sure to select Tuino1 board support in Arduino before compilation (menu: Tools->Board->"Tuino1"). If you can't find the board [please re-check your Arduino IDE setup](../../arduino_setup.md).
* Make sure to select the correct serial interface (menu: Tools->Port...). If you can't find your Tuino1 there check the connection between the board and your computer.
* Make sure to have a valid SIM card in the NB-IoT modem.
* Plug the Gimasi NB-IoT modem into the modem socket of the Tuino1.
* Compile and flash the sketch onto the board.
* Open the serial monitor to see the device's activity (menu Tools->Serial Monitor)

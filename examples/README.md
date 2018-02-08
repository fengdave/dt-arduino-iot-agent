# Usage Examples For The Cloud Of Things Arduino Library

This document describes how to setup and run the usage examples of the Cloud Of Things library. All examples are Arduino sketches for different types of hardware platforms and different protocols. 

-------------------------------------------------------------------------------
## Important Notes
Please check the following things before you try to compile any of the examples:
* Make sure to have all neccesary Arduino libraries and board support installed, [as described here](../arduino_setup.md).
* Each example comes with a specific configuration header file ("DTCoTSetup.h"). This file must be copied manually into the library directory ("src/") before compilation of the related sketch.
* Each examples requires specific pieces of hardware, access to the Cloud of Things or credentials for usage of NB-IoT. Please find the details below.
* Each example requires a set of credentials to access the local WiFi or the MQTT/MQTT-SN service. These credentials need to be provided in a specific file ("secrets.h") before compilation.
* Make sure to always select the appropriate Board support in Arduino before compilation.

-------------------------------------------------------------------------------
## Examples
The following examples are available (click on the links below to learn more):

### [Feather M0: MQTT over WiFi](dt-cot-feather-m0-mqtt-test/readme.md)
This example is an Arduino sketch that implements an MQTT client over WiFi on an Adafruit Feather M0. At the moment this example cannot yet access the DT CoT. Instead, it shows the access of the Adafruit IO MQTT service. 

### [Feather M0: MQTT-SN over NB-IoT](test-feather-m0-ublox-cot-nbiot/readme.md)
This example is an Arduino sketch that implements an MQTT-SN client over Narrowband Internet of Things (NB-IoT) on an Adafruit Feather M0. 

### [Huzzah: MQTT over WiFi](test-huzzah-mqtt/readme.md)
This example is an Arduino sketch that implements an MQTT client over WiFi on a Huzzah ESP8266. At the moment this example cannot yet access the DT CoT. Instead, it shows the access of the Adafruit IO MQTT service. 

### [Tuino1: MQTT-SN over NB-IoT](test-tuino1-cot-nbiot/readme.md)
This example is an Arduino sketch that implements an MQTT-SN client over Narrowband Internet of Things (NB-IoT) on a Tuino1. 

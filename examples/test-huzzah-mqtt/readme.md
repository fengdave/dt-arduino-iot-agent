# Example: Feather M0 with MQTT over WiFi

## Description
This example implements an MQTT client over WiFi on a Huzzah ESP8266. At the moment this example cannot yet access the DT CoT. Instead, it shows the access of the Adafruit IO MQTT service. 

-------------------------------------------------------------------------------
## Important Notes
Please check the following things before you try to compile any of the examples:
* Make sure to have all neccesary Arduino libraries and board support installed, [as described here](../../mainpage.md).
* This example comes with a specific configuration header file ("DTCoTSetup.h"). This file must be copied manually into the library directory ("src/") before compilation of the related sketch.
* Each examples requires specific pieces of hardware, access to the Cloud of Things or credentials for usage of NB-IoT. Please find the details below.
* Each example requires a set of credentials to access the local WiFi or the MQTT/MQTT-SN service. These credentials need to be provided in a specific file ("secrets.h") before compilation.
* Make sure to always select the appropriate Board support in Arduino before compilation.

-------------------------------------------------------------------------------
## Prerequisits

The following prerequisits are neccesary to run this example:
* Huzzah ESP8266
* WiFi cape
* Access to the [Adafruit IO MQTT service](https://learn.adafruit.com/adafruit-io/mqtt-api)

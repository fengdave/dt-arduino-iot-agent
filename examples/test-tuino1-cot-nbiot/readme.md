# Example: Tuino1 with MQTT-SN over NB-IoT

## Description
This example implements an MQTT-SN client over Narrowband Internet of Things (NB-IoT).

-------------------------------------------------------------------------------
## Important Notes
Please check the following things before you try to compile any of the examples:
* Make sure to have all neccesary Arduino libraries and board support installed, [as described here](../../mainpage.md).
* This example comes with a specific configuration header file ("DTCoTSetup.h"). This file must be copied manually into the library directory ("src/") before compilation of the related sketch.
* Each examples requires specific pieces of hardware, access to the Cloud of Things or credentials for usage of NB-IoT. Please find the details below.
* Each example requires a set of credentials to access the MQTT-SN service. These credentials need to be provided in a specific file ("secrets.h") before compilation.
* Make sure to always select the appropriate Board support in Arduino before compilation.

-------------------------------------------------------------------------------
## Prerequisits

The following prerequisits are neccesary to run this example:
* [Gimasi Tuino1](http://www.tuino.io/)
* Gimasi NB-IoT module (based on Quectel BC95)
* NB-IoT compatible SIM card
* Access to a remote MQTT-SN service.

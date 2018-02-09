# Quickstart Guide: Setup of EVK-N2 and Adafruit Feather M0 WiFi

---
## Abstract
This quickstart guide is supposed to illustrate the setup process for the Adafruit Feather M0 WiFi board (“Feather”) and the evaluation kit EVK-N2 (“EVK”).

---
## Hardware
For the setup the Feather and the EVK are required:

![Adafruit Feather M0 WiFi](doc/Adafruit_Feather_M0_WiFi.jpg)

Adafruit Feather M0 WiFi

![u-blox Evaluation Kit EVK-N2](doc/ublox_EVK-N2.png)

u-blox Evaluation Kit EVK-N2

Furthermore, the following equipment is required for the setup:

Quantity | Description              | Function
---------| ------------------------ | --------
5 | Wired Jumper type female-female	| UART connection between Feather and EVK.
1 | USB-to-MicroUSB	                | Serial interface and power supply for Feather.
1 | USB-to-MiniUSB                  | Power supply for EVK.
1 | Antenna	                        | Radio/NB-IoT connectivity.


---
## Pinout Overview
![Bottom View of Feather M0, relevant pins highlighted red](doc/FeatherM0BottomView.png)

Bottom View of Feather M0, relevant pins highlighted red.

![Ublox EVK with relevant areas highlighted in red](doc/u-blox_EVK_pinout.png)

Ublox EVK, relevant areas highlighted in red.

**Note:** Both, Pin1 and Pin2 of the pin headers "DIL B2B J101" and "DIL B2B J104" are already marked on the board. Count up the pins of those pin headers accordingly to determine the referred pins.

---
## Connecting EVK-N2 and Feather M0
The following steps are required to connect the two components:

### Preparations on EVK:
* Connect the provided antenna with the SMA connector “Cellular antenna connector J102”.
* Insert an appropriate NB-IoT SIM card into the “SIM card holder J300”.
* Make sure the switch “SW401” is set to “B2B”.

### Connections between Feather and EVK pin header “DIL B2B connector J101”:

Feather        | EVK: Pin header “DIL B2B connector J101”
-------------- | ----------------------------------------
Pin "3V"       | Pin7 or Pin8
Pin "GND"      | Pin1
Pin "33/A9/10" | Pin26

### Connections between Feather and EVK pin header “DIL B2B connector J104”:

Feather        | EVK: Pin header “DIL B2B connector J104”
-------------- | ----------------------------------------
Pin "TX"       | Pin15
Pin "RX"       | Pin16

### Final Steps
Connect the Feather and the EVK with the appropriate USB cables. The communication between the devices will be established using the provided software (TODO which one). 

---
## Abbreviations
Term   | Meaning
------ | --------------------------------------------
NB-IoT | Narrowband Internet of Things (LTE Cat NB1)
UART   | Universal asynchronous receiver-transmitter

---
## Related Documents
Source                                                            | Date
----------------------------------------------------------------- | --------------------------------
[Adafruit Feather M0 WiFi](https://www.adafruit.com/product/3010) | 05.02.2018
[u-blox EVK N2](https://www.u-blox.com/de/product/evk-n2)         | 05.02.2018
[Feather Pinout](https://www.adafruit.com/product/3010)           | 05.02.2018
[u-blox EVK with relevant areas highlighted in red](https://www.u-blox.com/sites/default/files/EVK-N2_UserGuide_%28UBX-17005115%29.pdf) | 05.02.2018


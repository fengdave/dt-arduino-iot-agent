#include <DTCoTDeviceWifi.h>

#include <WiFi.h>
#include <WiFiClient.h>

using namespace DTCoT;

/*DeviceWiFi::DeviceWiFi() {

}*/

void DeviceWiFi::connect(char * ssid, char * password) {
    delay(10);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
    }
}


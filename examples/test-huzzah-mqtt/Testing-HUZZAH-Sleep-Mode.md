# Testing Huzzah Sleep modes

If the huzzah shall be used in sleep mode the following need to be done:

1. The Pins GPIO16 and RST need to be connecte
2. At the end of the loop, the following command shall be called:

ESP.deepSleep(5e6);

This will put thet Huzzah into deep sleep for 5 seconds. During this, the huzzah will be completely shut down so while coming back from deep sleep, the huzzah will start the sketch from beginning.

There are other sleep modes which only sets the wifi part into sleep. A good introduction can be read here: https://www.losant.com/blog/making-the-esp8266-low-powered-with-deep-sleep
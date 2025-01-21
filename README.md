# Code_NodeMCU_Alexa_Arduino_IotCloud_4Relays
 This project integrates an ESP8266 microcontroller with the Arduino IoT Cloud for controlling multiple devices via Alexa or other smart platforms.
 
1. arduino_secrets.h: Contains sensitive details such as Wi-Fi credentials (SSID, PASS) and a secret device key used for secure IoT communication​.

2. thingProperties.h: Initializes IoT properties and configurations, linking cloud-controlled switches (like lights, fans, etc.) with the Arduino IoT Cloud. It defines events for device state changes and sets up a Wi-Fi connection handler​.

3. Code_NodeMCU_Alexa_ArduinoIotCloud_4Relays.ino: Implements the core logic to manage relays connected to appliances. This script facilitates device control via Alexa and synchronizes with the IoT Cloud.

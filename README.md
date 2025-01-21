# Code_NodeMCU_Alexa_Arduino_IotCloud_4Relays
 This project integrates an ESP8266 microcontroller with the Arduino IoT Cloud for controlling multiple devices via Alexa or other smart platforms.

# 🔶Folder ➜Code_NodeMCU_Alexa_ArduinoIotCloud_4Relays:
⚠️this folder have 3 files and 1 picture , lets explain this files

  1. arduino_secrets.h: Contains sensitive details such as Wi-Fi credentials (SSID, PASS) and a secret device key used for secure IoT communication​.

  2. thingProperties.h: Initializes IoT properties and configurations, linking cloud-controlled switches (like lights, fans, etc.) with the Arduino IoT Cloud. It defines events for device state changes and sets up a Wi-Fi connection handler​.

  3. Code_NodeMCU_Alexa_ArduinoIotCloud_4Relays.ino: Implements the core logic to manage relays connected to appliances. This script facilitates device control via Alexa and synchronizes with the IoT Cloud.
     
  4. this picture explain how we connect our devices

  # 🔷Folder ➜Smart Door Lock:
  ⚠️this folder have 1 files and 1 picture , lets explain this files
  
    ⇨ This Arduino sketch is designed to control a secure door system with a keypad and servo motor. It uses a 4x4 matrix keypad for input, an LCD display for messages, and a servo motor to         lock or unlock the door. The user must enter a predefined password ("123*#") to open the door. If the entered password matches the stored one, the servo motor moves to unlock the door,        and a message indicating the door is open is displayed. After a short delay, the door automatically relocks. The system allows the user to close the door manually by pressing the '#' key.

 ⇨The code is structured with helper functions to manage different tasks, including ServoOpen and ServoClose for servo control, clearData for resetting the password entry, and loading for       displaying a progress message on the LCD. In the loop function, the system checks if the door is open and handles password entry or closure commands. The LCD displays feedback, enhancing      user interaction. This modular design ensures simplicity and clarity while effectively managing the security workflow. ​

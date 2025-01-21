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
  
   ⚀ Key Features:​\n
      ⇨ Components Used:​\n
         1. 4x4 Matrix Keypad: Allows user input for the password.​\n
         2. LCD Display: Displays messages and feedback to the user.​\n
         3. Servo Motor: Controls the locking and unlocking of the door.​\n
         
   ⚁ Password Protection:
      1. A predefined password ("123*#") is stored in the program.
      2. The system compares the user’s input with the predefined password.
      3. If the password matches, the door unlocks; otherwise, it displays an error message.
      
   ⚂ Servo Motor Control:
      1. ServoOpen(): Unlocks the door by rotating the servo to an open position.
      2. ServoClose(): Locks the door by rotating the servo back to a closed position.
      
   ⚃ Interactive Feedback:
      1. Displays messages like "Enter Password," "Door is Open," or "Wrong Password" on the LCD.
      2. Includes a loading() function for dynamic messages with a loading effect.
      
   ⚄ Automatic Locking:
     1. After the door is opened, the system waits for a set time before automatically relocking.
     
   ⚅ Manual Closure:
    1. Pressing the '#' key closes the door manually.
    
   🔻Code Flow:
      1️⃣ Setup:
          1. Initializes the keypad, servo, and LCD.
          2. Displays a welcome message and prepares the door in a locked state.
      2️⃣ Main Loop:
         Checks if the door is open:
           1. If open, listens for the '#' key to close the door.
           2. If closed, prompts the user to enter the password.
      3️⃣ Password Handling:
          1. Accepts character input from the keypad and displays it on the LCD.
          2. Validates the entered password when the length matches the required size.
          3. Clears input after each attempt.

# Code_NodeMCU_Alexa_Arduino_IoTCloud_4Relays

This project integrates an ESP8266 microcontroller with the Arduino IoT Cloud for controlling multiple devices via Alexa or other smart platforms.

## 🔶 Folder: `Code_NodeMCU_Alexa_ArduinoIotCloud_4Relays`
This folder contains three essential files and a diagram to help you connect your devices:

### 1. `arduino_secrets.h`
- Stores sensitive information like:
  - **Wi-Fi credentials** (`SSID`, `PASS`)
  - **Secret device key** for secure IoT communication.

### 2. `thingProperties.h`
- Initializes IoT properties and configurations.
- Links cloud-controlled switches (e.g., lights, fans) with the Arduino IoT Cloud.
- Defines events for device state changes.
- Sets up a Wi-Fi connection handler.

### 3. `Code_NodeMCU_Alexa_ArduinoIotCloud_4Relays.ino`
- Implements the core logic to manage relays connected to appliances.
- Enables device control via Alexa.
- Synchronizes with the IoT Cloud for real-time updates.

### 4. Circuit Diagram
- Provides a visual representation of how to connect your devices.

---

## 🔷 Folder: `Smart Door Lock`
This folder contains one file and one diagram detailing the implementation of a secure smart door lock system.

### ⚀ Key Features
#### Components Used:
1. **4x4 Matrix Keypad**: Allows user input for the password.
2. **LCD Display**: Displays messages and feedback to the user.
3. **Servo Motor**: Controls the locking and unlocking of the door.

#### Password Protection:
1. A predefined password (`"123*#"`) is stored in the program.
2. The system compares the user’s input with the predefined password.
3. If the password matches, the door unlocks; otherwise, it displays an error message.

#### Servo Motor Control:
1. `ServoOpen()`: Unlocks the door by rotating the servo to an open position.
2. `ServoClose()`: Locks the door by rotating the servo back to a closed position.

#### Interactive Feedback:
1. Displays messages such as "Enter Password," "Door is Open," or "Wrong Password" on the LCD.
2. Includes a `loading()` function for dynamic messages with a loading effect.

#### Automatic Locking:
1. After the door is opened, the system waits for a set time before automatically relocking.

#### Manual Closure:
1. Pressing the `#` key closes the door manually.

### ⚁ Code Flow
1. **Setup:**
   - Initializes the keypad, servo, and LCD.
   - Displays a welcome message and prepares the door in a locked state.
2. **Main Loop:**
   - Checks if the door is open:
     - If open, listens for the `#` key to close the door.
     - If closed, prompts the user to enter the password.
3. **Password Handling:**
   - Accepts character input from the keypad and displays it on the LCD.
   - Validates the entered password when the length matches the required size.
   - Clears input after each attempt.

---

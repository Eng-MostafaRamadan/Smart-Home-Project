#include "arduino_secrets.h"
#include "thingProperties.h"

// define the GPIO connected with Relays and switches
#define RelayPin1 5  //D1
#define RelayPin2 4  //D2
#define RelayPin3 14 //D5
#define RelayPin4 12 //D6
#define RelayPin5 15 //D8 

#define SwitchPin1 10  //SD3
#define SwitchPin2 0   //D3 
#define SwitchPin3 13  //D7
#define SwitchPin4 3   //RX

#define wifiLed   16   //D0

int toggleState_1 = 0; //Define integer to remember the toggle state for relay 1
int toggleState_2 = 0; //Define integer to remember the toggle state for relay 2
int toggleState_3 = 0; //Define integer to remember the toggle state for relay 3
int toggleState_4 = 0; //Define integer to remember the toggle state for relay 4
int toggleState_5 = 0; //Define integer to remember the toggle state for relay 5

void relayOnOff(int relay) {
  switch (relay) {
    case 1:
      if (toggleState_1 == 0) {
        digitalWrite(RelayPin1, HIGH); // turn on relay 1
        toggleState_1 = 1;
        Serial.println("Device1 ON");
      } else {
        digitalWrite(RelayPin1, LOW); // turn off relay 1
        toggleState_1 = 0;
        Serial.println("Device1 OFF");
      }
      delay(100);
      break;
    case 2:
      if (toggleState_2 == 0) {
        digitalWrite(RelayPin2, HIGH); // turn on relay 2
        toggleState_2 = 1;
        Serial.println("Device2 ON");
      } else {
        digitalWrite(RelayPin2, LOW); // turn off relay 2
        toggleState_2 = 0;
        Serial.println("Device2 OFF");
      }
      delay(100);
      break;
    case 3:
      if (toggleState_3 == 0) {
        digitalWrite(RelayPin3, HIGH); // turn on relay 3
        toggleState_3 = 1;
        Serial.println("Device3 ON");
      } else {
        digitalWrite(RelayPin3, LOW); // turn off relay 3
        toggleState_3 = 0;
        Serial.println("Device3 OFF");
      }
      delay(100);
      break;
    case 4:
      if (toggleState_4 == 0) {
        digitalWrite(RelayPin4, HIGH); // turn on relay 4
        toggleState_4 = 1;
        Serial.println("Device4 ON");
      } else {
        digitalWrite(RelayPin4, LOW); // turn off relay 4
        toggleState_4 = 0;
        Serial.println("Device4 OFF");
      }
      delay(100);
      break;
    case 5:
      if (toggleState_5 == 0) {
        digitalWrite(RelayPin5, HIGH); // turn on relay 5
        toggleState_5 = 1;
        Serial.println("Device5 ON");
      } else {
        digitalWrite(RelayPin5, LOW); // turn off relay 5
        toggleState_5 = 0;
        Serial.println("Device5 OFF");
      }
      delay(100);
      break;
    default:
      break;
  }
}

void manual_control() {
  //Manual Switch Control
  if (digitalRead(SwitchPin1) == LOW) {
    delay(200);
    relayOnOff(1);
  } else if (digitalRead(SwitchPin2) == LOW) {
    delay(200);
    relayOnOff(2);
  } else if (digitalRead(SwitchPin3) == LOW) {
    delay(200);
    relayOnOff(3);
  } else if (digitalRead(SwitchPin4) == LOW) {
    delay(200);
    relayOnOff(4);
  }
}

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  pinMode(RelayPin5, OUTPUT); // Initialize the new output pin

  pinMode(wifiLed, OUTPUT);

  pinMode(SwitchPin1, INPUT_PULLUP);
  pinMode(SwitchPin2, INPUT_PULLUP);
  pinMode(SwitchPin3, INPUT_PULLUP);
  pinMode(SwitchPin4, INPUT_PULLUP);

  //During Starting all Relays should TURN OFF
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(RelayPin3, HIGH);
  digitalWrite(RelayPin4, HIGH);
  digitalWrite(RelayPin5, HIGH); // Turn off the new output pin

  digitalWrite(wifiLed, HIGH); //Turn OFF WiFi LED
}

void loop() {
  ArduinoCloud.update();

  manual_control(); //Control relays manually

  if (WiFi.status() != WL_CONNECTED) {
    digitalWrite(wifiLed, HIGH); //Turn OFF WiFi LED
  } else {
    digitalWrite(wifiLed, LOW); //Turn ON WiFi LED
  }

}

void onRoomLightChange() {
  if (room_Light == 1) {
    digitalWrite(RelayPin1, HIGH);
    Serial.println("RoomLight ON");
    toggleState_1 = 1;
  } else {
    digitalWrite(RelayPin1, LOW);
    Serial.println("RoomLight OFF");
    toggleState_1 = 0;
  }
}

void onTvChange() {
  if (tv == 1) {
    digitalWrite(RelayPin2, HIGH);
    Serial.println("Tv ON");
    toggleState_2 = 1;
  } else {
    digitalWrite(RelayPin2, LOW);
    Serial.println("Tv OFF");
    toggleState_2 = 0;
  }
}

void onAirConditionChange() {
  if (air_Condition == 1) {
    digitalWrite(RelayPin3, HIGH);
    Serial.println("air_Condition ON");
    toggleState_3 = 1;
  } else {
    digitalWrite(RelayPin3, LOW);
    Serial.println("air_Condition OFF");
    toggleState_3 = 0;
  }
}

void onOutDoorLightChange() {
  if (outDoor_Light == 1) {
    digitalWrite(RelayPin4, HIGH);
    Serial.println("outDoor_Light ON");
    toggleState_4 = 1;
  } else {
    digitalWrite(RelayPin4, LOW);
    Serial.println("outDoor_Light OFF");
    toggleState_4 = 0;
  }
}

void onFanChange() {
  if (fan == 1) {
    digitalWrite(RelayPin5, HIGH); // turn on fan (assuming RelayPin5 is connected to the fan)
    Serial.println("Fan ON");
    toggleState_5 = 1;
  } else {
    digitalWrite(RelayPin5, LOW); // turn off fan
    Serial.println("Fan OFF");
    toggleState_5 = 0;
  }
}

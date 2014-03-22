#include <RFduinoGZLL.h>

device_t role = DEVICE0;

int redLed = 2;
int greenLed = 3;
int blueLed = 4;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  
  RFduinoGZLL.begin(role);
}

void loop() {
  RFduinoGZLL.sendToHost(NULL, 0);
}

void  RFduinoGZLL_onConnect() {
  digitalWrite(redLed, HIGH); 
  digitalWrite(greenLed, HIGH);
  digitalWrite(blueLed, HIGH);
}

void RFduinoGZLL_onReceive(device_t device, int rssi, char *data, int len) {
  char content = 'e';
  content = data[0];
  if (content != 0) {     
    if (content == 'r') {
      digitalWrite(redLed, HIGH); 
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
    } else if (content == 'g') {
      digitalWrite(redLed, LOW); 
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, LOW);
    } else if (content == 'b') {
      digitalWrite(redLed, LOW); 
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, HIGH);
    }
  }
}

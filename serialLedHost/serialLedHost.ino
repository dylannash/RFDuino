#include <RFduinoGZLL.h>

device_t role = HOST;
device_t other = DEVICE0;

char charSend = 'g';
String isConnected = "not";

void setup() {
  Serial.begin(9600);
  
  RFduinoGZLL.begin(role);
}

void loop() {
  
  String content = "";   
  char character;    

  while(Serial.available()) {       
    character = Serial.read();       
    content.concat(character);       
    delay(10);   
  }    
  if (content != "") {     
    Serial.println(content);
    if (content == "red") {
      charSend = 'r';
    } else if (content == "green") {
      charSend = 'g';
    } else if (content == "blue") {
      charSend = 'b';
    }
    RFduinoGZLL.sendToDevice(other, charSend);
  }
}

int redLed = 2;
int greenLed = 3;
int blueLed = 4;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  
  Serial.begin(9600);
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
      digitalWrite(redLed, HIGH); 
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
    } else if (content == "green") {
      digitalWrite(redLed, LOW); 
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, LOW);
    } else if (content == "blue") {
      digitalWrite(redLed, LOW); 
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, HIGH);
    }
  }
}

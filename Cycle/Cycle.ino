int red_led = 2;
int green_led = 3;
int blue_led = 4;
int buttonUp = 6;
int buttonDown = 5;

int buttonStateDown = 0;
int lastButtonStateDown = 0;
int pressCountDown = 0;
int lastPressCountDown = 0;

int buttonStateUp = 0;
int lastButtonStateUp = 0;
int lastPressCountUp = 0;
int pressCountUp = 0;

int lastLed = 1;

//RED = 0
//GREEN = 1
//BLUE = 2

void setup() {
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
  
  Serial.begin(1200);
}


void loop() {
  
  buttonStateDown = digitalRead(buttonDown);
  
  if (buttonStateDown != lastButtonStateDown) {
     if (buttonStateDown = 1) {
       pressCountDown++;
     }
     delay(50);
  }
  
  buttonStateUp = digitalRead(buttonUp);
  
  if (buttonStateUp != lastButtonStateUp) {
     if (buttonStateUp = 1) {
       pressCountUp++;
     }
     delay(50);
  }
  
  if (lastPressCountUp < pressCountUp && lastPressCountDown >= lastPressCountDown) {
     Serial.println("Up");
     if (lastLed == 1) {
       digitalWrite(red_led, LOW);
       digitalWrite(green_led, HIGH);
       digitalWrite(blue_led, LOW);
       lastLed = 2;
     } else if (lastLed == 2) {
       digitalWrite(red_led, LOW);
       digitalWrite(green_led, LOW);
       digitalWrite(blue_led, HIGH);
       lastLed = 3;
     } else if (lastLed == 3) {
       digitalWrite(red_led, HIGH);
       digitalWrite(green_led, LOW);
       digitalWrite(blue_led, LOW);
       lastLed = 1;
     }
  }
  if (lastPressCountDown < pressCountDown && lastPressCountUp >= lastPressCountUp) {
    Serial.println("Down");
    if (lastLed == 1) {
       digitalWrite(red_led, LOW);
       digitalWrite(green_led, LOW);
       digitalWrite(blue_led, HIGH);
       lastLed = 3;
     } else if (lastLed == 2) {
       digitalWrite(red_led, HIGH);
       digitalWrite(green_led, LOW);
       digitalWrite(blue_led, LOW);
       lastLed = 1;
     } else if (lastLed == 3) {
       digitalWrite(red_led, LOW);
       digitalWrite(green_led, HIGH);
       digitalWrite(blue_led, LOW);
       lastLed = 2;
     }  
   }
  Serial.println(lastLed);
  lastPressCountUp = pressCountUp;
  lastPressCountDown = pressCountDown;
  delay(100);
}


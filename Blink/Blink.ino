int red_button_up = 6;
int red_button_down = 5;
int red_led = 2;
int hl_red_up = 0;
int hl_red_down = 0;
int i_red = 0;


void setup() {
  pinMode(red_led, OUTPUT);
  pinMode(red_button_up, INPUT);
  pinMode(red_button_down, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  hl_red_up = digitalRead(red_button_up);
  hl_red_down = digitalRead(red_button_down);
  
  if (hl_red_up == 1) {
    if (i_red > 240) {
      i_red = 250;
    } else {
      i_red = i_red + 10;
    }
  }
  if (hl_red_down == 1) {
    if (i_red < 10) {
      i_red = 0; 
    } else {
      i_red = i_red - 10;
    }
  }
  Serial.println(i_red);
  analogWrite(red_led, i_red);
  delay(250);
}

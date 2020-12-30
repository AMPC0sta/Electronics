// By Antonio Costa - 2020/12/30
// Testing Digital inputs PINs
// To change the state, it's necessary to fed pin D0 or either with HIGH or LOW current. By Shunting Vin or GND.

const int LED = LED_BUILTIN;

const int PIN_D0 = 0;

int state = HIGH;
int last_state = HIGH;
int led_state = LOW;

// Source code to tests digital pins
void setup() {

    // Config
    pinMode(PIN_D0,INPUT_PULLUP);   // This will be one of the reading line
    pinMode(LED,OUTPUT);

    digitalWrite(LED,led_state);    // On board LED starts OFF
}

void loop() {
 
  state = digitalRead(PIN_D0);
  
  if(state != last_state) // if PIN state is different form last state, change LED status OFF->ON or ON->OFF
    if(led_state == LOW)
        led_state = HIGH;
     else
        led_state = LOW;
     
  digitalWrite(LED,led_state);
  last_state = state;
}

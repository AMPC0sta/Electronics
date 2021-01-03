#include <Keyboard.h>



#define NUM_ROWS 8
#define NUM_COLS 5

byte colPins[NUM_COLS] = {0, 1, 2, 3, 4};
byte rowPins[NUM_ROWS] = {5,6, 7, 8, 9, 10, 11, 12};

int debounceCount[NUM_ROWS][NUM_COLS];

void setup() {
  // put your setup code here, to run once:

}


bool scan_key(byte *d0,int d0_len,byte *d1,int d1_len,bool rotated)
{
  bool key_pressed = false;

  for(int i=0; i < 5; i++) {
    for (byte y = 0 ; y < d0_len ; y++) {
      pinMode(d0[y], OUTPUT);
        digitalWrite(d0[y], HIGH);
        
        for (byte x = 0 ; x < d1_len ; x++) { 
          pinMode(d1[x], INPUT_PULLUP);

          if (digitalRead(d1[x]) == LOW) {
            debounceCount[rotated ? x : y][rotated ? y : x]++;
            Keyboard.print("X ");
            Keyboard.print(x);
            Keyboard.print("Y ");
            Keyboard.print(y);
            Keyboard.print("I ");
            Keyboard.println(i);
            key_pressed = true;
          }
      } // for row
      digitalWrite(d0[y], LOW);
    } // for col
  }

  return key_pressed;
}

void loop() {
  // put your main code here, to run repeatedly:

  bool key_pressed = false;

  key_pressed = scan_key(colPins,NUM_COLS,rowPins,NUM_ROWS,false);
  
  if(key_pressed)
    {
      Keyboard.println("Key pressed!");
      delay(1000);
    }

  //delay(5000);
}

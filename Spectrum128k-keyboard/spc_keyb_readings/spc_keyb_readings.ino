#include <Keyboard.h>

// (c) Antonio Costa (AMC0sta) - 2021/01/03
// Program to read keyboard signais from Spectrum 128k+2 Keyboard Matrix
// This the first program around it. The ideia is to MAP keys using these read signals
// 128k Spectrum keyboard is a matrix of 5x8. This program flood all the rows, and get respective signals in rows (Next step is: check if there are a unique 5 bytes combinatios per key)
// PS: Digital Inputs are pulled GND.


#define NUM_ROWS 5
#define NUM_COLUMNS 8
#define BYTE_LEN 8

// Keyboard 5 wires flat cable 
byte row_pins[NUM_ROWS] = {0,1,2,3,4};

// Keyboard 8 wires flat cable 
byte column_pins[NUM_COLUMNS] = {5,6,7,8,9,10,11,12};

// State of one key
byte one_read[NUM_ROWS] = { 0,0,0,0,0 };

// State of last key
byte last_read[NUM_ROWS] = { 0,0,0,0,0 };


// On Teensy 3.2 On board built LED
const int LED = 13;

void setup() {
  // put your setup code here, to run once:

 // prepare led to ligh up
 pinMode(LED,OUTPUT);
}


// Compare two bytes arrays (in this program, 2 keys)
bool are_equals_arrays(byte a[],byte b[],int len)
{
  bool result = true;

  for(int ptr = 0; ptr < len; ptr++)
  {
    if(a[ptr]!=b[ptr])
    {
      result = false;
      break;
    }
  }

  return result;
}

// Function that reads one key ... this key is the global var: one_read
bool read_key()
{ int acc = 0;                   // Bitwise mask
  bool key_pressed = false;      // value to signal out if a key is pressed
  
  for(int r=0; r < NUM_ROWS;r++)
  {
    pinMode(row_pins[r],OUTPUT);      // Change mode to output: D0..D4
    digitalWrite(row_pins[r],HIGH);   // Flood it with HIGH (one line each time)

    for(int c=0; c < NUM_COLUMNS;c++)
    {
      
      pinMode(column_pins[c],INPUT_PULLUP);   // Mode read PULLUP
      
      if(digitalRead(column_pins[c])==LOW)    // Because keyboard mount was pulled to GND, get the results this way
        acc = acc + pow(2,c);                 // Bitwising a byte
    }

    digitalWrite(row_pins[r],LOW);          // flooed line is now dry
    one_read[r] = acc;                      // Save partial state
    acc = 0;
  }

  if(!are_equals_arrays(one_read,last_read,NUM_ROWS))   // If this is a different key
   key_pressed = true;

 return key_pressed;    // will be true if something happened
}


void loop() {
  // put your main code here, to run repeatedly:

 if(read_key())
  {
    for(int ptr=0;ptr<5;ptr++)  // if a new key was pressed show all the 5 values
    {
     Keyboard.print(one_read[ptr]);
     Keyboard.print(" ");
    }
    Keyboard.println(" ");
    digitalWrite(LED,HIGH);     // Also, blink on board LED for one second

    delay(1000);
    digitalWrite(LED,LOW);
  }
}

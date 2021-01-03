#include <Keyboard.h>

// 5 pins flat cable connector
const int KL_1 = 1;
const int KL_2 = 2;
const int KL_3 = 3;
const int KL_4 = 4;
const int KL_5 = 5;

// 8 pins flat cable connector
const int KB_1 = 6;
const int KB_2 = 7;
const int KB_3 = 8;
const int KB_4 = 9;
const int KB_5 = 10;
const int KB_6 = 11;
const int KB_7 = 12;
const int KB_8 = 13;

const int ROWS = 5;
const int COLUMNS = 8;

// flat cables values containers (masked to HIGH and LOW) (STATERS)
int row = 11111;
int column = 11111111;
int last_row = row;
int last_column = column;


// rows
int r1 = LOW;
int r2 = LOW;
int r3 = LOW;
int r4 = LOW;
int r5 = LOW;

int c1 = LOW;
int c2 = LOW;
int c3 = LOW;
int c4 = LOW;
int c5 = LOW;
int c6 = LOW;
int c7 = LOW;
int c8 = LOW;



void flood_matrix(int side) {

 if(side==ROWS)
 {
  Keyboard.println("INSIDE ROWS SIDE");
  pinMode(KL_1,OUTPUT);
  pinMode(KL_2,OUTPUT);
  pinMode(KL_3,OUTPUT);
  pinMode(KL_4,OUTPUT);
  pinMode(KL_5,OUTPUT);

  digitalWrite(KL_1,HIGH);
  digitalWrite(KL_2,HIGH);
  digitalWrite(KL_3,HIGH);
  digitalWrite(KL_4,HIGH);
  digitalWrite(KL_5,HIGH);
 }

 if(side==COLUMNS)
 {
  Keyboard.println("INSIDE COLUMNS SIDE");
  pinMode(KB_1,OUTPUT);
  pinMode(KB_2,OUTPUT);
  pinMode(KB_3,OUTPUT);
  pinMode(KB_4,OUTPUT);
  pinMode(KB_5,OUTPUT);
  pinMode(KB_6,OUTPUT);
  pinMode(KB_7,OUTPUT);
  pinMode(KB_8,OUTPUT);

  digitalWrite(KB_1,HIGH);
  digitalWrite(KB_2,HIGH);
  digitalWrite(KB_3,HIGH);
  digitalWrite(KB_4,HIGH);
  digitalWrite(KB_5,HIGH);
  digitalWrite(KB_6,HIGH);
  digitalWrite(KB_7,HIGH);
  digitalWrite(KB_8,HIGH);
 }
 
}


void setup() {
  // Configuring digital entries

  // Keyboard rows
  pinMode(KL_1,INPUT_PULLUP);
  pinMode(KL_2,INPUT_PULLUP);
  pinMode(KL_3,INPUT_PULLUP);
  pinMode(KL_4,INPUT_PULLUP);
  pinMode(KL_5,INPUT_PULLUP);

  // Keyboard columns
  pinMode(KB_1,INPUT_PULLUP);
  pinMode(KB_2,INPUT_PULLUP);
  pinMode(KB_3,INPUT_PULLUP);
  pinMode(KB_4,INPUT_PULLUP);
  pinMode(KB_5,INPUT_PULLUP);
  pinMode(KB_6,INPUT_PULLUP);
  pinMode(KB_7,INPUT_PULLUP);
  pinMode(KB_8,INPUT_PULLUP);
}

void loop() {


  flood_matrix(ROWS);
  // reading columns
  c1 = digitalRead(KB_1);
  c2 = digitalRead(KB_2);
  c3 = digitalRead(KB_3);
  c4 = digitalRead(KB_4);
  c5 = digitalRead(KB_5);
  c6 = digitalRead(KB_6);
  c7 = digitalRead(KB_7);
  c8 = digitalRead(KB_8);

  
  // Masking columns
  column = c1 + 10*c2 + 100*c3 + 1000*c4 + 10000*c5 + 100000*c6 + 1000000*c7 + 10000000*c8;
  Keyboard.print("Read column ");
  Keyboard.println(column);

  if(last_column != column)
    {
        //Keyboard.print("ROW ");
        //Keyboard.print(row);
        
        flood_matrix(COLUMNS);

        // reading rows
        r1 = digitalRead(KL_1);
        r2 = digitalRead(KL_2);
        r3 = digitalRead(KL_3);
        r4 = digitalRead(KL_4);
        r5 = digitalRead(KL_5);

        row = r1 + 10*r2 + 100*r3 + 1000*r4 + 10000*r5;


        Keyboard.print(" ROW ");
        Keyboard.println(row);

        delay(1000);
    }

  setup();
  last_row = row;
  last_column = column;
  delay(3000);

}
    

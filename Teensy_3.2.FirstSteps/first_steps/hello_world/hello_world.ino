#include <Keyboard.h>

int count = 0;
void setup() {
  // No Setup is needeg
}



void loop() {
  // put your main code here, to run repeatedly:
  

  if( count > 5)
    exit(0);
    
  Keyboard.print("Hello World from inside the board! "); 
  Keyboard.println(count);
  count = count + 1;
  delay(5000);
} 

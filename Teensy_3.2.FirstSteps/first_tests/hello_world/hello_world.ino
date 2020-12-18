

int count = 0;
void setup() {
  // No Setup is needed
}



void loop() {
  // put your main code here, to run repeatedly:
  Keyboard.print("Hello World from inside the board! "); 
  Keyboard.println(count);
  count = count + 1;
  delay(5000);
}

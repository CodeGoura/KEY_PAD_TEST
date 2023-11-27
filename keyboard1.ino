#include <Keypad.h>
const int ROWS=4;
const int COLS=4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};
Keypad customkeypad = Keypad(makeKeymap(keys),rowPins,colPins, ROWS, COLS);
void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  char customkey = customkeypad.getKey();
  if (customkey){
    Serial.println(customkey);
    if ((customkey == 'A') || (customkey == 'B') || (customkey == 'C') || (customkey == 'D')){
     digitalWrite(10,HIGH);
  	 delay(1000); // Wait for 1000 millisecond(s)
  	 digitalWrite(10, LOW);
     delay(1000); }
    else{
      digitalWrite(11,HIGH);
  	 delay(1000); // Wait for 1000 millisecond(s)
  	 digitalWrite(11, LOW);
     delay(1000); }
  }
 }
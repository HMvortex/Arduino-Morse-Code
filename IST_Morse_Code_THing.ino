/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
char stringToMorseCode[32] = "Hello";
#include <LiquidCrystal.h>


String input;

const int redPin = 8;
const int greenPin = 9;
const int bluePin = 10;

int betweenLetters = 300;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  Serial.begin(9600);
  lcd.begin(16, 2);
    
}
void loop() {
  lcd.print(stringToMorseCode);
  for (int i = 0; i < sizeof(stringToMorseCode) - 1; i++){
    char tmpChar = stringToMorseCode[i];
    tmpChar = toLowerCase(tmpChar);
    GetChar(tmpChar);
  }
  if(Serial.available()){
        input = Serial.readString();
        Serial.print("You typed: " );
        int inputLength = input.length() + 1;
        Serial.println(input);
        Serial.println(inputLength);
        for( int i = 0; i < sizeof(stringToMorseCode);  ++i ){
          stringToMorseCode[i] = (char)0;
        }
        input.toCharArray(stringToMorseCode, inputLength);
  }
  Serial.println("Restart");
  lcd.clear();
  lightOff(3000);  
}
void dot(){
  analogWrite(greenPin, 255);
  tone(13,1000);
  delay(100);
}
void dash(){
  analogWrite(bluePin, 255);
  tone(13,1000);
  delay(300);
}
void lightOff(int timeOff) {
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  noTone(13);
  delay(timeOff);
}  
void GetChar(char tmpChar){
  switch (tmpChar){
    case 'a':
      dot();
      lightOff(100);
      dash();
      lightOff(betweenLetters);
      Serial.println("a");
      break;
    case 'b':
      dash();
      lightOff(100);
      dot();
      lightOff(100);
      dot();
      lightOff(100);
      dot();
      lightOff(betweenLetters);
      Serial.println("b");
      break;
    case 'c':
      dash();
      lightOff(100);
      dot();
      lightOff(100);
      dash();
      lightOff(100);
      dot();
      lightOff(betweenLetters);
      Serial.println("c");
      break;
    case 'd':
      dash();
      lightOff(100);
      dot();
      lightOff(100);
      dot();
      lightOff(betweenLetters);
      Serial.println("d");
      break;
    case 'e':
      dot();
      lightOff(betweenLetters);
      Serial.println("e");
      break;
    case 'f':
      dot();
      lightOff(100);
      dot();
      lightOff(100);
      dash();
      lightOff(100);
      dot();
      lightOff(betweenLetters);
      Serial.println("f");
      break;
    case 'g':
      dash();
      lightOff(100);
      dash();
      lightOff(100);
      dot();
      lightOff(betweenLetters);
      Serial.println("g");
      break;
    case 'h':
      dot();
      lightOff(100);
      dot();
      lightOff(100);
      dot();
      lightOff(100);
      dot();
      lightOff(betweenLetters);
      Serial.println("h");
      break;
    case 'i':
      dot();
      lightOff(100);
      dot();
      lightOff(betweenLetters);
      Serial.println("i");
      break;
    case 'j':
      dot();
      lightOff(100);
      dash();
      lightOff(100);
      dash();
      lightOff(100);
      dash();
      lightOff(betweenLetters);
      Serial.println("j");
      break;
    case 'k':
      dash();
      lightOff(100);
      dot();
      lightOff(100);
      dash();
      lightOff(betweenLetters);
      Serial.println("k");
      break;
    case 'l':
      dot();
      lightOff(100);
      dash();
      lightOff(100);
      dot();
      lightOff(100);
      dot();
      lightOff(betweenLetters);
      Serial.println("l");
      break;
    case 'm':
      dash();
      lightOff(100);
      dash();
      lightOff(betweenLetters);
      Serial.println("m");
      break;
    case 'n':
      dash();
      lightOff(100);
      dot();
      lightOff(betweenLetters);
      Serial.println("n");
      break;
    case 'o':
      dash();
      lightOff(100);
      dash();
      lightOff(100);
      dash();
      lightOff(betweenLetters);
      Serial.println("o");
      break;
    case 'p':
      dot();
      lightOff(100);
      dash();
      lightOff(100);
      dash();
      lightOff(100);
      dot();
      lightOff(betweenLetters);
      Serial.println("p");
      break;
    case 'q':
      dash();
      lightOff(100);
      dash();
      lightOff(100);
      dot();
      lightOff(100);
      dash();
      lightOff(betweenLetters);
      Serial.println("q");
      break;
    case 'r':
      dot();
      lightOff(100);
      dash();
      lightOff(100);
      dot();
      lightOff(betweenLetters);
      Serial.println("r");
      break;
    case 's':
      dot();
      lightOff(100);
      dot();
      lightOff(100);
      dot();
      lightOff(betweenLetters);
      Serial.println("s");
      break;
    case 't':
      dash();
      lightOff(betweenLetters);
      Serial.println("t");
      break;
    case 'u':
      dot();
      lightOff(100);
      dot();
      lightOff(100);
      dash();
      lightOff(betweenLetters);
      Serial.println("u");
      break;
    case 'v':
      dot();
      lightOff(100);
      dot();
      lightOff(100);
      dot();
      lightOff(100);
      dash();
      lightOff(betweenLetters);
      Serial.println("v");
      break;
    case 'w':
      dot();
      lightOff(100);
      dash();
      lightOff(100);
      dash();
      lightOff(betweenLetters);
      Serial.println("w");
      break;
    case 'x':
      dash();
      lightOff(100);
      dot();
      lightOff(100);
      dot();
      lightOff(100);
      dash();
      lightOff(betweenLetters);
      Serial.println("x");
      break;
    case 'y':
      dash();
      lightOff(100);
      dot();
      lightOff(100);
      dash();
      lightOff(100);
      dash();
      lightOff(betweenLetters);
      Serial.println("y");
      break;
    case 'z':
      dash();
      lightOff(100);
      dash();
      lightOff(100);
      dot();
      lightOff(100);
      dot();
      lightOff(betweenLetters);
      Serial.println("z");
      break;
    case ' ':
      Serial.println("SPACE");
      lightOff(700);
            
      
  }
}




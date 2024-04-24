#include <SR04.h>

#include "SR04.h"
#include "IRremote.h"

#define RED 3
#define GREEN 5
#define BLUE 6

#define TRIG_PIN 12
#define ECHO_PIN 11
#define POTENTIOMETER_PIN A6

#define Button_0 0xFF6897
#define Button_1 0xFF30CF
#define Button_2 0xFF18E7
#define Button_3 0xFF7A85
#define Button_4 0xFF10EF
#define Button_5 0xFF38C7
#define Button_6 0xFF5AA5
#define Button_7 0xFF42BD
#define Button_8 0xFF4AB5
#define Button_9 0xFF52AD

#define delayTime 10 // Timpul de tranziție între culori

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN); // Creează o instanță a senzorului ultrasonic

int receiver = 10; // Signal Pin of IR receiver to Arduino Digital Pin 10

IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void setup() {

  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

int lastButtonPressed = -1; // Variabilă pentru a ține evidența ultimului buton apăsat
unsigned long lastButtonTime = 0; // Variabilă pentru a ține timpul la care s-a apăsat ultimul buton
unsigned long colorDuration = 15000; // Durata de menținere a culorii în milisecunde (aici 5000 ms = 5 secunde)


void translateIR() // takes action based on IR code received
{ 
  int red = 255;
  int green = 255;
  int blue = 255;

  Serial.println(results.value, HEX);
  unsigned long currentTime = millis();
  unsigned long transitionStartTime = currentTime;
  
  switch(results.value)
  {
    case Button_0 :lastButtonPressed = Button_0;
                   lastButtonTime = currentTime;
                   red = 255;
                   green = 0;
                   blue = 0;
                   analogWrite(RED, red);
                   analogWrite(GREEN, green);
                   analogWrite(BLUE, blue); 
                   break;
    case Button_1 :lastButtonPressed = Button_1;
                   lastButtonTime = currentTime;
                   red = 0;
                   green = 255;
                   blue = 0;
                   analogWrite(RED, red);
                   analogWrite(GREEN, green);
                   analogWrite(BLUE, blue);
                   break;
    case Button_2 :lastButtonPressed = Button_2;
                   lastButtonTime = currentTime;
                   red = 0;
                   green = 0;
                   blue = 255;
                   analogWrite(RED, red);
                   analogWrite(GREEN, green);
                   analogWrite(BLUE, blue); 
                   break;
    case Button_3 :lastButtonPressed = Button_3;
                   lastButtonTime = currentTime;
                   red = 225;
                   green = 0;
                   blue = 175;
                   analogWrite(RED, red);
                   //analogWrite(GREEN, green);
                   analogWrite(BLUE, blue); 
                   break;
    case Button_4 :lastButtonPressed = Button_4;
                   lastButtonTime = currentTime;
                   red = 232;
                   green = 245;
                   blue = 0;
                   analogWrite(RED, red);
                   analogWrite(GREEN, green);
                   //analogWrite(BLUE, blue);
                   break;
    case Button_5 :lastButtonPressed = Button_5;
                   lastButtonTime = currentTime;
                   red = 0;
                   green = 195;
                   blue = 235;
                   analogWrite(RED, red);
                   analogWrite(GREEN, green);
                   analogWrite(BLUE, blue); 
                   break;
    case Button_6 :lastButtonPressed = Button_6;
                   lastButtonTime = currentTime;
                   red = 125;
                   green = 0;
                   blue = 255;
                   analogWrite(RED, red);
                   analogWrite(GREEN, green);
                   analogWrite(BLUE, blue); 
                   break;
    case Button_7 :lastButtonPressed = Button_7;
                   lastButtonTime = currentTime;
                   red = 125;
                   green = 45;
                   blue = 25;
                   analogWrite(RED, red);
                   analogWrite(GREEN, green);
                   analogWrite(BLUE, blue); 
                   break;
    case Button_8 :lastButtonPressed = Button_8;
                   lastButtonTime = currentTime;
                   red = 255;
                   green = 165;
                   blue = 0; 
                   analogWrite(RED, red);
                   analogWrite(GREEN, green);
                   //analogWrite(BLUE, blue); 
                   break;
    case Button_9 :lastButtonPressed = Button_9;
                   lastButtonTime = currentTime;
                   red = 245;
                   green = 245;
                   blue = 250;
                   analogWrite(RED, red);
                   analogWrite(GREEN, green);
                   analogWrite(BLUE, blue); 
                   break;
    default:
      break;
    
  }
  while (currentTime - transitionStartTime <= colorDuration) {
    analogWrite(RED, red);
    analogWrite(GREEN, green);
    analogWrite(BLUE, blue);
    currentTime = millis();
  }
  irrecv.resume();
}

// define variables
int redValue;
int greenValue;
int blueValue;
int potValue;

void loop() {
  long distance = sr04.Distance(); // Măsoară distanța cu senzorul ultrasonic

  unsigned long currentTime = millis();

  potValue = analogRead(POTENTIOMETER_PIN);

  if (distance < 40) {
   redValue = 255;
   greenValue = 0;
   blueValue = 0;

  for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
  {
   redValue -= 1;
   greenValue += 1;
   analogWrite(RED, redValue);
   analogWrite(GREEN, greenValue);
   delay(delayTime);
  }

  redValue = 0;
  greenValue = 255;
  blueValue = 0;

  for(int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
  {
    greenValue -= 1;
    blueValue += 1;
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 0;
  blueValue = 255;

  for(int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
  {
    blueValue -= 1;
    redValue += 1;
    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    delay(delayTime);
  }
 }
 else {

    analogWrite(RED, 255);
    analogWrite(GREEN, 255);
    analogWrite(BLUE, 255);

    if (irrecv.decode(&results)) {
      translateIR();
      irrecv.resume();
      
    } else {
      if (lastButtonPressed != -1 && (currentTime - lastButtonTime >= colorDuration)) {
        // LED-urile vor rămâne albe
        analogWrite(RED, 255);
        analogWrite(BLUE, 255);
        analogWrite(GREEN, 255);
        lastButtonPressed = -1;
      }
    }
 }
  delay(350); // Pauză pentru a evita măsurători prea frecvente cu senzorul ultrasonic
}

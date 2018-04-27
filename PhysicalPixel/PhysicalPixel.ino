/*
  Physical Pixel

 An example of using the Arduino board to receive data from the
 computer.  In this case, the Arduino boards turns on an LED when
 it receives the character 'H', and turns off the LED when it
 receives the character 'L'.

 The data can be sent from the Arduino serial monitor, or another
 program like Processing (see code below), Flash (via a serial-net
 proxy), PD, or Max/MSP.

 The circuit:
 * LED connected from digital pin 13 to ground

 created 2006
 by David A. Mellis
 modified 30 Aug 2011
 by Tom Igoe and Scott Fitzgerald

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/PhysicalPixel
 */

//const int ledPin = 13; // the pin that the LED is attached to

int ledPins[] = {3, 5, 6, 9};

int incomingByte;      // a variable to read incoming serial data into

//int go[] = {0, 100, 50, 255};

String numbers;
//int go[4];
int activePin = 0;

void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < sizeof(ledPins)/sizeof(ledPins[0]); i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
//  go = int(split(numbers, ' '));
//  for(int i = 0; i < sizeof(go)/sizeof(go[0]); i++) {
//      go[i] = numbers.substring(i*3, (i+1)*3).toInt();
////      Serial.println(go[i]);
//  }
  if (Serial.available() > 0) {
    
    incomingByte = Serial.read();
    Serial.println(incomingByte);
    analogWrite(ledPins[activePin], map(incomingByte, 0, 10, 0, 255));
    activePin = (activePin+1)%4;


    
//    numbers = String(incomingByte);

//    for(int i = 0; i < sizeof(ledPins)/sizeof(ledPins[0]); i++) {
////      go[i] = numbers.substring(i*3, (i+1)*3).toInt();
////      Serial.print(i);
////      Serial.println(go[i]);
////      analogWrite(ledPins[i], go[i]);
//
//      analogWrite(ledPins[i], numbers.substring(i*3, (i+1)*3).toInt());
//    }

  }
}

//      go = Serial.read();
//
//    Serial.println("hi");
//    Serial.println(incomingByte);

//    for(int i = 0; i < sizeof(ledPins)/sizeof(ledPins[0]); i++) {
//      if( i == incomingByte ) {
//        analogWrite(ledPins[i], 255);
//      } else {
//        analogWrite(ledPins[i], LOW);
//      }
//    }

//    for(int i = 0; i < sizeof(go)/sizeof(go[0]); i++) {
//        analogWrite(ledPins[i], go[i]);
//    }



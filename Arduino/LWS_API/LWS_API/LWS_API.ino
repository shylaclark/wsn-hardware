#include <XBee.h>
#include < AltSoftSerial.h>


// create XBee object
XBee xbee = XBee();

// create the AltSoftSerial object
// has fixed pin assignments:
// Arduino Uno: TX (9), RX (8), unusable PWN (10)
AltSoftSerial mySerial;

// Variable to store the value coming from the sensor
int LWS = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("AltSoftSerial Test Begin");
  mySerial.begin(9600);
  mySerial.println("Hello World");
}

void loop() {
  // Read from A0 and store in LWS
  LWS = analogRead(A0);

}

void printReading(int LWS) {
  mySerial.print("LWS currently: ");
  mySerial.println(LWS);
}

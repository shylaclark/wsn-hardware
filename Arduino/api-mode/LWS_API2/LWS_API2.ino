#include <XBee.h>

// Create an XBee object at the top of your sketch
XBee xbee = XBee();

// Variable to store the value coming from the sensor
uint8_t LWS = 0;

void setup() {
  // Start the serial port
  Serial.begin(9600);
  // Tell XBee to use Hardware Serial. It's also possible to use SoftwareSerial
  xbee.setSerial(Serial);
}

// Create an array for holding the data you want to send.
//uint8_t payload[] = { LWS };

// Specify the address of the remote XBee (this is the SH + SL)
XBeeAddress64 addr64 = XBeeAddress64(0x0013a200, 0x415b8b98);

// Create a TX Request
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));

void loop() {
  
  // Read from A0 and store in LWS
  LWS = analogRead(A0);

  uint8_t payload[] = { LWS };
  // Send your request
  xbee.send(zbTx);
  delay(2000);
}

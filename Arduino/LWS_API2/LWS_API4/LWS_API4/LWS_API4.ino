#include <XBee.h>

XBee xbee = XBee();

void setup() {
  Serial.begin(9600);
  // Use hardware serial
  xbee.setSerial(Serial);     
}

// Specify the address of the remote XBee (this is the SH + SL)
XBeeAddress64 addr64 = XBeeAddress64(0x0013a200, 0x415b8b98);

int data = analogRead(A0); 
uint8_t* payload = (uint8_t*) data;

  //uint8_t* payload = analogRead(A0);
  
  ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));


void loop() {
  // Send your request
  xbee.send(zbTx);
  delay(2000);
}

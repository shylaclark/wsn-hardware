#include <XBee.h>

// Sender sends a ZigBee Transmit Request API frame to the XBee module, 
// containing the destination address and the message.

XBee xbee = XBee();

void setup() {
  Serial.begin(9600);
  // Use hardware serial
  xbee.setSerial(Serial);     
}



//uint8_t* payload = analogRead(A0);



void sendPacket() {

  // Specify the address of the remote XBee (this is the SH + SL)
  // Special value 0x0000000000000000 can be used to address coordinator
  XBeeAddress64 addr64 = XBeeAddress64(0x00000000, 0x00000000);

  int data = analogRead(A0); 
  uint8_t* payload = (uint8_t*) data;
  
  // ZB Transmit Request API frame/packet containing dest. address + message
  ZBTxRequest txPacket = ZBTxRequest(addr64, payload, sizeof(payload));
  xbee.send(txPacket);

}

unsigned long last_tx_time = 0;

void loop() {
  // Send your request
  delay(2000);
  Serial.println("Sent");
}



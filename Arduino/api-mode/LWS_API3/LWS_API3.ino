#include <XBee.h>

XBee xbee = XBee();

// Variable to store the value coming from the sensor
uint8_t LWS = 0;

void setup() {
  Serial.begin(9600);
  // Use hardware serial
  xbee.setSerial(Serial);

    // Setup callbacks
  // xbee.onPacketError(printErrorCb, (uintptr_t)(Print*)&DebugSerial);
  // xbee.onResponse(printErrorCb, (uintptr_t)(Print*)&DebugSerial);

  // Send a first packet right away
  sendPacket();
}

void sendPacket() {

    // Prepare the Zigbee Transmit Request API packet
    ZBTxRequest txRequest;
    txRequest.setAddress64(0x0013a200415b8b98);

    // Allocate 9 payload bytes: 1 type byte plus two floats of 4 bytes each
    AllocBuffer<9> packet;

    // Packet type, leaf wetness sensor
    packet.append<uint8_t>(1);
    packet.append<float>(analogRead(A0));
    txRequest.setPayload(packet.head, packet.len());

    // And send it
    xbee.send(txRequest);
}

unsigned long last_tx_time = 0;

void loop() {
  // Check the serial port to see if there is a new packet available
  xbee.loop();

  // Send a packet every 10 seconds
  if (millis() - last_tx_time > 3000) {
    sendPacket();
    last_tx_time = millis();
  }
}

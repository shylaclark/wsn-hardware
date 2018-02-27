#include <AltSoftSerial.h>
#include <XBee.h> 
#include <Printers.h>

// Define two preprocessor macros which tell compiler:
// Wherever you see DebugSerial, read as Serial instead
// Wherever you see XBeeSerial, read as SoftSerial
// Henceforth, DebugSerial used whenever debug message must be printed
// XBeeSerial is used to talk to the XBee device
#define DebugSerial Serial
#define XBeeSerial SoftSerial

AltSoftSerial SoftSerial;
 
// Create global xbee obj to use all xbee-arduino functionality
XBeeWithCallbacks xbee;


void setup() {
  
  // Setup debug serial output 
  DebugSerial.begin( 115200); 
  DebugSerial.println( F(" Starting..."));
   
  // Setup XBee serial communication 
  XBeeSerial.begin( 9600); 
  xbee.begin( XBeeSerial); 
  delay( 1);

  // Let all responses be printed
  xbee.onResponse( printResponseCb, (uintptr_t)( Print*) &DebugSerial);
  
  // Create a "VR" command to retrieve firmware version 
  AtCommandRequest req(( uint8_t*)"VR");
  
  // Send an AT command API frame containing the VR command.
  xbee.send( req);

}


void loop() {
  
  // Check the serial port to see if there is a new packet available 
  xbee.loop();
}


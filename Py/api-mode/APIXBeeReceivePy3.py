# /usr/bin/python.3.5.3
# Check for new /dev/ttyUSB* before running
# XBee radios in API mode - not transparent mode
# Threaded synchronous mode 

from xbee import ZigBee
import serial

serial_port = serial.Serial('/dev/tty.usbserial-DN03FEEK', 9600)
xbee = ZigBee(serial_port)

while True:
    try:
        print ("waiting for frame...")
        
        # Blocks until a valid frame received from associated XBee device
        print (xbee.wait_read_frame())
        
    except KeyboardInterrupt:
        break

serial_port.close()

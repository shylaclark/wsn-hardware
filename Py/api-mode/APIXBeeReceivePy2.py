#! /usr/bin/python2.7.13
# XBee radios in API mode - not transparent mode
# Threaded synchronous mode

from xbee import ZigBee
import serial


serial_port = serial.Serial('/dev/ttyUSB0', 9600)
xbee = ZigBee(serial_port)

while True:
    try:
        print "waiting for frame..."
        # Blocks until valid frame received from associated XBee device
        print xbee.wait_read_frame()
        
    except KeyboardInterrupt:
        break

serial_port.close()

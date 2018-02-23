#! /usr/bin/python2.7.13
# Check for new /dev/ttyUSB* before running
# For XBees in transparent mode - not API mode

import serial

serial_port = serial.Serial('/dev/ttyUSB0', 9600)

while True:
    try:
        print "waiting for frame..."
        data = serial_port.readline()
        print data
        
    except KeyboardInterrupt:
        break

serial_port.close()

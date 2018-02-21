#! /usr/bin/python2.7.13


from xbee import XBee, ZigBee
import serial

serial_port = serial.Serial('/dev/ttyUSB1', 9600)
xbee = ZigBee(serial_port)

while True:
    try:
        print "waiting for frame..."
        data = serial_port.readline()
        print data
        
    except KeyboardInterrupt:
        break

serial_port.close()

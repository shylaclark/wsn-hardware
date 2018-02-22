# /usr/bin/python.3.5.3
# Check for new /dev/ttyUSB* before running


# From xbee import XBee, ZigBee
import serial

serial_port = serial.Serial('/dev/ttyUSB0', 9600)
# xbee = ZigBee(serial_port)

while True:
    try:
        print ("waiting for frame...")
        data = serial_port.readline()
        print (data)
        
    except KeyboardInterrupt:
        break

serial_port.close()

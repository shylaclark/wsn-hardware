# /usr/bin/python.3.5.3
# Check for new /dev/ttyUSB* before running
# XBee radios in transparent mode - not API mode

import serial

serial_port = serial.Serial('/dev/ttyUSB0', 9600)

while True:
    try:
        print ("Receiving transmissions in transparent mode...")
        data = serial_port.readline()
        print (data)
        
    except KeyboardInterrupt:
        break

serial_port.close()

# /usr/bin/python.3.5.3
# Check for new /dev/ttyUSB* before running
# XBee radios in API mode - not transparent mode
# Threaded synchronous mode 

import serial
import time
from xbee import ZigBee

serial_port = serial.Serial('/dev/ttyUSB0', 9600)

def print_data(data):
    """
    This method is called whenever data is received
    from the associated XBee device. Its first and
    only argument is the data contained within the
    frame.
    """
    print (data)

xbee = ZigBee(serial_port, callback=print_data)

while True:
    try:
        time.sleep(0.001)
    except KeyboardInterrupt:
        break

xbee.halt()
serial_port.close()
# /usr/bin/python.3.5.3
# Check for new /dev/ttyUSB* before running
# XBee radios in API mode - not transparent mode
# Threaded synchronous mode 


import serial
import time
from xbee import ZigBee

# Open serial port
serial_port = serial.Serial('/dev/ttyUSB0', 9600)

def message_received(data):
    """
    This method is called whenever data is received
    from the associated XBee device. Its first and
    only argument is the data contained within the
    frame.
    """
    print (data)

# Create API object, which spawns a new thread
xbee = ZigBee(serial_port, callback=message_received)

# Do other stuff in the main thread
while True:
    try:
        print ("Where is the message?")
        time.sleep(1)
    except KeyboardInterrupt:
        break

# Always call halt() before closing serial for proper thread shutdown
xbee.halt()
serial_port.close()
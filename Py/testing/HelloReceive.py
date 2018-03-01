# /usr/bin/python.3.5.3
# Check for new /dev/ttyUSB* before running
# XBee radios in API mode - not transparent mode
# Threaded asynchronous mode 

from xbee import ZigBee
import serial

# Open serial port on Pi
# serial_port = serial.Serial('/dev/ttyUSB0', 9600)

# Open serial port on Mac
serial_port = serial.Serial('/dev/tty.usbserial-DN03FEEK', 9600)

xbee = ZigBee(serial_port)


# Do other stuff in the main thread
while True:
    try:
        print (xbee.wait_read_frame())
    except KeyboardInterrupt:
        break

serial_port.close()
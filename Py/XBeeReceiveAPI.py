# /usr/bin/python.3.5.3
# Check for new /dev/ttyUSB* before running


from xbee import XBee, ZigBee
import serial

serial_port = serial.Serial('/dev/ttyUSB0', 9600)
xbee = XBee(serial_port)

while True:
    try:
        print ("waiting for frame...")
        print (xbee.wait_read_frame())
        # data = serial_port.read()
        # print (data)
        
    except KeyboardInterrupt:
        break

serial_port.close()

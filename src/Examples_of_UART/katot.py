import serial
import time

port = serial.Serial('/dev/cu.usbmodem101',115200,timeout=1)
time.sleep(3)

while port.is_open:
    port.write(b'#|1010|'+str(255).encode("ascii")+b'|'+str(0).encode("ascii")+b'|')
    time.sleep(5)
    port.write(b'#|110|'+str(0).encode("ascii")+b'|'+str(255).encode("ascii")+b'|')
    time.sleep(5)
    port.write(b'#|0000|'+str(0).encode("ascii")+b'|'+str(0).encode("ascii")+b'|')
    time.sleep(5)
    

import serial
import time

port = serial.Serial('/dev/cu.usbserial-10',115200,timeout=1)
time.sleep(3)

while port.is_open:
    port.write(b'#|10|10|'+str(125).encode("ascii")+b'|'+str(125).encode("ascii")+b'|')
    time.sleep(5)
    port.write(b'#|11|11|'+str(0).encode("ascii")+b'|'+str(0).encode("ascii")+b'|')
    time.sleep(5)
    port.write(b'#|01|01|'+str(125).encode("ascii")+b'|'+str(125).encode("ascii")+b'|')
    time.sleep(5)
    port.write(b'#|00|00|'+str(0).encode("ascii")+b'|'+str(0).encode("ascii")+b'|')
    time.sleep(5)
    port.write(b'#|10|01|'+str(125).encode("ascii")+b'|'+str(125).encode("ascii")+b'|')
    time.sleep(5)
    port.write(b'#|00|00|'+str(0).encode("ascii")+b'|'+str(0).encode("ascii")+b'|')
    time.sleep(5)
    port.write(b'#|01|10|'+str(125).encode("ascii")+b'|'+str(125).encode("ascii")+b'|')
    time.sleep(5)
    port.write(b'#|00|00|'+str(0).encode("ascii")+b'|'+str(0).encode("ascii")+b'|')
    time.sleep(5)
    

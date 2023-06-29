# https://www.xanthium.in/Cross-Platform-serial-communication-using-Python-and-PySerial


import serial
import time

SerialObj = serial.Serial('/dev/ttyACM0') # COMxx   format on Windows

SerialObj.baudrate = 9600  # set Baud rate to 9600
SerialObj.bytesize = 8     # Number of data bits = 8
SerialObj.parity   ='N'    # No parity
SerialObj.stopbits = 1     # Number of Stop bits = 1

time.sleep(3)   

code= input("How you doin'? Give me the secret code number, and I'll keep it a secret :) \n")

BytesWritten = SerialObj.write(code.encode())      # transmit 'A' (8bit) to micro/Arduino

print("Whoa! Look at that, you entered ", code)

SerialObj.close()          # Close the port




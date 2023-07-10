# https://www.xanthium.in/Cross-Platform-serial-communication-using-Python-and-PySerial

from flask import Flask, request, render_template
import serial
import time
import socket
import ssl

app = Flask(__name__)

teensy = serial.Serial('/dev/ttyACM1') # COMxx   format on Windows

teensy.baudrate = 9600  # set Baud rate to 9600
teensy.bytesize = 8     # Number of data bits = 8
teensy.parity   ='N'    # No parity
teensy.stopbits = 1     # Number of Stop bits = 1

time.sleep(3)   

#code= input("How you doin'? Give me the secret code number, and I'll keep it a secret :) \n")
#BytesWritten = SerialObj.write(code.encode())      # transmit 'A' (8bit) to micro/Arduino

@app.route('/')
def home():
    # Get the IP address of the laptop running the Flask server
    ip_address = request.remote_addr
    return render_template('index.html', ip_address=ip_address)

@app.route('/action')
def action():
    data = 'A'  # Data to be sent to Arduino
    teensy.write(data.encode())  # Send data to Arduino
    return 'Action command sent to Arduino'

@app.route('/forward')
def forward():
    data = 'B'  # Data to be sent to Arduino
    teensy.write(data.encode())  # Send data to Arduino
    return 'Forward command sent to Arduino'

@app.route('/backward')
def backward():
    data = 'C'  # Data to be sent to Arduino
    teensy.write(data.encode())  # Send data to Arduino
    return 'Backward command sent to Arduino'

@app.route('/right')
def right():
    data = 'D'  # Data to be sent to Arduino
    teensy.write(data.encode())  # Send data to Arduino
    return 'Right command sent to Arduino'

@app.route('/left')
def left():
    data = 'E'  # Data to be sent to Arduino
    teensy.write(data.encode())  # Send data to Arduino
    return 'Left command sent to Arduino'

@app.route('/stopdrive')
def stopdrive():
    data = 'F'  # Data to be sent to Arduino
    teensy.write(data.encode())  # Send data to Arduino
    return 'Stop Drive command sent to Arduino'

@app.route('/namasthe')
def namasthe():
    data = 'G'  # Data to be sent to Arduino
    teensy.write(data.encode())  # Send data to Arduino
    return 'Namasthe command sent to Arduino'

@app.route('/namasthereset')
def namasthereset():
    data = 'H'  # Data to be sent to Arduino
    teensy.write(data.encode())  # Send data to Arduino
    return 'Namasthe Reset command sent to Arduino'

@app.route('/handwave')
def handwave():
    data = 'I'  # Data to be sent to Arduino
    teensy.write(data.encode())  # Send data to Arduino
    return 'Handwave command sent to Arduino'

@app.route('/wavereset')
def wavereset():
    data = 'J'  # Data to be sent to Arduino
    teensy.write(data.encode())  # Send data to Arduino
    return 'Handwave Reset command sent to Arduino'

@app.route('/seq1')
def seq1():
    data = 'K'  # Data to be sent to Arduino
    teensy.write(data.encode())  # Send data to Arduino
    return 'Seq1 command sent to Arduino'

@app.route('/seq2')
def seq2():
    data = 'L'  # Data to be sent to Arduino
    teensy.write(data.encode())  # Send data to Arduino
    return 'Seq2 command sent to Arduino'

@app.route('/flower')
def flower():
    data = 'M'  # Data to be sent to Arduino
    teensy.write(data.encode())  # Send data to Arduino
    return 'Flower command sent to Arduino'


if __name__ == '__main__':
    # Get the IP address of the laptop running the Flask server
    hostname = socket.gethostname()
    ip_address = socket.gethostbyname(hostname)
    print(f"Laptop IP Address: {ip_address}")

    # Enable HTTPS using a self-signed certificate
    context = ssl.SSLContext(ssl.PROTOCOL_TLSv1_2)
    context.load_cert_chain('/home/achu/Mika-June-23/teensy-python-flask/certificates/certificate.crt', '/home/achu/Mika-June-23/teensy-python-flask/certificates/private.key')

    try:
        app.run(host='0.0.0.0', port=5000, ssl_context=context)
    except OSError:
        # Fallback to HTTP if HTTPS fails (e.g., certificate not found)
        app.run(host='0.0.0.0', port=5000)



    app.run(host='0.0.0.0', port=5000)



#print("Whoa! Look at that, you entered ", code)

SerialObj.close()          # Close the port

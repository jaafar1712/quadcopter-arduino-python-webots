import serial
import time

class ArduinoSerial:
    def __init__(self, port, baudrate=115200):
        self.ser = serial.Serial(port, baudrate, timeout=1)
        time.sleep(2)

    def send(self, r, p, y, t):
        self.ser.write(f"{r},{p},{y},{t}\n".encode())

    def close(self):
        self.ser.close()

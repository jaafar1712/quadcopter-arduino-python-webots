from serial_interface import ArduinoSerial
import time

arduino = ArduinoSerial("COM3")

try:
    while True:
        arduino.send(0, 0, 0, 1200)
        time.sleep(0.02)
except KeyboardInterrupt:
    arduino.close()

import tkinter as tk
from serial_interface import ArduinoSerial

arduino = ArduinoSerial("COM3")

root = tk.Tk()
root.title("Quadcopter Control")

def send():
    arduino.send(roll.get(), pitch.get(), yaw.get(), throttle.get())

roll = tk.DoubleVar()
pitch = tk.DoubleVar()
yaw = tk.DoubleVar()
throttle = tk.IntVar(value=1100)

for label, var in [("Roll", roll), ("Pitch", pitch), ("Yaw", yaw), ("Throttle", throttle)]:
    tk.Label(root, text=label).pack()
    tk.Scale(root, variable=var, from_=-10, to=10, orient="horizontal").pack()

tk.Button(root, text="Send", command=send).pack()
root.mainloop()

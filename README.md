# quadcopter-arduino-python-webots

End-to-end quadcopter flight control system with embedded control, Python supervision, and Webots simulation.
# Quadcopter Flight Control System (Arduino + Python + Webots)

A complete quadcopter UAV project featuring an Arduino Nano flight controller,
Python-based supervisory control, and Webots simulation for validation.

This project demonstrates embedded systems development, control theory,
robotics simulation, and software–hardware integration.

---

## Features
- Arduino Nano flight controller
- MPU6050 IMU-based attitude estimation
- PID stabilization (roll, pitch, yaw)
- Python serial control and GUI interface
- Webots simulation for controller validation
- Modular, extensible software architecture

---

## System Architecture
The system is divided into four layers:

1. **Embedded Control**  
   Real-time flight control on Arduino Nano (sensor fusion, PID, motor mixing)

2. **High-Level Control**  
   Python-based serial communication, command generation, and monitoring

3. **Simulation**  
   Webots-based quadcopter model for testing control behavior

4. **Documentation**  
   Engineering-focused documentation extracted from thesis work

---

## Repository Structure


# Quadcopter Flight Control System (Arduino + Python + Webots)

A complete quadcopter UAV project featuring an Arduino Nano flight controller,
Python-based supervisory control, and Webots simulation for validation.

This project demonstrates embedded systems development, control theory,
robotics simulation, and software0hardware integration.

---

## Features
- Arduino Nano flight controller
- MPU6050 IMU-based attitude estimation
- PID stabilization (roll, pitch, yaw)
- Python serial control and GUI
- Webots simulation for validation
- Modular, extensible architecture

---

## System Architecture
1. Embedded Control (Arduino Nano)
2. High-Level Control (Python over serial)
3. Simulation (Webots)
4. Documentation

---

## Repository Structure
See `/src`, `/simulations`, and `/docs`.

---

## Running the Project

### Arduino
- Upload `flight_controller.ino`
- Connect MPU6050 and ESCs
- Use propellers only in controlled environments

### Python
```bash
pip install pyserial
python controller.py
```

### Webots

* Open Webots
* Load `quadcopter.wbt`
* Run `quadcopter_controller.py`

---

## Future Improvements

* EKF-based state estimation
* Autonomous navigation
* ROS integration
* Hardware-in-the-loop simulation

---

## License

MIT License

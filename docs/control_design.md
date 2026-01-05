# Control Design

This document provides a high-level overview of the control design:

- PID controllers for roll, pitch, and yaw.
- Tuning parameters are seeded in the Arduino sketch (kp, ki, kd).
- Integrator anti-windup and derivative filtering are recommended for production use.
- Future: replace PID with cascaded PID + EKF state estimation for robustness.

Safety note: The provided control code is educational. Do not fly without thorough testing.

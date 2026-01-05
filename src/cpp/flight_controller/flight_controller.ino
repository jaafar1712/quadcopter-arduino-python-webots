#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>

MPU6050 imu;

Servo motorFL, motorFR, motorBL, motorBR;

#define FL_PIN 3
#define FR_PIN 5
#define BL_PIN 6
#define BR_PIN 9

float kp = 1.8, ki = 0.02, kd = 0.9;
float roll, pitch, yaw;
float rollError, pitchError, yawError;
float rollI, pitchI, yawI;
float prevRoll, prevPitch, prevYaw;

int baseThrottle = 1100;
unsigned long lastTime;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  imu.initialize();

  motorFL.attach(FL_PIN);
  motorFR.attach(FR_PIN);
  motorBL.attach(BL_PIN);
  motorBR.attach(BR_PIN);

  armMotors();
  lastTime = millis();
}

void loop() {
  readIMU();
  readSerial();
  computePID();
  mixMotors();
}

void readIMU() {
  int16_t ax, ay, az, gx, gy, gz;
  imu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);

  roll  = atan2(ay, az) * 57.3;
  pitch = atan2(-ax, sqrt(ay*ay + az*az)) * 57.3;
  yaw  += gz * 0.000061;
}

void readSerial() {
  if (Serial.available()) {
    rollError  = Serial.parseFloat();
    pitchError = Serial.parseFloat();
    yawError   = Serial.parseFloat();
    baseThrottle = Serial.parseInt();
  }
}

void computePID() {
  float dt = (millis() - lastTime) / 1000.0;
  lastTime = millis();

  rollI  += rollError * dt;
  pitchI += pitchError * dt;
  yawI   += yawError * dt;
}

void mixMotors() {
  int rollOut  = kp*rollError;
  int pitchOut = kp*pitchError;
  int yawOut   = kp*yawError;

  motorFL.writeMicroseconds(baseThrottle + pitchOut - rollOut + yawOut);
  motorFR.writeMicroseconds(baseThrottle + pitchOut + rollOut - yawOut);
  motorBL.writeMicroseconds(baseThrottle - pitchOut - rollOut - yawOut);
  motorBR.writeMicroseconds(baseThrottle - pitchOut + rollOut + yawOut);
}

void armMotors() {
  motorFL.writeMicroseconds(1000);
  motorFR.writeMicroseconds(1000);
  motorBL.writeMicroseconds(1000);
  motorBR.writeMicroseconds(1000);
  delay(3000);
}

from controller import Robot

robot = Robot()
timestep = int(robot.getBasicTimeStep())

motors = []
for name in ["motor_fl","motor_fr","motor_bl","motor_br"]:
    m = robot.getDevice(name)
    m.setPosition(float('inf'))
    m.setVelocity(0)
    motors.append(m)

imu = robot.getDevice("inertial unit")
imu.enable(timestep)

base = 6.0

while robot.step(timestep) != -1:
    roll, pitch, yaw = imu.getRollPitchYaw()
    motors[0].setVelocity(base - roll + pitch)
    motors[1].setVelocity(base + roll + pitch)
    motors[2].setVelocity(base - roll - pitch)
    motors[3].setVelocity(base + roll - pitch)

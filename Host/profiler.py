import pygame
import sys
import serial
import matplotlib.pyplot as plt
import numpy

# parse the input argument
if len(sys.argv) == 1:
    ex = Exception('Error: Not enough parameters')
    raise ex

manual = False
profile_path = ''

for i in range(1, len(sys.argv)):
    if sys.argv[i] == '--port':
        i += 1
        stm_port = sys.argv[i]
    elif sys.argv[i] == '--manual'
        manual = True

# configure the serial port for STM32
stm32 = serial.Serial(
    port=stm_port,
    baudrate=152000,
    parity=serial.PARITY_ODD,
    stopbits=serial.STOPBITS_TWO,
    bytesize=serial.SEVENBITS
)

# find and initiate the joystick
pygame.init()
pygame.joystick.init()
joystick_count = pygame.joystick.get_count()
x56stick = pygame.joystick.Joystick(0)
for i in range(joystick_count):
    if "Stick" in pygame.joystick.Joystick(i).get_name():
        x56stick = pygame.joystick.Joystick(i)
x56stick.init()

# open the serial port
stm32.isOpen()

# set the parameters
done = False
axis-x = 0
axis-y = 0

# define the close behavior
def on_close(event):
    done = True

# initiate the plot
fig, ax = plt.subplots()

img = plt.imread("background.jpg")
ax.imshow(img, extent=[-1, 1, -1, 1])
ax.scatter(axis-x, axis-y)

plt.subplots_adjust(bottom=0.5)
plt.show()

# main loop
while not done:
    # Get axis from throttle
    axis_x = x56stick.get_axis(0)
    axis_y = x56stick.get_axis(1)


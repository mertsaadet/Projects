import serial
from erayslayer import directionfinder
from determineParkingZone import park_detector

ser = serial.Serial('/dev/ttyUSB1',9600)
while True:
    a = ser.readline()
    while(a):
        if park_detector()==20:
            b = directionfinder()
            if(b==1):
                print('duz')
                ser.write(b'\x31\r\n')
            elif(b==2):
                print('sag')
                ser.write(b'\x32\r\n')
            elif(b==3):
                print('sol')
                ser.write(b'\x33\r\n')
        else:
            c = park_detector()
            if (c == 4):
                ser.write(b'\x34\r\n')
            elif (c == 5):
                ser.write(b'\x35\r\n')
            elif (c == 6):
                ser.write(b'\x36\r\n')
            elif (c == 7):
                ser.write(b'\x37\r\n')
            elif (c == 8):
                ser.write(b'\x38\r\n')
            elif (c == 9):
                ser.write(b'\x39\r\n')

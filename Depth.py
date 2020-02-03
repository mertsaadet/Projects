# Including necessary libraries
import cv2
import numpy as np
from Depth_functions import *

# Initializing variables
frames = []
circle_frames = []
cap = cv2.VideoCapture(0)
capture_counter = 0

# Looping until two frames are captured
while capture_counter < 2:
    ret, frame = cap.read()
    cv2.imshow('Frame', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        frames.append(frame)
        capture_counter += 1

# Image processing before detection
frame_blur(frames)
frame_conversion(circle_frames, frames)

# Detection of circles
ref_circles = detect_circle(circle_frames[0])
ref_circles2 = detect_circle(circle_frames[1])

# Drawing circles
for i in ref_circles[0, :]:
    cv2.circle(frames[0], (i[0], i[1]), i[2], (0, 255, 0), 2)
    break
for i in ref_circles2[0, :]:
    cv2.circle(frames[1], (i[0], i[1]), i[2], (0, 255, 0), 2)
    break

# Necessary calculations
mes = distance(ref_circles)
mes2 = distance(ref_circles2)

# Terminal information
print("Distance to object in the first frame:", mes, "cm")
print("*" * 56)
print("Distance to object in the second frame:", mes2, "cm")

# Writing the measurements on the frames
font = cv2.FONT_HERSHEY_SIMPLEX
cv2.putText(frames[0], "%.3f" % mes, (ref_circles[0][0][0] - 90, ref_circles[0][0][1] + 25), font, 70 / mes,
            (0, 0, 255), 1, cv2.LINE_AA)
cv2.putText(frames[1], "%.3f" % mes2, (ref_circles2[0][0][0] - 50, ref_circles2[0][0][1] + 25), font, 70 / mes2,
            (0, 0, 255), 1, cv2.LINE_AA)

# Closing camera and waiting a keyboard interrupt for exit
cap.release()
cv2.destroyWindow('Frame')
cv2.imshow('First captured frame', frames[0])
cv2.imshow('Second captured frame', frames[1])
cv2.waitKey(0)

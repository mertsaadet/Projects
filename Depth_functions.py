# Including necessary libraries
import cv2
import numpy as np


# Blurs the first and second element of the frame list.
def frame_blur(frame_list):
    frame_list[0] = cv2.medianBlur(frame_list[0], 11)
    frame_list[1] = cv2.medianBlur(frame_list[1], 11)


# Color space conversion
def frame_conversion(frame_list, second_frame_list):
    frame_list.append(cv2.cvtColor(second_frame_list[0], cv2.COLOR_BGR2GRAY))
    frame_list.append(cv2.cvtColor(second_frame_list[1], cv2.COLOR_BGR2GRAY))


# Takes frame and detects circles using HoughCircles Method
def detect_circle(frame):
    circles = cv2.HoughCircles(frame, cv2.HOUGH_GRADIENT, 1, 20, param1=40, param2=50, minRadius=0, maxRadius=0)
    circles = np.uint16(np.around(circles))
    return circles


# Measures distance using proportionality
def distance(circles):
    distance_to_object = (170 / circles[0][0][2]) * 30
    return distance_to_object

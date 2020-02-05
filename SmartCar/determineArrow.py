import cv2
import numpy as np
import sys

def directionfinder():
    right_cascade= cv2.CascadeClassifier('cascade_right.xml')
    left_cascade= cv2.CascadeClassifier('cascade_left.xml')
    forward_cascade= cv2.CascadeClassifier('cascade_straight.xml')
    cap = cv2.VideoCapture(1)

    tot=f=l=r=0
    while True and tot<30:
        ret, img = cap.read()

        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)


        right = right_cascade.detectMultiScale(gray, 1.01, 5)
        left = left_cascade.detectMultiScale(gray,1.08,4)
        forward = forward_cascade.detectMultiScale(gray,2.31,4)

        if len(right)!=0 :
            r+=1
            tot+=1
        elif len(left)!=0 :
            l += 1
            tot += 1
        elif len(forward)!= 0:
            f += 1
            tot += 1
        k = cv2.waitKey(30) & 0xff
        if k == 27:
            break


    a=max(l,r,f)
    if(a == l):
        return 3
    if (a == r):
        return 2
    if (a == f):
        return 1


    cap.release()
    cv2.destroyAllWindows()









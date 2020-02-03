import cv2 as cv
import numpy as np



img = cv.imread('Main.png')
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
gray = np.float32(gray)
xs = []
ys = []
corners = cv.goodFeaturesToTrack(gray, 8,0.01,30 )
corners = np.int0(corners)

for corner in corners:
    x, y = corner.ravel()
    xs.append(x)
    ys.append(y)
    cv.circle(img, (x,y),3,255,-1)
xs.sort()
ys.sort()
font = cv.FONT_HERSHEY_SIMPLEX
if((xs[4]-xs[3])>(ys[4]-ys[3])):
    cv.putText(img,'Closed',(90,130),font,1,(0,0,255),2,cv.LINE_AA)
else:
    cv.putText(img,'Open',(90,130),font,1,(0,0,255),2,cv.LINE_AA)

cv.imshow('corners',img)
cv.imwrite('detected.png',img)
import numpy as np
import cv2
import pytesseract

def park_detector():
    camera = cv2.VideoCapture(1)

    while True:
        try:
            success, ret = camera.read()

            # TODO Set Threshold

            rekt, thresh = cv2.threshold(cv2.cvtColor(ret, cv2.COLOR_BGR2GRAY), 100, 255, cv2.THRESH_BINARY)

            thresh = cv2.medianBlur(thresh, 3)
            circimage = cv2.cvtColor(ret,cv2.COLOR_BGR2GRAY)
            circles = cv2.HoughCircles(circimage, cv2.HOUGH_GRADIENT, 1, 50, param1=160, param2=40)
            circles = np.uint16(np.around(circles))

            mr_hough =circimage
            max_r, max_i = 0, 0
            for i in range(len(circles[:, :, 2][0])):
                if circles[:, :, 2][0][i] > 50 and circles[:, :, 2][0][i] > max_r:
                    max_i = i
                    max_r = circles[:, :, 2][0][i]
            x, y, r = circles[:, :, :][0][max_i]


            if y > r and x > r:

                square = mr_hough[y - r:y + r, x - r:x + r]

                aq,square = cv2.threshold(square, 100, 255, cv2.THRESH_BINARY)
                cv2.imwrite('square.jpg', square)
                cv2.imshow('wo',square)
                cv2.waitKey(1)
                text = pytesseract.image_to_string(square, lang='eng',
                                                   config='--psm 7 tessedit_char_whitelist=AB123')

                print(text)

                chars = "()\",]{&\' "
                for char in chars:
                    text = text.replace(char, "")
                print(text)

                mission = None

                if text == "Al" or text == "A1" or text == "AI"or text == "AL"or text == "A7":
                    mission = 4
                elif text == "A2" or text == "AZ":
                    mission = 5
                elif text == "A3" or text == "AS" or text == "A5" or text == "kA3" or text =="AB":
                    mission = 6
                elif text == "Bl" or text == "B1" or text == "BI" or text == "8l" \
                        or text == "81" or text == "8I" or text == "61" or text == "Bi" \
                        or text == "bl" or text == "31" or text == "3l" or text == "Bl"or text == "BL":
                    mission = 7
                elif text == "B2" or text == "82" or text == "62" or text == "BZ" \
                        or text == "52":
                    mission = 8
                elif text == "B3" or text == "BS" or text == "83" or text == "8S" or \
                        text == "63" or text == "L3" or text == "33":
                    mission = 9
                elif text == "=" or text == "=>" or text == "<=" or text =="t" or text =="tt" or  text =="-" or text =="—" or text =="—>" or text =="--" or text =="<—" or text =="|" or text =="mert" or text == "=)" or text == "(=" :
                    camera.release()
                    return 20
                elif mission is None:
                    continue

                camera.release()
                return mission


        except:
            continue


# -*- coding: utf-8 -*

import cv2
import numpy as np
import random

font = cv2.FONT_HERSHEY_COMPLEX
windowLength = 700
windowWidth  = 400
buttonLength = 100
buttonWidth  = 25
buttonNoPos  = [100, 300]
buttonYesPos = (400, 300)

background = (240, 240, 240)
lightgray  = (230, 230, 230)
gray       = (200, 200, 200)
darkgray   = (150, 150, 150)
black      = (  0,   0,   0)
buttonYesColor = lightgray

sentence1 = 'Is Nightwheel an angel?'
sentence2 = ''
sentence3 = 'Press Esc to exit.'
clickYesFlag = 0


def changeImg(event, x, y, flags, param):
    global buttonNoPos, buttonYesColor, sentence1, sentence2, clickYesFlag

    if not clickYesFlag:
        if buttonNoPos[0] < x < buttonNoPos[0]+buttonLength and buttonNoPos[1] < y < buttonNoPos[1]+buttonWidth:
            newx = newy = -1
            while not(0 < newx < windowLength - buttonLength and 100 < newy < windowWidth - buttonWidth) or \
                    (buttonYesPos[0] < newx < buttonYesPos[0]+buttonLength
                     or buttonYesPos[0] < newx+buttonLength < buttonYesPos[0]+buttonLength
                     or buttonYesPos[1] < newy < buttonYesPos[0]+buttonWidth
                     or buttonYesPos[1] < newy+buttonWidth < buttonYesPos[0]+buttonWidth):
                newx = random.randint(0, windowLength - buttonLength)
                newy = random.randint(100, windowWidth - buttonWidth)
            buttonNoPos = [newx, newy]

        if buttonYesPos[0] < x < buttonYesPos[0]+buttonLength and buttonYesPos[1] < y < buttonYesPos[1]+buttonWidth:
            buttonYesColor = gray
            if event == cv2.EVENT_LBUTTONDOWN:
                sentence1 = 'NightWheel is an angel.'
                sentence2 = 'Ah-Ah-Ah I\'m so excited that I run in a loop.'
                clickYesFlag = 1

        else:
            buttonYesColor = lightgray


def showImg():
    global img
    img = np.zeros((windowWidth, windowLength, 3), np.uint8)
    img[:] = background
    cv2.putText(img, sentence1, (100, 50), font, 0.6, black, 0, cv2.LINE_AA)
    cv2.putText(img, sentence2, (100, 80), font, 0.6, black, 0, cv2.LINE_AA)
    if not clickYesFlag:
        drawButton(img, buttonNoPos, 'No', lightgray)
        drawButton(img, buttonYesPos, 'Yes', buttonYesColor)
    else:
        cv2.putText(img, sentence3, (100, 140), font, 0.5, darkgray, 0, cv2.LINE_AA)

    cv2.namedWindow('angel')
    cv2.setMouseCallback('angel', changeImg)


def drawButton(img, pos, character, color):
    cv2.rectangle(img, tuple(pos), (pos[0]+buttonLength, pos[1]+buttonWidth), color, -1)
    cv2.rectangle(img, tuple(pos), (pos[0]+buttonLength, pos[1]+buttonWidth), gray, 1)
    cv2.putText(img, character, (pos[0]+35, pos[1]+20), font, 0.6, black, 0, cv2.LINE_AA)


img = np.zeros((400, 700, 3), np.uint8)

while (1):
    showImg()
    cv2.imshow('angel', img)

    k = cv2.waitKey(1) & 0xFF
    if k == 27:
        break

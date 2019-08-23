import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
print ("Use BCM 17, 27, 22")
GPIO.setup(17, GPIO.OUT)
GPIO.output(17, False)
GPIO.setup(27, GPIO.OUT)
GPIO.output(27, False)
GPIO.setup(22, GPIO.OUT)
GPIO.output(22, False)

count=0

while count<100:
    GPIO.output(17, True)
    time.sleep(1)
    GPIO.output(17,False)
    time.sleep(2)
    GPIO.output(27, True)
    time.sleep(1)
    GPIO.output(27,False)
    time.sleep(2)
    GPIO.output(22, True)
    time.sleep(1)
    GPIO.output(22,False)
    time.sleep(2)

    count += 1

print("LED Test End")
GPIO.cleanup()

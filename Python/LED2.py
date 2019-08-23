import RPi.GPIO as GPIO
import time



GPIO.setmode(GPIO.BCM)
print ("Use BCM 17")
GPIO.setup(17, GPIO.OUT)
GPIO.output(17, False)

count=0

while count<100:
    GPIO.output(17, True)
    time.sleep(1)
    GPIO.output(17,False)
    time.sleep(2)
    count += 1

print("LED Test End")
GPIO.cleanup()

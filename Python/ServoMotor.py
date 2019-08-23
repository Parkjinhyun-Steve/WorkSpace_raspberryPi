import RPi.GPIO as GPIO
import time

# wPi. 1, BCM. 18, Physical. 12
SERVO = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(SERVO,GPIO.OUT)
pwm = GPIO.PWM(SERVO, 50)
pwm.start(7.2)

def angle(angle):
    pwm.ChangeDutyCycle(7.2 - angle / 18.75)
    print("%s" % angle)
    time.sleep(1)

if __name__ == "__main__":
    try :
        Angle(0)
        Angle(30)
        Angle(60)
        Angle(90)
        Angle(60)
        Angle(30)
        Angle(0)
        Angle(-30)
        Angle(-60)
        Angle(-90)
        Angle(-60)
        Angle(-30)
        Angle(0)

    except :
        print("ERROR")

    finally :
        GPIO.cleanup()
        print("END")







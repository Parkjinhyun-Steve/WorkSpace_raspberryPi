import RPi.GPIO as GPIO

SWITCH = 18

LED = 23

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

GPIO.setup(LED, GPIO.OUT)
GPIO.setup(SWITCH, GPIO.IN, pull_up_down = GPIO.PUD_DOWN)

try :
    while True : 
        if GPIO.input(SWITCH) == 1 :
            GPIO.output(LED, True)
        else :
            GPIO.output(LED, False)

except :
    GPIO.cleanup()
    print("end")


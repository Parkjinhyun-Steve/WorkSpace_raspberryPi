

import Adafruit_DHT, time, sys

sensor = Adafruit_DHT.DHT11
pin = 23

if __name__ == "__main__":
    try:
        while(True):
            humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)

            now = time.localtime()
            timestamp = ("%04d-%02d-%02d %02d:%02d:%02d" %
            (now.tm_year, now.tm_mon, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec))

            print("%s humidity : %0.1f\n%s temperature : %0.1f\n" %
            (timestamp, humidity, timestamp, temperature))

            time.sleep(1)
    
    except:
        print("error OR Press Ctrl -C")
    finally:
        sys.exit(1)

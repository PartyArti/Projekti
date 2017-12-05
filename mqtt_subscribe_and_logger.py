import paho.mqtt.client as mqtt
import time

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("sensori")

def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))
    log = open('mqtt_log.txt' ,'a')
    log.write(msg.payload + "\t" + (time.strftime("%y.%d.%m\t%H:%M:%S")))
    log.write('\n')

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("172.20.10.6", 1883, 60)

client.loop_forever()
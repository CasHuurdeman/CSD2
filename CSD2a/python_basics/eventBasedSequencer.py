import pygame
import time

pygame.init()

#Samples
hihat = pygame.mixer.Sound("Hihat.wav")
snare = pygame.mixer.Sound("Snare.wav")
kick = pygame.mixer.Sound("Kick.wav")


#Dictionaries
hihatEvent = {
        "sample": hihat,
        "instrument": "Hihat",
        "velocity": 100,
        "duration": 500,
        "timestamp": None
}

snareEvent = {
        "sample": snare,
        "instrument": "Snare",
        "velocity": 100,
        "duration": 500,
        "timestamp": None
}

kickEvent = {
        "sample": kick,
        "instrument": "Kick",
        "velocity": 100,
        "duration": 500,
        "timestamp": None
}


#Events?
kickTimestamps = []
snareTimestamps = []
hihatTimestamps = []

eventList = []

# Maybe not necessary
for i in range(16):
    if (i%4) ==0:
        kickTimestamps.append((i+1))
    snareTimestamps.append(i+1)
    hihatTimestamps.append(i+0.5)
    hihatTimestamps.append(i+1)

print(kickTimestamps,snareTimestamps,hihatTimestamps)

#Useless for now
def pushTimestampsToDictionary(event,ts):
    for i in range(len(ts)):
        event["timestamp"] = ts[i]
        eventList.append(event)
        print(eventList)
        eventList.clear()



pushTimestampsToDictionary(snareEvent,snareTimestamps)

#Event handler function
def eventHandler(event):
    print(event["instrument"])
    event["sample"].play()
    



# Show BPM and ask user to change
initBPM = 120
BPM = None
print("BPM: ", initBPM)
if input("Do you want to change the BPM (y/n)? \n ") == 'y':
    while type(BPM) != float:
        try: 
            BPM = float(input("New BPM: "))
        except ValueError:
            print('Invalid integer value')
else: BPM = initBPM


eventHandler(hihatEvent)
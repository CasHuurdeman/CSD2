import pygame
import time

pygame.init()

#Samples
hihat = pygame.mixer.Sound("Hihat.wav")
snare = pygame.mixer.Sound("Snare.wav")
kick = pygame.mixer.Sound("Kick.wav")


#Dictionaries with instrument events
hihatEvent = {
        "sample": hihat,
        "instrument": "Hihat",
        "velocity": 100,
        "duration": 1,
        "timestamp": None
}

snareEvent = {
        "sample": snare,
        "instrument": "Snare",
        "velocity": 100,
        "duration": 1,
        'timestamp': None
}

kickEvent = {
        "sample": kick,
        "instrument": "Kick",
        "velocity": 100,
        "duration": 1,
        "timestamp": None
}



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



# Function to generate timestamps based on growth factor
barLength = 240/BPM  #in seconden

def generateTimestamps(numNotes, growthFactor):

    growthFactorList = []


    for i in range(numNotes):
        growthFactorList.append(growthFactor**i)

    initLength = barLength/(sum(growthFactorList))
    print((growthFactorList))

    timestamps = []
    durations = []
    summ = 0

    for i in range (numNotes):
        initLength *= growthFactor
        durations.append(initLength)

        timestamps.append(summ)
        summ = summ + durations[i]

    return timestamps



#Lists for timestamps
kickTimestamps = []
snareTimestamps = []
hihatTimestamps = []



# Timestamps aanmaken
for i in range(17):
    if (i%2) ==0:
        kickTimestamps.append((i))
    snareTimestamps.append(i+0.5)
    hihatTimestamps.append(i+0.5)
    hihatTimestamps.append(i)


# Pushes a copy of a dictionary with the proper timestamp to an event list
def pushTimestampsToDictionary(event,ts, eventList):
    for i in range(len(ts)):
        event["timestamp"] = ts[i]
        eventList.append(event.copy())



# Create the event lists
snareEventList = []
kickEventList = []
hihatEventList = []

pushTimestampsToDictionary(snareEvent, generateTimestamps(13, 10), snareEventList)
pushTimestampsToDictionary(kickEvent, kickTimestamps, kickEventList)
pushTimestampsToDictionary(hihatEvent, hihatTimestamps, hihatEventList)

# eventList = snareEventList + kickEventList + hihatEventList
eventList = snareEventList



# Sorting the list based on timestamps
def getTimestamp(instrument):
    return instrument["timestamp"]

eventList.sort(key = getTimestamp)



# Event handler
def eventHandler(event):
    print(event["instrument"])
    event["sample"].play()



# Store eventList in case user wants to save it
storedEventList = eventList



# While loop to play the samples
timeZero = time.time() # Store current time
ts = eventList[0]["timestamp"]

while True:    
    secondsPlaying = time.time() - timeZero

    # check if we passed the next timestamp,
    # if so, play sample and fetch new timestamp
    if secondsPlaying >= ts:
        print(ts)
        eventList[0]["sample"].play()

        simultaneousEvents = []

        while eventList and eventList[0] == ts:
            simultaneousEvents.append(eventList.pop(0))
        if len(eventList) > 1:
            ts = eventList.pop(0)
            ts = eventList[0]["timestamp"] 
        else:
            # no new timestamp available --> break while loop
            time.sleep(0.5)
            break


        
    time.sleep(0.001)


# Clear storedEventList after asking for it to be saved
storedEventList.clear()

# Clearing lists that need to be cleared
kickTimestamps.clear()
snareTimestamps.clear()
hihatTimestamps.clear()

snareEventList.clear()
kickEventList.clear()
hihatEventList.clear()

eventList.clear()



















# # Function to generate timestamps based on growth factor
# def generateTimestamps(numNotes, growthFactor, startDuration):
#     timestamps = []
#     currentTime = 0

#     for i in range(numNotes):
#         timestamps.append(currentTime)
#         currentTime += startDuration
#         startDuration *= growthFactor
    
#     return timestamps


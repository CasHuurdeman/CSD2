import pygame
import time
import random
from midiutil import MIDIFile
import os

pygame.init()

# Samples
hihat = pygame.mixer.Sound("Hihat.wav")
snare = pygame.mixer.Sound("Snare.wav")
kick = pygame.mixer.Sound("Kick.wav")


# Function to generate event dictionaries 
def generateEvent(sample, instrument):
    eventName = {
        "sample": sample,
        "instrument": instrument,
        "velocity": 100,
        "duration": None,
        "timestamp": None
    }
    return eventName

hihatEvent = generateEvent(hihat, "Hihat")
snareEvent = generateEvent(snare, "Snare")
kickEvent = generateEvent(kick, "Kick")



# Show BPM and ask user to change  (begin met alle settings vragen--> user input )
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

# Ask for growthFactor and numNotes and random or not + number of repeats
 
numberOfRepeats = int(input("How many times do you want to repeat this rhythm: "))


# Function to generate timestamps based on growth factor
# uitleg waarom lelijk
def generateTimestamps(numNotes, growthFactor):

    barLength = 240/BPM

    if(growthFactor > 1):
        growthFactorList = []
        extraNote = 0

        for i in range(numNotes):
            growthFactorList.append(growthFactor**i)
        
        initLength = barLength/(sum(growthFactorList))

    elif (growthFactor > 0.6 and growthFactor < 1):
        initLength = 1
        extraNote = 1
     
    else:
        print("nope nieuwe growthFactor")  #aan het begin van de code zetten

    

    timestamps = []
    durations = []
    summ = 0

    for i in range (numNotes + extraNote):
        initLength *= growthFactor
        durations.append(initLength)

        timestamps.append(summ)
        summ = summ + durations[i]

    # print(durations)

    if(growthFactor >=  0.6 and growthFactor < 1):

        initLenFactor = barLength/timestamps.pop(numNotes)

        timestampsNew = []
        durationsNew = []

        for timestamps in timestamps:
            timestampsNew.append(timestamps*initLenFactor)
        
        # Note to self: the durations also have to be scaled, this is probably not the most efficient way to do it 
        for durations in durations:
            durationsNew.append(durations*initLenFactor)

        return [timestampsNew, durationsNew]
    else: return [timestamps, durations]



# Pushes a copy of a dictionary with the proper timestamp to an event list
def pushTimestampsToDictionary(event,timestamp, eventList):
    for i in range(len(timestamp[0])):
        event["timestamp"] = timestamp[0][i]

        event["duration"] = timestamp[1][i]

        eventList.append(event.copy())




# Create the event lists
hihatEventList = []
snareEventList = []
kickEventList = []

pushTimestampsToDictionary(hihatEvent, generateTimestamps(21, 0.9), hihatEventList)
pushTimestampsToDictionary(snareEvent, generateTimestamps(8, 0.8), snareEventList)
pushTimestampsToDictionary(kickEvent, generateTimestamps(5, 0.61), kickEventList)


eventList = hihatEventList + snareEventList + kickEventList



# Sorting the list based on timestamps
def getTimestamp(instrument):
    return instrument["timestamp"]

eventList.sort(key = getTimestamp)

# Store eventList in case user wants to save it
storedEventList = eventList.copy()



# Event handler
def eventHandler(event):
    print(event["instrument"])
    event["sample"].play()



# While loop to play the samples
def playSound():
    eventList = storedEventList.copy()
    # print(storedEventList)
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
                break


            
        time.sleep(0.001)



# For loop to play the sequence multiple times
for i in range(numberOfRepeats):
    playSound()


# Store as a Midi file
if (input("Do you want to save this beat as a MIDI file? (y/n): ")) == "y":
    userFileName = input("File name: ")

    track = 0
    channel = 9

    mf = MIDIFile(1)

    time_beginning = 0
    mf.addTrackName(track, time_beginning, "exponential drums")
    mf.addTempo(track, time_beginning, BPM)

    # variables necessary for transforming events to midi output
    qnote_dur = 60 / BPM
    instr_midi_pitch = {
        "Kick": 35,
        "Snare": 38,
        "Hihat": 41
    }

    for event in eventList:
        # transform time (sec) to (qnote)
        qnote_time = event["timestamp"] / qnote_dur
        instr_name = event["instrument"]
        mf.addNote(track, channel, instr_midi_pitch[instr_name], qnote_time,
            event["duration"], event["velocity"])

    with open(os.path.expanduser("~") + fr"\Downloads\{userFileName}.midi","wb") as outf: #this only works for windows because of the backslashes
        mf.writeFile(outf)

    print("File is stored in downloads")


# # Clear storedEventList after asking for it to be saved
# storedEventList.clear()

# # Clearing lists that need to be cleared

# snareEventList.clear()
# kickEventList.clear()
# hihatEventList.clear()

# eventList.clear()



















# # Function to generate timestamps based on growth factor
# def generateTimestamps(numNotes, growthFactor, startDuration):
#     timestamps = []
#     currentTime = 0

#     for i in range(numNotes):
#         timestamps.append(currentTime)
#         currentTime += startDuration
#         startDuration *= growthFactor
    
#     return timestamps


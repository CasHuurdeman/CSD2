import pygame
import time
import random
from midiutil import MIDIFile
import os

pygame.init()

# Colours (code from https://stackoverflow.com/questions/287871/how-do-i-print-colored-text-to-the-terminal)
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


# Samples
hihat = pygame.mixer.Sound("Hihat.wav")
snare = pygame.mixer.Sound("Snare.wav")
kick = pygame.mixer.Sound("Kick.wav")

# Number sequences:
fib = [2, 3, 5, 8, 13, 21]
pwrOf2 = [1, 2, 4, 8, 16, 32]
linear = [1, 2, 3, 4, 5, 6, 7]



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
print("\nBPM: ", initBPM)
if input("Do you want to change the BPM (y/n)?\n") == 'y':
    print("New BPM (between 30 and 350):")
    while BPM == None or BPM < 30 or BPM > 350:
        try: 
            BPM = float(input(""))
        except ValueError:
            print(f"{bcolors.WARNING}Invalid value, try again:{bcolors.ENDC}")
else: BPM = initBPM



# User input 
# Note: probably duplicates

# ---Sequence---
chosenSeq = None
print("\nWhich sequence do you want to use? (1,2,3): \n 1. Fibonacci sequence \n 2. Power of two sequence \n 3. Normal sequence")

while chosenSeq != 1 and chosenSeq != 2 and chosenSeq != 3:
    try: chosenSeq = int(input(""))
    except ValueError:
        print(f"{bcolors.WARNING}Invalid value, try again:{bcolors.ENDC}")


# ---Growthfactors---
def tryGrowthfactorInput(variable, type, string):
    print(string)
    while variable == None or variable < 0.6 or variable > 1.6:
        try: variable = type(input("        "))
        except ValueError:
            print(f"{bcolors.WARNING}Invalid value, try again:{bcolors.ENDC}")

    return variable


growthfactorHihat = None
growthfactorSnare = None
growthfactorKick = None

print("\nChose growthfactors (from 0.6 to 1.6)")
tryGrowthfactorInput(growthfactorHihat, float, "    Hihat growthfactor: ")
tryGrowthfactorInput(growthfactorSnare, float, "    Snare growthfactor: ")
tryGrowthfactorInput(growthfactorKick, float, "    Kick growthfactor: ")


# ---Repeats---
numberOfRepeats = None
print("\nHow many times do you want to repeat this rhythm (max 10):  ")

while numberOfRepeats == None or numberOfRepeats < 0 or numberOfRepeats >= 10:
    try: numberOfRepeats = int(input())
    except ValueError:
        print(f"{bcolors.WARNING}Invalid value, try again:{bcolors.ENDC}")



# Picking random numbers from a list
if(chosenSeq == 1):
    chosenSeq = fib
elif(chosenSeq == 2):
    chosenSeq = pwrOf2
else: chosenSeq = linear

numOfHihats = (random.choice(chosenSeq[3:6]))
numOfSnares = (random.choice(chosenSeq[1:4]))
numOfKicks = (random.choice(chosenSeq[0:3]))



# Function to generate timestamps based on growth factor
# This function decides between two algorithms: one for growthFactor > 1, one for growthFactor < 1
def generateTimestamps(numNotes, growthFactor):

    barLength = 240/BPM

    if(growthFactor > 1):
        growthFactorList = []
        extraNote = 0

        for i in range(numNotes):
            growthFactorList.append(growthFactor**i)
        
        initLength = barLength/(sum(growthFactorList))

    else:
        initLength = 1
        extraNote = 1

    

    timestamps = []
    durations = []
    summ = 0

    for i in range (numNotes + extraNote):
        initLength *= growthFactor
        durations.append(initLength)

        timestamps.append(summ)
        summ = summ + durations[i]


    if(growthFactor > 1):
        return [timestamps, durations]
    
    else:
        initLenFactor = barLength/timestamps.pop(numNotes)

        timestampsNew = []
        durationsNew = []

        for timestamps in timestamps:
            timestampsNew.append(timestamps*initLenFactor)
        
        # Note to self: the durations have to be scaled, but this is probably not the most efficient way to do it 
        for durations in durations:
            durationsNew.append(durations*initLenFactor)

        return [timestampsNew, durationsNew]



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

pushTimestampsToDictionary(hihatEvent, generateTimestamps(numOfHihats, 0.9), hihatEventList)
pushTimestampsToDictionary(snareEvent, generateTimestamps(numOfSnares, 0.8), snareEventList)
pushTimestampsToDictionary(kickEvent, generateTimestamps(numOfKicks, 0.61), kickEventList)


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
    timeZero = time.time() # Store current time
    ts = eventList[0]["timestamp"]

    while True:    
        secondsPlaying = time.time() - timeZero

        # check if we passed the next timestamp,
        # if so, play sample and fetch new timestamp
        if secondsPlaying >= ts:
            eventList[0]["sample"].play()

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
if (input("\nDo you want to save this beat as a MIDI file? (y/n):\n")) == "y":

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

    # Writes the file to the downloads folder(with exception handler)
    userFileName = None
    while userFileName != "MIDI":
        try: 
            userFileName = input("\nFile name: ")

            with open(os.path.expanduser("~") + fr"\Downloads\{userFileName}.midi","wb") as outf: #this only works for windows because of the backslashes
                mf.writeFile(outf)

        except OSError: 
            print(f"{bcolors.WARNING}Invalid name, try again:{bcolors.ENDC}")

    print(f"{bcolors.OKGREEN}\nFile is stored in downloads{bcolors.ENDC}")
import pygame
import time

pygame.init()

Hihat = pygame.mixer.Sound('Hihat.wav')

# BPM
initBPM = 120
BPM = None
print(type(BPM))
print("BPM: ", initBPM)
if input("Do you want to change the BPM (y/n)? \n ") == 'yes':
    while type(BPM) != int:
        try: 
            BPM = int(input("New BPM: "))
        except ValueError:
            print('Invalid integer value')
else: BPM = initBPM


# numPlaybackTimes = int(input("How many notes: "))


bpmToSeconds = 60/BPM

#Asks user to create list, removes all comma's and converts the strings to floats

timestamps16th = (input("List of 16th note timestamps: "))
timestamps16th = list(timestamps16th.split(","))

for i in timestamps16th:
    timestamps16th.append(float(timestamps16th[0]) * bpmToSeconds) #conversion from notes to seconds 
    timestamps16th.remove(timestamps16th[0])  
    

#Function to create time stamps
timestampList = []

def durationToTimestamps16th(list):
    sum = 0
    for time_dur in timestamps16th:
        timestampList.append(sum)
        sum = sum + time_dur

durationToTimestamps16th(timestamps16th)

print(timestampList)

# retrieve the first time stamp
if timestampList:
    ts = timestampList.pop(0)
else:
    # list contains no items
    print("no timestamps --> exit")
    exit()

# store the current time
time_zero = time.time()

# iterate through time sequence and play sample
while True:
    now = time.time() - time_zero
    # check if we passed the next timestamp,
    # if so, play sample and fetch new timestamp
    if(now >= ts):
        print(ts)
        Hihat.play()
        if timestampList:
            ts = timestampList.pop(0)
        else:
            # no new timestamp available --> break while loop
            time.sleep(0.5)
            break

    time.sleep(0.001)
    

timestamps16th.clear()
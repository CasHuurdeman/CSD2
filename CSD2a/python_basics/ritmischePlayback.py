import pygame
import time

pygame.init()

Hihat = pygame.mixer.Sound('Hihat.wav')

# Rhythm list contains delay in note values (1 for quarter note)
rhythm = []
BPM = int(input("BPM: "))
numPlaybackTimes = int(input("How many notes: "))

# inputNumber = 1
# 
# for i in range(numPlaybackTimes) :
#     rhythm.append(input("Rhythm input ", inputNumber, ": "))
#     inputNumber+=1


BPM_toSeconds = 60/BPM  #hoe doe je dit in camelcap

print("Type 1 for a quarter note, 0.5 for an eight note etc.: ")
      
for i in range(numPlaybackTimes) :
    rhythm.append(float(input("Rhythm input: ")) * BPM_toSeconds )


for delay in rhythm:
    play_obj = Hihat.play()
    time.sleep(delay)

rhythm.clear()
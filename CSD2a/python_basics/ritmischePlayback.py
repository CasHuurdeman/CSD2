import pygame
import time

pygame.init()

Hihat = pygame.mixer.Sound('Hihat.wav')

# Rhythm list contains delay in seconds
rhythm = []
BPM = int(input("BPM: "))
numPlaybackTimes = int(input("How many notes: "))

inputNumber = 1

bpmToSeconds = 60/BPM

print("Type 1 for a quarter note, 0.5 for an eight note etc.")

#calculates and pushes the note values in seconds into rhythm     
for i in range(numPlaybackTimes) :
    rhythm.append(float(input(f"Rhythm input {inputNumber}: ")) * bpmToSeconds )
    inputNumber+=1

# loop functie
loop = input("Do you want to (infinitly) loop this rhythm? (yes/no):")

if loop == "yes":
    loopBool = True
else: loopBool = False


while loopBool == True :
    for delay in rhythm:
        play_obj = Hihat.play()
        time.sleep(delay)
else:    
    for delay in rhythm:
        play_obj = Hihat.play()
        time.sleep(delay)

    

rhythm.clear()
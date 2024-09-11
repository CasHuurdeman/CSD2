import pygame
import time

pygame.init()

rhythm = []

# Rhythm list contains delays in seconds
rhythm.append(1)
rhythm.append(0.5)
rhythm.append(1)

Hihat = pygame.mixer.Sound('Hihat.wav')

for delay in rhythm:
    play_obj = Hihat.play()
    time.sleep(delay)

numberOfRepeats = int(input("Aantal herhalingen"))

for i in range(numberOfRepeats):
    play_obj = Hihat.play()
    time.sleep(0.5)

play_obj.wait_done()
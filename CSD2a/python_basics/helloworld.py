# username = input("What is your name: ")

# print("Hello", username)


BPM = 120
barLength = 240/BPM  #in seconden



def generateTimestamps(numNotes, growthFactor):

    growthFactorList = []


    for i in range(numNotes):
        growthFactorList.append(growthFactor**i)

    initLength = barLength/(sum(growthFactorList))
    print(sum(growthFactorList))

    timestamps = []
    durations = []
    summ = 0

    for i in range (numNotes):
        initLength *= growthFactor
        durations.append(initLength)

        timestamps.append(summ)
        summ = summ + durations[i]

    return timestamps

print(generateTimestamps(55,0.8))
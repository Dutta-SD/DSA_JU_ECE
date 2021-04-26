import random

NUM_RANDOM_NUMBERS = 10000
MAX_RANDOM_NUMBER = 20000
PS_UPPER_LIMIT = 0.45

random.seed(42)

# Implementation of Knuth Shuffle for partial sorting
def shuffle_slice(arr, start, stop):
    i = start
    while (i < stop-1):
        idx = random.randrange(i, stop)
        arr[i], arr[idx] = arr[idx], arr[i]
        i += 1

    return arr

# Completely unsorted file
with open("CompletelyUnsorted.input", "w") as file:
    randomNumbers = [str(random.randint(0, MAX_RANDOM_NUMBER)) for _ in range(NUM_RANDOM_NUMBERS)]
    randomString = ' '.join(randomNumbers)
    file.write(str(len(randomNumbers)) + "\n")
    file.write(randomString)

random.seed(42)

# Partially Sorted Data
with open("PartiallySorted.input", "w") as file:
    randomNumbers = [str(random.randint(0, MAX_RANDOM_NUMBER)) for _ in range(NUM_RANDOM_NUMBERS)]
    randomNumbers.sort(key = lambda x : int(x))

    stop = int(PS_UPPER_LIMIT * len(randomNumbers))
    randomNumbers = shuffle_slice(randomNumbers, 0, stop)

    randomString = ' '.join(randomNumbers)
    file.write(str(len(randomNumbers)) + "\n")
    file.write(randomString)
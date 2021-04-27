import random

NUM_RANDOM_NUMBERS = 500000
MAX_RANDOM_NUMBER = 20000

random.seed(42)

# Sorted Array for searching
with open("InputNumbers.input", "w") as file:
    randomNumbers = [str(random.randint(0, MAX_RANDOM_NUMBER)) for _ in range(NUM_RANDOM_NUMBERS)]
    randomNumbers.sort(key = int)
    randomString = ' '.join(randomNumbers)
    file.write(str(len(randomNumbers)) + "\n")
    file.write(randomString)
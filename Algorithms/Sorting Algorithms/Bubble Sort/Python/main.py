import sys
import random

def main(argv):
    sizeOfArray = int(sys.argv[1])
    unsortedArray = [0]*sizeOfArray
    
    for index in range(sizeOfArray):
        unsortedArray[index] = random.randrange(1,100,1)
    print(unsortedArray)
    sortArray(unsortedArray, sizeOfArray)
    print(unsortedArray)

def sortArray(unsortedArray, sizeOfArray):
    for index in range(sizeOfArray):
        for index in range(sizeOfArray - 1):
            if (unsortedArray[index] > unsortedArray[index + 1]):
                temp = unsortedArray[index + 1]
                unsortedArray[index + 1] = unsortedArray[index]
                unsortedArray[index] = temp

if __name__ == "__main__":
    main(sys.argv[1:])

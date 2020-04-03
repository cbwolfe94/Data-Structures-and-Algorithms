import sys
import random

def main(argv):
    sizeOfArray = int(sys.argv[1])
    unsortedArray = [0]*sizeOfArray

    for index in range(sizeOfArray):
        unsortedArray[index] = random.randrange(1, 100, 1)
    
    print(unsortedArray)
    sortArray(unsortedArray, sizeOfArray)
    

def sortArray(unsortedArray, sizeOfArray):
    for index in range(1,sizeOfArray):
        element = unsortedArray[index]
        decrement = index - 1
        while decrement >= 0 and unsortedArray[decrement] > element:
            unsortedArray[decrement + 1] = unsortedArray[decrement]
            decrement -= 1

        unsortedArray[decrement + 1] = element 
    print(unsortedArray)

if __name__ == "__main__":
    main(sys.argv[1:])

import sys
import random


def partition(unsortedArray, low, high):
    pivot = unsortedArray[high]
    smallerElementIndex = low - 1

    for index in range(low, high, 1):
        if (unsortedArray[index] < pivot):
            smallerElementIndex += 1
            unsortedArray[smallerElementIndex], unsortedArray[index] = unsortedArray[index], unsortedArray[smallerElementIndex]
    unsortedArray[smallerElementIndex + 1],unsortedArray[high] = unsortedArray[high], unsortedArray[smallerElementIndex + 1]
    return smallerElementIndex + 1


def quickSort(unsortedArray, low, high):
    if (low < high):
        partitionIndex = partition(unsortedArray, low, high)
        quickSort(unsortedArray, low, partitionIndex - 1)
        quickSort(unsortedArray, partitionIndex + 1, high)



def main(argv):
    sizeOfArray = int(sys.argv[1])
    unsortedArray = [0]*sizeOfArray

    for index in range(sizeOfArray):
        unsortedArray[index] = random.randrange(1, 100, 1)

    print(unsortedArray)
    quickSort(unsortedArray, 0, sizeOfArray - 1)
    print(unsortedArray)

if __name__ == '__main__':
    main(sys.argv[1:])

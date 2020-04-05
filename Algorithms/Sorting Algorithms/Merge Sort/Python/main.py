import sys
import random

def main(argv):
    sizeOfArray = int(sys.argv[1])
    unsortedArray = [0]*sizeOfArray

    for index in range(sizeOfArray):
        unsortedArray[index] = random.randrange(1, 100, 1)

    print(unsortedArray)
    mergeSort(unsortedArray)
    print(unsortedArray)


def mergeSort(unsortedArray):
    if len(unsortedArray) > 1:
        middle = len(unsortedArray) // 2
        leftArray = unsortedArray[:middle]
        rightArray = unsortedArray[middle:]

        mergeSort(leftArray)
        mergeSort(rightArray)
        leftIndex = rightIndex = mainIndex = 0
        while leftIndex < len(leftArray) and rightIndex < len(rightArray):
            if leftArray[leftIndex] <= rightArray[rightIndex]:
                unsortedArray[mainIndex] = leftArray[leftIndex]
                leftIndex += 1
            else:
                unsortedArray[mainIndex] = rightArray[rightIndex]
                rightIndex += 1
            mainIndex += 1

        while leftIndex < len(leftArray):
            unsortedArray[mainIndex] = leftArray[leftIndex]
            leftIndex += 1
            mainIndex += 1
        while rightIndex < len(leftArray):
            unsortedArray[mainIndex] = rightArray[rightIndex]
            rightIndex += 1
            mainIndex += 1

if __name__ == '__main__':
    main(sys.argv[1:])

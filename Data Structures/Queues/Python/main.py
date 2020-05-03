class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.previous = None

class Queue:
    def __init__(self):
        self.topNode = None
        self.bottomNode = None

    def queue(self):
        data = input("Enter data to add to the queue: ")
        newNode = Node(data)
        newNode.next = self.topNode
        if self.topNode == None:
            self.bottomNode = newNode
            self.topNode = newNode

        else:
            self.topNode = newNode
            self.topNode.next.previous = self.topNode

    def dequeue(self):
        temp = self.bottomNode
        if self.topNode != self.bottomNode:
            self.bottomNode = self.bottomNode.previous
            self.bottomNode.next = None
            del temp

        else:
            self.bottomNode = None
            self.topNode = None
            del temp

    def peek(self):
        print("Data at the front of the queue is: ", self.bottomNode.data)

    def displayQueue(self):
        temp = self.topNode
        while(temp != None):
            print(temp.data)
            temp = temp.next

def main():
    queue = Queue()
    while(1):
        choice = input("Enter a 1 for queue, 2 for dequeue, 3 for peek, 4 for traverse and display queue, or 5 for exit. ")
        if choice == '1':
            queue.queue()

        elif choice == '2':
            queue.dequeue()

        elif choice == '3':
            queue.peek()

        elif choice == '4':
            queue.displayQueue()

        elif choice == '5':
            quit()

if __name__ == '__main__':
    main()

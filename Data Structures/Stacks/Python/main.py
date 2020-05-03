class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.topNode = None
        
    def push(self):
        data = input("Enter data to add to the stack: ")
        newNode = Node(data)
        newNode.next = self.topNode
        self.topNode = newNode
        
    def pop(self):
        temp = self.topNode
        self.topNode = self.topNode.next
        del temp

    def peek(self):
        print("Data at the top of the stack is: ", self.topNode.data)
    
    def displayStack(self):
        temp = self.topNode
        while(temp != None):
            print(temp.data)
            temp = temp.next

def main():
    stack = Stack()
    while(1):
        choice = input("Enter a 1 for push, 2 for pop, 3 for peek, 4 for traverse and display stack or 5 for exit. ")
        if choice == '1':
            stack.push()
        elif choice == '2':
            stack.pop()
        elif choice == '3':
            stack.peek()
        elif choice == '4':
            stack.displayStack()
        elif choice == '5':
            quit()

if __name__ == '__main__':
    main()
        

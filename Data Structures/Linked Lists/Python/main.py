class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
    
class LinkedList:
    def __init__(self):
        self.head = None

    def traverse(self):
        temp = self.head
        while (temp != None):
            print(temp.data)
            temp = temp.next



def main():
    head = Node(1)
    second = Node(2)
    third = Node(3)
    fourth = Node(4)
    

    head.next = second
    second.next = third
    third.next = fourth 
    
    llist = LinkedList()
    llist.head = head
    llist.traverse()


if __name__ == '__main__':
    main()

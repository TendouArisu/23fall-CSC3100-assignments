class Node():
    def __init__(self):
        self.count = 1
        self.node = {}

class Treenode():
    def __init__(self):
        self.root = Node()

    def insert(self, word):
        current = self.root
        for char in word:
            if current.node.get(char) is None:
                current.node[char] = Node()
            else:
                current.node[char].count += 1
            current = current.node[char]

    def search(self, word):
        current = self.root
        for char in word:
            if current.node.get(char) is None:
                return 0
            current = current.node[char]
        return current.count

Word = Treenode()
n = int(input())
pos = 0
list1 = []
while pos < n:
    temp = input()
    list1.append(temp)
    pos += 1
q = int(input())
pos = 0
list2 = []
while pos < n:
    temp = input()
    list2.append(temp)
    pos += 1
# list1 = ['wenwen','wenbl','blgg','wenx']
# list2 = ['wen','bl','csc','we']
for i in list1:
    Word.insert(i)
for i in list2:
    print(Word.search(i))
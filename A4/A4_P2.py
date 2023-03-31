class Heap():

    def __init__(self, heap=[]):
        self.heap = heap

    def maxheapify(self):
        for i in range((len(self.heap) + 1) // 2 - 1, -1, -1):
            self.max_heapify(i)

    def minheapify(self):
        a=0
        for i in self.heap:
            self.heap[a] = -i
            a += 1
        for j in range((len(self.heap) + 1) // 2 - 1, -1, -1):
            self.max_heapify(j)

    def printmaxheap(self):
        for i in self.heap:
            print(i, end=' ')

    def printminheap(self):
        for i in self.heap:
            print(-i, end=' ')

    def max_heapify(self, i):
        l = i*2 + 1
        r = i*2 + 2
        if l < len(self.heap) and self.heap[l] > self.heap[i]:
            large = l
        else:
            large = i
        if r < len(self.heap) and self.heap[r] > self.heap[large]:
            large = r
        if large != i:
            self.heap[large], self.heap[i] = self.heap[i], self.heap[large]
            self.max_heapify(large)

    def max_heapify_node(self, i):
        pre = (i + 1) // 2 - 1
        if pre >= 0 and self.heap[pre] < self.heap[i]:
            small = pre
        else:
            small = i

        if small != i:
            self.heap[small], self.heap[i] = self.heap[i], self.heap[small]
            self.max_heapify_node(small)

    def pop(self):
        self.heap[0], self.heap[len(self.heap) - 1] = self.heap[len(self.heap) - 1], self.heap[0]
        value = self.heap.pop()
        self.max_heapify(0)
        return value

    def push(self, value):
        self.heap.append(value)
        self.max_heapify_node(len(self.heap) - 1)

temp = input().split()
m = int(temp[0])
k = int(temp[1])
klist = input().split()
pos=0
for i in klist:
    klist[pos]=int(i)
    pos += 1
klist.sort()
pos=0
max = Heap([-1])
min = Heap([1])
min.pop()
max.pop()
totalnum = 2*k
while pos < m:
    pos += 1
    temp = input().split()
    num1 = int(temp[0])
    if num1 == 1:
        num2 = int(temp[1])
        if totalnum%2 == 0:
            if num2 < klist[0]:
                max.push(num2)
            elif num2 > klist[-1]:
                min.push(-num2)
                tnum = -min.pop()
                tnum2 = klist.pop(0)
                klist.append(tnum)
                klist.sort()
                max.push(tnum2)
            else:
                tnum = klist.pop(0)
                klist.append(num2)
                klist.sort()
                max.push(tnum)
        if totalnum%2 == 1:
            if num2 > klist[-1]:
                min.push(-num2)
            elif num2 < klist[0]:
                max.push(num2)
                tnum = max.pop()
                tnum2 = klist.pop()
                klist.insert(0,tnum)
                min.push(-tnum2)
            else:
                tnum = klist.pop()
                klist.append(num2)
                klist.sort()
                min.push(-tnum)
        totalnum += 1
    elif num1 == 2:
        for i in klist:
            if i == klist[0]:
                print(i, end='')
                continue
            print(' ',i, end='',sep='')
        print('')
    elif num1 == 3:
        num2 = int(temp[1])
        del klist[num2-1]
        if totalnum%2 == 0:
            tnum = -min.pop()
            klist.append(tnum)
        if totalnum%2 == 1:
            tnum = max.pop()
            klist.insert(0, tnum)
        totalnum -= 1
from math import log2
from math import floor
input = int(input())
def function(num):
    new = num
    store = []
    while new > 0:
        x = floor(log2(new))
        new = new - 2**x
        store.append(x)
    time = 0
    for i in store:
        if i == 1:
            print('2',end='')
        elif i != 2 and i != 0:
            print('2(',end='')
            function(i)
            print(')',end='')
        else:
            print(f'2({i})',end='')
        time += 1
        if time < len(store):
            print('+',end='')
function(input)
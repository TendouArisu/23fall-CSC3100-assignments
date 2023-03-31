from math import floor
n = int(input())
a = input().split(' ')
print(a)
time = 0
while time < n:
    a[time] = int(a[time])
    time += 1
def merge(A, p, q, mid):
    num1 = q - p + 1
    num2 = mid - q
    L, R = [], []
    i,j = 0,0
    while i < num1:
        L.append(A[p + i])
        i+=1
    while j < num2:
        R.append(A[q+j+1])
        j+=1
    L.append(10**7)
    R.append(10**7)
    i = 0
    j = 0
    inversions = 0
    k = p
    while k <= mid:
        if L[i] < R[j]:
            A[k] = L[i]
            i += 1
        else:
            inversions = inversions - i + num1
            A[k] = R[j]
            j += 1
        k += 1
    return inversions
def count(A, p, mid):
    if p < mid:
        q = floor((p + mid)/2)
        L = count(A, p, q)
        R = count(A, q + 1, mid)
        inversions = merge(A, p, q, mid) + L + R
        return inversions
    return 0
print(count(a,0,n-1))
print(a)
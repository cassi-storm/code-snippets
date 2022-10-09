# cook your dish here
import math

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    c = [[0] * (n + 1) for __ in range(33)]
    for i, v in enumerate(a, start=1):
        po = 32
        for j in range(33): c[j][i] = c[j][i - 1]
        if v != 0: po = int(math.log(v, 2))
        c[po][i] += 1
    q = int(input())
    for i in range(q):
        l, r, x = map(int, input().split())
        po, l = 32, l - 1
        if x != 0: po = int(math.log(x, 2))
        print(r - l - (c[po][r] - c[po][l]))  

# and vs xor preprocessed query based 

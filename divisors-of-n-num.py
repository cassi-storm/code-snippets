# cook your dish here
n = 10 ** 5 + 1
a = [0] * n
for i in range(1, n):
    j = 1
    sm = 0
    while j * j <= i:
        if i % j == 0:
            if j * j == i and j % 2 == 1: sm += j
            else:
                if j % 2 == 1: sm += j
                if (i // j) % 2 == 1: sm += i // j
        j += 1
    a[i] = a[i - 1] + sm 
t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    print(a[r] - a[l - 1])

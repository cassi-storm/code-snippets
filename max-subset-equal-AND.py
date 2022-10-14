# cook your dish here
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    k = a[0]
    for i in a:
        k &= i
    count = 0
    for i in range(n - 1):
        if a[i] == k: continue
        a[i + 1] &= a[i]
        count += 1
    print(count + (a[-1] != k))

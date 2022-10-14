# cook your dish here
n = 10 ** 5 + 1
a = [[0] * n for _ in range(5)]
for i in range(2, n):
    for j in range(5): a[j][i] = a[j][i - 1]
    tp, ct = i, 0
    if tp % 2 == 0:
        ct += 1
        while tp % 2 == 0: tp //= 2
    j = 3
    while j * j <= tp:
        if tp % j == 0:
            ct += 1
            while tp % j == 0: tp //= j
        j += 2
    if tp > 2: ct += 1
    if ct < 6: a[ct - 1][i] += 1

t = int(input())
for _ in range(t):
    l, r, k = map(int, input().split())
    print(a[k - 1][r] - a[k - 1][l - 1])

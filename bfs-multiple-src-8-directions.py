# cook your dish here
from collections import deque

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = [0] * n
    maxi, dmax = 0, n * m + 1
    for i in range(n):
        a[i] = list(map(int, input().split()))
        maxi = max(maxi, max(a[i]))
    d = [[dmax] * m for __ in range(n)]
    q = deque()
    for i, row in enumerate(a):
        for j, v in enumerate(row):
            if v == maxi:
                q.append((i, j))
                d[i][j] = 0
    dr = [(1, 1), (-1, -1), (1, -1), (-1, 1), (0, 1), (1, 0), (0, -1), (-1, 0)]
    while len(q) > 0:
        x, y = q.popleft()
        for i, j in dr:
            i, j = x + i, y + j
            if -1 < i < n and -1 < j < m and d[x][y] + 1 < d[i][j]:
                d[i][j] = d[x][y] + 1
                q.append((i, j))
    res = 0
    for i in d:
        res = max(res, max(i))
    print(res)

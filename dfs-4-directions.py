# cook your dish here
from collections import deque

def bfs(x, y, k):
    a = [(0, 1), (1, 0), (0, -1), (-1, 0), (1, 1), (-1, -1), (-1, 1), (1, -1)]
    vi = [[0] * 8 for __ in range(8)]
    q = deque()
    q.append((x, y, 0))
    vi[x][y] = 1
    count = 1
    while len(q) > 0:
        xi, yi, ki = q.popleft()
        if ki < k:
            for i, j in a:
                i, j = i + xi, j + yi
                if -1 < i < 8 and -1 < j < 8 and vi[i][j] == 0:
                    vi[i][j] = 1
                    count += 1
                    q.append((i, j, ki + 1))
    return count


t = int(input())
for _ in range(t):
    x, y, k = map(int, input().split())
    x, y = x - 1, y - 1
    res = bfs(x, y, k)
    print(res)

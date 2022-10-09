# cook your dish here
from collections import deque

def dfs(n, graph, start):
    a = [10 ** 9] * n
    a[start] = 0
    q = deque()
    q.append((start, 0))
    while q:
        cnode, v = q.popleft()
        for node, wt in graph.get(cnode, []):
            if v + wt < a[node]:
                if wt: 
                    a[node] = v + 1
                    q.append((node, v + 1))
                else:
                    a[node] = v
                    q.appendleft((node, v))
    return a[n - 1] if a[n - 1] != 10 ** 9 else -1


t = 1
for i in range(t):
    n, m = map(int, input().split())
    graph = {}
    for i in range(n):
        graph[i] = {}
    for i in range(m):
        u, v = map(int, input().split())
        u, v = u - 1, v - 1
        if u == v: continue
        graph[u][v] = 0
        graph[v][u] = graph[v].get(u, 1)
    for i in range(n):
        graph[i] = list(graph[i].items())
    print(dfs(n, graph, 0))


# contains edge weight 0 or 1 

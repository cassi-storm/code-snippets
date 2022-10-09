# cook your dish here
import sys
sys.setrecursionlimit(10 ** 6)


def is_bipar(graph, color, root, c):
    if color[root] != -1:
        if color[root] != c: return False
        else: return True
    else: color[root] = c
    for i in graph.get(root, []):
        if not is_bipar(graph, color, i, c ^ 1):
            return False
    return True


t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    graph = {}
    for i in range(m):
        u, v = map(int, input().split())
        u, v = u - 1, v - 1
        graph[u] = graph.get(u, []) + [v]
        graph[v] = graph.get(v, []) + [u]
    color = [-1] * n
    flag = True
    for i in range(n):
        if color[i] == -1 and not is_bipar(graph, color, i, 0):
            flag = False
            break
    if flag: print('YES')
    else: print('NO')

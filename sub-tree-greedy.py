# cook your dish here
import sys
sys.setrecursionlimit(10 ** 6)

def dfs(tree, root, mini, a):
    if tree.get(root, '0') == '0': 
        mini[root] = a[root]
        return
    min_ = a[root]
    for i in tree[root]:
        dfs(tree, i, mini, a)
        min_ = min(min_, mini[i])
    mini[root] = min_


t = 1
for _ in range(t):
    p = list(map(int, input().split()))
    n, p = p[0], p[1:]
    a, p = p[:n], list(map(lambda x: x - 1, p[n:]))
    mini = [10 ** 9] * n
    tree = {}
    for i, v in enumerate(p):
        tree[v] = tree.get(v, []) + [i]
    root = tree[-2][0]
    dfs(tree, root, mini, a)
    max_ = -(10 ** 9)
    for i, j in zip(a, mini):
        max_ = max(max_, i - j)
    print(max_)

# cook your dish here
import sys
sys.setrecursionlimit(10 ** 6)


def get_height(root, tree, res):
    if not tree.get(root, []): return 1
    ht = [0] * (len(tree[root]) + 1)
    for i, v in enumerate(tree[root], start=1):
        ht[i] = get_height(v, tree, res)
    max1, max2 = 0, 0
    for i, v in enumerate(ht):
        if ht[max1] < v: max1 = i
    for i, v in enumerate(ht):
        if max1 != i and ht[max2] < v: max2 = i
    res[0] = max(res[0], ht[max1] + ht[max2])
    return ht[max1] + 1


t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1:
        print(0)
        continue
    par, tree = [0] * (n + 1), {}
    for i in range(n - 1):
        u, v = map(int, input().split())
        tree[u] = tree.get(u, []) + [v]
        par[v] = u
    root = 0
    for i, v in enumerate(par[1:], start=1):
        if v == 0: 
            root = i
    res = [0]
    get_height(root, tree, res)
    print(res[0])

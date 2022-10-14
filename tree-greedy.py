# cook your dish here
def dfs(tr, root, vls):
    if tr.get(root, '0') == '0':
        vls[root] = 1
        return
    count = 1
    for i in tr.get(root, []):
        dfs(tr, i, vls)
        count += vls[i]
    vls[root] = count

def dfs2(tr, root, r, a, v):
    if a[root] == 1:
        r.append(v[root])
        return
    for i in tr.get(root, []):
        dfs2(tr, i, r, a, v)
 

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = [0] * n
    tr = {}
    for i in range(n - 1):
        u, v, x = map(int, input().split())
        u, v = u - 1, v - 1
        tr[u] = tr.get(u, []) + [v]
        a[v] = x
    vls, r = [0] * n, []
    dfs(tr, 0, vls)
    dfs2(tr, 0, r, a, vls)
    r.sort(reverse=True)
    count, rn = 0, len(r)
    while count < rn:
        if n <= k: break
        n = n - r[count]
        count += 1
    if n > k: print(-1)
    else: print(count)

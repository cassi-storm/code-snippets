# cook your dish here
def union(u, v, a):
    ctu, ctv = 0, 0
    while u != a[u]: 
        u = a[u]
        ctu += 1
    while v != a[v]: 
        v = a[v]
        ctv += 1
    if u == v: return 0 
    if ctu < ctv: a[u] = v
    else: a[v] = u
    return 1
    
def find_par(x, a):
    if x == a[x]: return x
    t = find_par(a[x], a)
    a[x] = t
    return t


t = 1
for _ in range(t):
    n, q = map(int, input().split())
    count, a = n, list(range(n))
    for i in range(q):
        lt = input().split()
        if lt[0] == '3':
            print(count)
            continue
        tp, u, v = map(int, lt)
        u, v = u - 1, v - 1
        if tp == 1: 
            count -= union(u, v, a)
        elif tp == 2:
            up = find_par(u, a)
            vp = find_par(v, a)
            if up == vp: print('YES')
            else: print('NO')

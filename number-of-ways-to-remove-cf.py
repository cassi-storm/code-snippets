t = 1
for _ in range(t):
    n, m = map(int, input().split())
    sz = 200
    p = [1] * sz
    p[0] = p[1] = 0
    for i in range(2, sz):
        if not p[i]: continue
        for j in range(i * i, sz, i):
            p[j] = 0
    mod_ = 998244353
    mk, ans = 1, 1
    prod, total = 1, 0
    for i in range(1, n + 1):
        if i < sz and p[i]:
            prod *= i
        ans = (ans * (m // prod)) % mod_
        mk = (mk * m) % mod_
        total = (total + mk - ans) % mod_
    print(total)

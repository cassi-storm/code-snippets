# cook your dish here
t = int(input())
for _ in range(t):
    n, w = map(int, input().split())
    a = [0] * n
    for i in range(n):
        c, p, t = map(int, input().split())
        a[i] = (t, c * p)
    a.sort()
    b, c = [0] * n, [0] * n
    for i, v in enumerate(a): b[i], c[i] = v
    dp = [[0] * (w + 1), [0] * (w + 1)]
    for i in range(1, n + 1):
        for j in range(1, w + 1):
            if b[i - 1] > j: dp[i % 2][j] = dp[(i + 1) % 2][j]
            else: 
                dp[i % 2][j] = max(
                    c[i - 1] + dp[(i - 1) % 2][j - b[i - 1]], 
                    dp[(i - 1) % 2][j]
                )
    print(dp[n % 2][w])

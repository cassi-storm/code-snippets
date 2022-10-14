# cook your dish here
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = [0] * n
    for i in range(n):
        a[i] = int(input())
    a.sort()
    dp = [[False] * (m + 1), [False] * (m + 1)]
    dp[0][0] = dp[1][0] = True
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i - 1] > j: dp[i & 1][j] = dp[(i & 1) ^ 1][j]
            elif j < 2 * a[i - 1]: 
                dp[i & 1][j] = dp[(i & 1) ^ 1][j] or dp[i & 1][j - a[i - 1]]
            else:
                dp[i & 1][j] = dp[(i & 1) ^ 1][j] or dp[(i & 1) ^ 1][j - a[i - 1]]
    print('Yes' if dp[n & 1][m] else 'No')

# cook your dish here
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    memo = {}
    for num in a:
        while num % 2 == 0:
            memo[2] = memo.get(2, 0) + 1
            num //= 2
        i = 3
        while i * i <= num:
            while num % i == 0:
                memo[i] = memo.get(i, 0) + 1
                num //= i
            i += 2
        if num > 2: memo[num] = memo.get(num, 0) + 1
    res = 1
    for v in memo.values():
        res *= v + 1
    print(res)

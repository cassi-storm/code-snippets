from cmath import pi
from math import atan2


def grahum(a):
    min_ = min(a, key=lambda x: (x[1], x[0]))
    def dist(x, y): return (y[1] - x[1]) ** 2 + (y[0] - x[0]) ** 2

    def polar(x, y): return - \
        pi if x[1] == y[1] else atan2(y[1] - x[1], y[0] - x[0])

    def angle(x, y, z): return (z[1]-y[1]) * \
        (y[0]-x[0]) - (y[1]-x[1])*(z[0]-y[0]) <= 0

    a.sort(key=lambda x: (polar(min_, x), dist(min_, x)))
    hull = []
    for i in a:
        while len(hull) > 1 and angle(hull[-2], hull[-1], i):
            hull.pop()
        hull.append(i)
    return hull


n = int(input())
a = [0] * n
for i in range(n):
    a[i] = tuple(map(int, input().split()))
cds = grahum(a)
print(len(cds) + 1)
for i in cds:
    print(*i)
print(*cds[0])


	
'''

Input:
3
15
30 30
50 60
60 20
70 45
86 39
112 60
200 113
250 50
300 200
130 240
76 150
47 76
36 40
33 35
30 30
12
50 60
60 20
70 45
100 70
125 90
200 113
250 140
180 170
105 140
79 140
60 85
50 60
6
60 20
250 140
180 170
79 140
50 60
60 20

Output:
3
8
60 20
250 50
300 200
130 240
76 150
47 76
30 30
60 20
6
60 20
250 140
180 170
79 140
50 60
60 20
6
60 20
250 140
180 170
79 140
50 60
60 20

'''

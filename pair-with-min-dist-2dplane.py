def brute(a):
    d1 = abs(a[0][0] - a[1][0]) ** 2 + abs(a[0][1] - a[1][1]) ** 2
    if len(a) == 2:
        return a[0], a[1], d1
    d2 = abs(a[1][0] - a[2][0]) ** 2 + abs(a[1][1] - a[2][1]) ** 2
    d3 = abs(a[2][0] - a[0][0]) ** 2 + abs(a[2][1] - a[0][1]) ** 2
    if d1 <= d2 and d1 <= d3:
        return a[0], a[1], d1
    if d2 <= d1 and d2 <= d3:
        return a[1], a[2], d2
    if d3 <= d1 and d3 <= d2:
        return a[2], a[0], d3


def rec(ax, ay):
    n = len(ax)
    if n < 4:
        return brute(ax)
    m = ax[n // 2]
    ax_l, ax_r = ax[:n // 2], ax[n // 2:]
    ay_l, ay_r = [], []
    for p in ay:
        if p[0] <= m[0]:
            ay_l.append(p)
        else:
            ay_r.append(p)
    p1_l, p2_l, dl = rec(ax_l, ay_l)
    p1_r, p2_r, dr = rec(ax_r, ay_r)
    if dl < dr:
        p1, p2, d = p1_l, p2_l, dl
    else:
        p1, p2, d = p1_r, p2_r, dr
    band = [p for p in ay if m[0] - d < p[0] < m[0] + d]
    for i, p in enumerate(band):
        for j in range(i + 1, min(i + 7, len(band))):
            k = band[j]
            dt = abs(p[0] - k[0]) ** 2 + abs(p[1] - k[1]) ** 2
            if dt < d:
                p1, p2, d = p, band[j], dt
    return p1, p2, d


def find(a):
    ax = sorted(a, lambda x: x[0])
    ay = sorted(a, lambda x: x[1])
    return rec(ax, ay)


if __name__ == '__main__':
    n = int(input())
    a = [map(int, input().split()) for _ in range(n)]
    ans = find(a)
    print(ans)

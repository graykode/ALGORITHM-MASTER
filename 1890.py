n = int(input())
a = []
for _ in range(n):
    a.append(list(map(int, input().split())))
d = [[0] * n for _ in range(n)]
d[0][0] = 1
for i in range(n):
    for j in range(n):
        if i == n-1 and j == n-1:
            break
        if d[i][j] != 0 and a[i][j] != 0:
            if i + a[i][j] < n:
                d[i + a[i][j]][j] += d[i][j]
            if j + a[i][j] < n:
                d[i][j + a[i][j]] += d[i][j]
print(d[n-1][n-1])

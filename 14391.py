n, m = map(int, input().split())
a = []
candidates = [i for i in range(n * m)]
for i in range(n):
    row = list(input())
    a.append(row)

aT = list(map(list, zip(*a)))

def calc(matrix, check, n, m, a):
    sum = 0
    for i in range(n):
        number = ''
        for j in range(m):
            if matrix[i][j] == check:
                number += a[i][j]
            else:
                if number != '':
                    sum += int(number)
                number = ''
        if number != '':
            sum += int(number)
    return sum


import itertools
ans = 0
for n_pick in range(n * m + 1):
    perms = itertools.combinations(candidates, n_pick)
    for perm in perms:
        index = 0
        matrix = [[False] * m for _ in range(n)]
        for p in perm:
            matrix[p//m][p%m] = True
        first = calc(matrix, True, n, m, a)

        matrixT = list(map(list, zip(*matrix)))
        second = calc(matrixT, False, m, n, aT)
        ans = max(ans, first+second)

print(ans)

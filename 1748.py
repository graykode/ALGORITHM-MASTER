# import sys
# sys.stdin = open('input.txt', 'r')

n = int(input())
i = 1
ans = 0
res = 0
while int('9' * i) < n:
    if i == 1:
        ans += 9
    else:
        ans += i * 9 * pow(10, i-1)
    res = pow(10, i)
    i += 1
if n > 9:
    print(ans + (n-res+1) * i)
else:
    print(n)

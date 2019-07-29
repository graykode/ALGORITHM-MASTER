#import sys
#sys.stdin = open('input.txt', 'r')

str = list(input())
dp = [[False] * (len(str)) for _ in range(len(str))]

for i in range(len(str)):
    dp[i][i] = True

for i in range(len(str)-1):
    if str[i] == str[i + 1]:
        dp[i][i+1] = True

for i in range(2, len(str)):
    for j in range(len(str) - i):
        if(str[j] == str[j + i] and dp[j+1][j+i-1]):
            dp[j][j+i] = True

ans = True
for i in range(len(str)):
    for j in range(i, len(str)):
        if dp[i][j] and (j-i)%2 == 1:
            ans = False

print('Odd.') if ans else print('Or not.')

n = int(input())
ls = list(map(int, input().split()))

_min = min(ls)
_max = max(ls)
Min, Max = [], []
for i in range(len(ls)):
    if ls[i] == _min:
        Min.append(i)
    if ls[i] == _max:
        Max.append(i)

Max.sort()
Min.sort()
ans = 1000000
import bisect
# bisect_left == lower_bound : ~이상 최소 index
# bisect_right == upper_bound : ~초과 최소 index
# 찾는 값이 모든 원소보다 클때는 len(list) return
for _min in Min:
    index = bisect.bisect_left(Max, _min)
    if index == len(Max):
        index = len(Max) - 1
    ans = min(ans, abs(_min - Max[index]) + 1)

for _max in Max:
    index = bisect.bisect_left(Min, _max)
    if index == len(Min):
        index = len(Min) - 1
    ans = min(ans, abs(_max - Min[index]) + 1)
print(ans)

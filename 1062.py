import itertools

char = []
words = []

n,k = map(int, input().split())
for i in range(n):
    str = input()
    words.append(set(str[4:-4]))
    char.extend([s for s in str])

if k < 5:
    print('0')
else:
    char = set(char)
    char -= set(['a', 'n', 't', 'i', 'c'])

    masks = itertools.combinations(list(char), min(k-5, len(char)))
    ans = 0
    for mask in masks:
        new_mask = set(set(['a', 'n', 't', 'i', 'c']).union(mask))
        cnt = 0
        for word in words:
            if word & new_mask == word:
                cnt += 1
        ans = max(ans, cnt)
    print(ans)

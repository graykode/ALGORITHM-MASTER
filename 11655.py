str = input()
ans = ''

for s in str:
    if 'a' <= s and s <= 'm':
        ans += chr(ord(s) + 13)
    elif 'n' <= s and s<= 'z':
        ans += chr(ord(s) - 13)
    elif 'A' <= s and s <= 'M':
        ans += chr(ord(s) + 13)
    elif 'N' <= s and s<= 'Z':
        ans += chr(ord(s) - 13)
    else:
        ans += s
print(ans)

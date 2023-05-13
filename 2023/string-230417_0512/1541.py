s = input()

s = s.split("-")
for i in range(len(s)):
    s[i] = sum(map(int, s[i].split("+")))

print(s[0] - sum(s[1:]))
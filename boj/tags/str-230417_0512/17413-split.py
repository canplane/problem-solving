s = input().replace(">", "<").split("<")

res = ""
for i in range(len(s)):
    res += ("<" + s[i] + ">") if i % 2 else " ".join([ e[::-1] for e in s[i].split()])
print(res)
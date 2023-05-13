s = input()

for pattern in [ "pi", "ka", "chu" ]:
    s = s.replace(pattern, "0")

def check(s):
    for c in s:
        if c != "0":
            return False
    return True
print("YES" if check(s) else "NO")        
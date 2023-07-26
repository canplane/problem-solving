s = input()
for _ in range(len(s) // 2): s = s.replace("()", "")
print(len(s))
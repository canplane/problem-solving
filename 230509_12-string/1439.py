s = list(input())
t = []
for c in s:
	if len(t) and c == t[-1]:	continue
	t.append(c)
x = t.count("0")
print(min(x, len(t) - x))
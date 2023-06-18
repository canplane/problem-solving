s = input().upper()

D = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
ans, cnt, valid = "A", s.count("A"), True
for d in D[1:]:
	c = s.count(d)
	if c > cnt:
		ans, cnt, valid = d, c, True
	elif c == cnt:
		valid = False

if valid:
	print(ans)
else:
	print("?")
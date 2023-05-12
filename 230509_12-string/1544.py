d = set()
def check(s):
	for k in d:
		if len(k) == len(s) and (s * 2).find(k) != -1:
			return False
	return True

res = 0
for _ in range(int(input())):
	s = input()
	if check(s):
		d.add(s)
		res += 1
print(res)
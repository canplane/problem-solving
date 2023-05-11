def f(s):
	li = [ 0 ] * 26
	for c in s:
		li[ord(c) - ord('a')] += 1 
	return tuple(li)

d = set()
for _ in range(int(input())):
	d.add(f(input()))
print(len(d))
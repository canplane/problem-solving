T = int(input())
for _ in range(T):
	s = input().split()
	while (t := input().split())[1] == "goes":
		t = t[2]
		while s.count(t):	s.remove(t)
	print(" ".join(s))
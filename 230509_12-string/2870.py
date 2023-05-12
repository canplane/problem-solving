M = int(input())

li = []
for _ in range(M):
	s = input()

	i = 0
	while i < len(s):
		j = i
		while j < len(s) and s[j].isdigit():
			j += 1
		if i != j:
			li.append(int(s[i:j]))
		i = j + 1

li.sort()
for e in li:
	print(e)
N = int(input())
s = input()

def check(t):
	for start in range(len(t)):
		if t[start] != s[0]:
			continue
		
		for step in range(1, len(t)):
			j = start + step; i = 1
			b = True
			while i < len(s):
				if not (j < len(t) and t[j] == s[i]):
					b = False
					break
				j += step; i += 1
			if b:
				return True
	return False

print(sum([ check(input()) for _ in range(N) ]))
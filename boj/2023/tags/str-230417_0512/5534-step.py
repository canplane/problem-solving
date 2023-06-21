N = int(input())
s = input()

def check(t):
	for start in range(len(t)):
		if t[start] == s[0]:
			for step in range(1, len(t)):
				if t[start::step][:len(s)] == s:
					return True
	return False

print(sum([ check(input()) for _ in range(N) ]))
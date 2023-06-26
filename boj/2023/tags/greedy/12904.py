S = input(); T = input()

def f(s, t):
	while len(s) < len(t):
		if t[-1] == "A":
			t = t[:-1]
		else:
			t = t[:-1][::-1]
	return s == t

print(int(f(S, T)))
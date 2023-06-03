N = int(input())
M = int(input())
A = []
if M > 0:
	A = list(map(int, input().split()))

def valid(x):
	X = list(map(int, str(x)))
	for x in X:
		for a in A:
			if x == a:
				return False
	return True

def lower():
	for x in range(N, -1, -1):
		if valid(x):
			return x
	return None

def upper():
	for x in range(N, 1000000):
		if valid(x):
			return x
	return None

ans = abs(N - 100)
lo = lower()
if lo != None:
	ans = min(ans, len(str(lo)) + (N - lo))
hi = upper()
if hi != None:
	ans = min(ans, len(str(hi)) + (hi - N))
print(ans)
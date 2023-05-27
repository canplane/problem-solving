import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args: sys.stdout.write(f"{' '.join(map(str, args))}\n")
####

A, P = map(int, input().split())

next = [None] * (1 + 500000)

k = A
while True:
	if next[k]:
		next[k] = None
		break
	else:
		k1 = sum(int(c) ** P for c in str(k))
		next[k] = k1
		k = k1

ans = 0
k = A
while (k := next[k]):
	ans += 1
print(ans)
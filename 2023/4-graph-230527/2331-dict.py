import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args: sys.stdout.write(f"{' '.join(map(str, args))}\n")
####

A, P = map(int, input().split())
idx = {}
i = 0; k = A
while k not in idx:
	idx[k] = i
	i += 1; k = sum(int(c) ** P for c in str(k))
print(idx[k])
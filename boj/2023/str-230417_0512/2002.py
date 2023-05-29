import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
enter = { input(): i for i in range(N) }
out = [ enter[input()] for _ in range(N) ]

ret = 0
for i in range(N):
	for j in range(i + 1, N):
		if out[i] > out[j]:
			ret += 1
			break
print(ret)
import sys
input = lambda: sys.stdin.readline().rstrip()

N, S = map(int, input().split())
A = list(map(int, input().split()))

def dfs(i, diff):
	ret = (diff == 0)
	for j in range(i, len(A)):
		ret += dfs(j + 1, diff - A[j])
	return ret
print(dfs(0, S) - (S == 0))
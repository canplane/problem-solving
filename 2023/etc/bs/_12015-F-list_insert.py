import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

bs = []
def find(key, l, r):
	if l == r:
		# FAILED: insert(): O(N)!! (cf. append(): O(1))
		bs.insert(l, [key, 1])
		return l

	m = (l + r) // 2
	if key == bs[m][0]:
		return -1
	else:
		if key < bs[m][0]:
			return find(key, l, m)
		else:
			return find(key, m + 1, r)

for i in range(N):
	idx = find(A[i], 0, len(bs))
	if idx > 0:
		bs[idx][1] += bs[idx - 1][1]
	#print(bs)

bs.sort(key=lambda x: x[1], reverse=True)
print(bs[0][1])
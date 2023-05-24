N, K = list(map(int, input().split()))

seg = [0] * (1 + 4 * N)
def init(l, r, i):
	if l + 1 == r:
		seg[i] = 1
	else:
		m = (l + r) // 2
		seg[i] = init(l, m, 2 * i) + init(m, r, 2 * i + 1)
	return seg[i]
def query(l, r, i, sum):
	seg[i] -= 1
	if l + 1 == r:
		return l
	m = (l + r) // 2
	if sum <= seg[2 * i]:
		return query(l, m, 2 * i, sum)
	else:
		return query(m, r, 2 * i + 1, sum - seg[2 * i])

init(1, 1 + N, 1)
ans = []; sum = seg[1]
while seg[1] > 0:
	sum = 1 + ((sum + K) - 1) % seg[1]
	ans.append(str(query(1, 1 + N, 1, sum))); sum -= 1
print(f"<{', '.join(ans)}>")
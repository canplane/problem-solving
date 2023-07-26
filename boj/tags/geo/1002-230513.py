'''
2023-05-14

if d = dist(A, B) > 0 (i.e., A != B) and r1, r2 >= 0,
the # of intersection is
	(1) 0	for r1 + r2 < d
	(2) 1	for r1 + r2 = d
	(3) 2	for r1 + r2 > d and |r2 - r1| < d
	(4) 1	for |r2 - r1| = d
	(5) 0	for |r2 - r1| > d
'''


T = int(input())
for i in range(T):
	x1, y1, r1, x2, y2, r2 = map(int, input().split())
	D = (x2 - x1) ** 2 + (y2 - y1) ** 2

	if D == 0:
		if r1 != r2:
			res = 0
		else:
			res = 1 if r1 == 0 else -1
	else:
		R12, R21 = (r2 + r1) ** 2, (r2 - r1) ** 2
		if R12 == D or R21 == D:
			res = 1
		elif R21 < D < R12:
			res = 2
		else:
			res = 0
	print(res)
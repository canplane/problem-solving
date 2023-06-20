# [1], [2 .. 7], [8 .. 19], [20 .. 37]
# 1, 6, 12, 18

N = int(input())
g, r = 1, 1
while True:
	if N <= r:
		print(g)
		break
	r += 6 * g
	g += 1
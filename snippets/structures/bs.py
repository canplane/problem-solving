'''
left == lower_bound
right + 1 == upper_bound
(x in [lower_bound, upper_bound))
'''
from bisect import bisect_left, bisect_right
left = bisect_left(bs, 2); right = bisect_right(bs, 2)
print(left, right)
left = bisect_left(bs, 2.5); right = bisect_right(bs, 2.5)
print(left, right)


# naive: bisect가 더 빠름
bs = [1, 2, 3, 4, 5]
lower_bound = None
def bound(l, r, key):
	global lower_bound
	while True:
		if l == r:
			lower_bound = l
			return -1
		
		m = (l + r) // 2
		if key == bs[m]:
			lower_bound = m
			return m
		else:
			if key < bs[m]:
				r = m
			else:
				l = m + 1

print(bound(0, len(bs), 2), lower_bound)
print(bound(0, len(bs), 2.5), lower_bound)
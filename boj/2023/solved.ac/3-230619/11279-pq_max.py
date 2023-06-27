import sys
input = lambda: sys.stdin.readline().rstrip()

# min heap in Python! (PriorityQueue is 10-30x slower than heapq)
import heapq
heap = []

N = int(input())
for _ in range(N):
	x = int(input())
	if x == 0:
		if len(heap) > 0:
			x = -heapq.heappop(heap)
		print(x)
	else:
		heapq.heappush(heap, -x)
import sys
input = lambda: sys.stdin.readline().rstrip()

T = int(input())
A = [ int(input()) for _ in range(T) ]

ans = []
def f():
	st = []
	cur = 1
	for a in A:
		while cur <= a:
			st.append(cur)
			cur += 1
			ans.append("+")
		if st.pop() == a:
			ans.append("-")
		else:
			return False
	return True
if f():
	print("\n".join(ans))
else:
	print("NO")
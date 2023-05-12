import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
ts = input().split("*")

def check(s):
	if len(ts) == 1:
		return s == ts[0]
	
	if ts[0] != "":
		if not s.startswith(ts[0]):
			return False
		s = s[len(ts[0]):]
	if ts[-1] != "":
		if not s.endswith(ts[-1]):
			return False
		s = s[:-len(ts[-1])]
	for i in range(1, len(ts) - 1):
		pos = s.find(ts[i])
		if pos == -1:
			return False
		s = s[(pos + len(ts[i])):]
	return True
	
for _ in range(N):
	s = input()
	print("DA" if check(s) else "NE")
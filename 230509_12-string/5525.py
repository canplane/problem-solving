N = int(input()) + 1
input()
S = input().replace("IO", "x").replace("xI", "xxi")

res = 0
l = 0
while l < len(S):
	r = l
	while r < len(S) and S[r] == "x":
		r += 1
	res += max(0, (r - l) - N + 1)
	l = r + 1
print(res)
'''
* 반례 :
330
4
0 1 2 3 
-> answer: 117

=> 그냥 완전탐색으로 풉시다.
'''

N = int(input())
M = int(input())
_D = list(map(int, input().split())) if M > 0 else []

def make_D(_D):
	li = [ not i in _D for i in range(10) ]
	D = []
	for d, b in enumerate(li):
		if b == True:
			D.append(d)
	return D
D = make_D(_D)

def encode(i, D):
	li = []
	if len(D) == 1:
		return int(str(D[0]) * (i + 1))
	else:
		while True:
			li.append(D[i % len(D)])
			i //= len(D)
			if i == 0:
				break
		return int("".join(map(str, li[::-1])))

ans = abs(N - 100)
if D == [0]:
	ans = min(ans, 1 + (N - 0))		
elif len(D) > 0:
	i = 0; n = encode(i, D)
	while n < N:
		ans = min(ans, len(str(n)) + (N - n))
		i += 1; n = encode(i, D)
		print(n)
	ans = min(ans, len(str(n)) + (n - N))

print(ans)
444
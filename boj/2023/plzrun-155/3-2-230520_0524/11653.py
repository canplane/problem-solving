import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args, sep=" ", end="\n": sys.stdout.write(f"{sep.join(map(str, args))}{end}")
####


N = int(input())
i = 2
while N > 1:
	while N % i:
		i += 1
	N //= i
	print(i)
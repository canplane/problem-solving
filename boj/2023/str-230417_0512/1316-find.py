N = int(input())
ret = sum(list(s := input()) == sorted(s, key=s.find) for _ in range(N))
print(ret)
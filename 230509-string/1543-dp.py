s = input()
p = input()

memo = [ 0 ] * (len(s) + len(p))

i = len(s) - 1
while i >= 0:
    if s.startswith(p, i):
        memo[i] = 1 + memo[i + len(p)]
        for j in range(1, len(p)):
            memo[i] = max(memo[i], memo[i + j])
    else:
        memo[i] = memo[i + 1]
    i -= 1
print(memo[0])
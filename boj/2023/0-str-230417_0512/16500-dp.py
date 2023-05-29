S = input()
A = [ input() for _ in range(int(input())) ]

memo = [ 0 ] * (len(S) + 1)
memo[0] = 1
for i in range(1, len(S) + 1):
    for a in A:
        if S[(i - len(a)):i] == a and memo[i - len(a)]:
            memo[i] = 1
print(memo[len(S)])
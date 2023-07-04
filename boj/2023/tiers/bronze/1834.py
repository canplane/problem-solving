# a = Nq + r = (N + 1)q
# 0 <= (r = q) < N
# (N + 1)(1 + 2 + ... + (N - 1)) = (N + 1)N(N - 1) / 2

N = int(input())
print((N - 1) * N * (N + 1) // 2)
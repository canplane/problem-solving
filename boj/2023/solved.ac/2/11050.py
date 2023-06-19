from math import factorial as fact

N, K = map(int, input().split())
binom = fact(N) // (fact(N - K) * fact(K))
print(binom)
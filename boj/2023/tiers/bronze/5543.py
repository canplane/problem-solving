def f(n): return [ int(input()) for _ in range(n) ]
A, B = f(3), f(2)
print(min(A) + min(B) - 50)
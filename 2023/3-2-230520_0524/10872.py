from functools import reduce
from operator import mul
print(reduce(mul, range(1, int(input()) + 1), 1))

# math.factorial(N)
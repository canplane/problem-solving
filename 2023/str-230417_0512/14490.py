# math.gcd()
def gcd(a, b): return gcd(b, a % b) if b else a

a, b = map(int, input().split(":"))
g = gcd(a, b)
print(f"{a // g}:{b // g}")
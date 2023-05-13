def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(a, b):
    GCD = gcd(a, b)
    return int(a * b / GCD)


s = input()
t = input()

LCM = lcm(len(s), len(t))
s *= int(LCM / len(s))
t *= int(LCM / len(t))
print(1 if s == t else 0)
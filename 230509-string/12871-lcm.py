def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcd(a, b):
    GCD = gcd(a, b)
    return int(a * b / GCD)


s = input()
t = input()

LCD = lcd(len(s), len(t))
s *= int(LCD / len(s))
t *= int(LCD / len(t))
print(1 if s == t else 0)
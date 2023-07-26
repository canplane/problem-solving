s = input()
t = input()

ll = len(s) * len(t)
s *= int(ll / len(s))
t *= int(ll / len(t))
print(1 if s == t else 0)

'''
aba, abab -> 0
'''
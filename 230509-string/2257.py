s = input()

res = 0
stack = []
for c in s:
    if c.isdigit():
        stack.append(stack.pop() * int(c))
    elif c == ")":
        n = 0
        while True:
            d = stack.pop()
            if d == "(":    break
            n += d
        stack.append(n)
    elif c == "H":
        stack.append(1)
    elif c == "C":
        stack.append(12)
    elif c == "O":
        stack.append(16)
    else:   # "("
        stack.append(c)
print(sum(stack))
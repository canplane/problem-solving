r, b = 0, 0
for c in input():
    r += (c == ")" and b == 0)
    b += (c == "(") - (c == ")" and b > 0)
print(r + b)
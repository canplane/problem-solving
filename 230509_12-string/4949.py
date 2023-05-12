import sys
lines = [x.rstrip() for x in sys.stdin.readlines()]

def check(s):
    stack = []
    for c in s:
        if c == "(" or c == "[":
            stack.append(c)
        elif c == ")" and not (len(stack) > 0 and stack.pop() == "("):
            return False
        elif c == "]" and not (len(stack) > 0 and stack.pop() == "["):
            return False
    return len(stack) == 0

for s in lines:
    if s == ".": break
    print("yes" if check(s) else "no")    
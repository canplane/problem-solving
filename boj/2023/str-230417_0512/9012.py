N = int(input())

def check(s):
    stack = []
    for c in s:
        if c == "(":
            stack.append(c)
        elif c == ")" and not (len(stack) > 0 and stack.pop() == "("):
            return False
    return len(stack) == 0   

for _ in range(N):
    s = input()
    print("YES" if check(s) else "NO")
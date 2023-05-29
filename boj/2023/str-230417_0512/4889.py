import sys

def cost(s):
    inv = 0
    bias = 0

    '''
    while len(s) > 0:
        c, *s = s   # 이게 더 느림 (264ms vs 48ms)
        if c == '}':
            bias -= 1
        elif c == '{':
            bias += 1
        
        if bias == -1:
            bias = 1
            inv += 1
    '''

    for i in range(len(s)):
        if s[i] == '}':
            bias -= 1
        elif s[i] == '{':
            bias += 1
        
        if bias == -1:
            bias = 1
            inv += 1
    
    return inv + int(bias / 2)

for i, s in enumerate(sys.stdin.readlines()):
    s = s.rstrip()

    if s[0] == '-':
        break

    print(f"{i + 1}. {cost(s)}")
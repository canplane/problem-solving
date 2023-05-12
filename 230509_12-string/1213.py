'''
2n개인 글자는 at most 1 
'''

def check(s):
    words = {}
    for c in s:
        if c not in words:
            words[c] = 0
        words[c] += 1

    odd = None
    for k in words:
        if words[k] % 2 == 1:
            if odd:
                return "I'm Sorry Hansoo"
            odd = k
    
    if odd:
        words[odd] -= 1
    wl = sorted(words.items())

    s = ""
    for a, n in wl:
       s += a * int(n / 2)
    return s + (odd if odd else "") + s[::-1]

print(check(input()))
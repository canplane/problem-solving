def check(s):
    pos = -1
    for c in ["U", "C", "P", "C"]:
        pos = s.find(c, pos + 1)
        if pos == -1:
            return False
    return True

s = input()
print(f"I {'love' if check(s) else 'hate'} UCPC")
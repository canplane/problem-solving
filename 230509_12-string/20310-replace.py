s = input()
print(s.replace("1", "", s.count("1") // 2)[::-1].replace("0", "", s.count("0") // 2)[::-1])
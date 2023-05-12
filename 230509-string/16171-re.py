import re
s = re.sub(r"\d+", "", input())
print(int(s.find(input()) != -1))
s=input()
rs=s[::-1]
l=len(s)
for i in range(l):
	if s[i:l]==rs[0:l-i]:
		print(l+i)
		break
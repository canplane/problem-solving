while True:
	s = input()
	if s == "0":
		break
	pal = True
	for i in range(len(s) // 2):
		if s[i] != s[(len(s) - 1) - i]:
			pal = False
	print("yes" if pal else "no")
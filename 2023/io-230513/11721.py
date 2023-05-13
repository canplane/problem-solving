s = input()
i = 0
while (t := s[i:(i + 10)]):
	print(t)
	i += 10
# print("\n".join([ s[i:(i + 10)] for i in range(0, len(s), 10) ]))
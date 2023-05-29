for i in range(int(input())):
	s = input().lower()
	p = min(3, min(s.count(chr(n)) for n in range(97, 123)))
	print(f"Case {i + 1}: {[ 'Not a p', 'P', 'Double p', 'Triple p' ][p]}angram{'!' * p}")
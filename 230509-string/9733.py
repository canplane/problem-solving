d = { k: 0 for k in [ "Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex" ] }

D = 0
try:
	while True:
		for k in input().split():
			if k in d:
				d[k] += 1
			D += 1
except:
	pass

d["Total"] = D
for k in d:
	print(f"{k} {d[k]} {(d[k] / D):.2f}")
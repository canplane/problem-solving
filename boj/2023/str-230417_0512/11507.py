s = input()

card = { k: [False] * 13 for k in ['P', 'K', 'H', 'T'] }

i = 0
while i < len(s):
    c = s[i]
    xy = int(s[(i + 1):(i + 3)]) - 1
    if card[c][xy]:
        print("GRESKA")
        exit()
    card[c][xy] = True
    i += 3
    
for k in card:
    print(13 - sum(card[k]), end=" ")
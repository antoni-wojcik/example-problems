text = input()

word = ""

d = {}

if 'a' in d:
    print(1)

for letter in text:
    if letter != ' ':
        word += letter
    else:
        if word in d:
            print('a')
            d[word] += 1
        else:
            d[word] = 1
        word = ""

if word in d:
    print('a')
    d[word] += 1
else:
    d[word] = 1

print(d)
item_list = d.items()
for item in item_list:
    print(item)

import math

print(sum(range(101)))
x = 0
for i in range(101):
    x += i
print(x)
x = 0
i = 0
while i < 101:
    x += i
    i += 1
print(x)
x = int(input())
a = 0
for i in range(2, int(math.sqrt(x))+1):
    if x%i == 0:
        print('złożona',x,i)
        a = 1
        break
if a == 0:
    print('pierwsza')
p = float(input())
i = 0
suma = 0
while suma <= p:
    i += 1
    suma += 1/i
print(i)
s = 11
i = 0
x = int()
while x != s:
    x = int(input())
    if x < s:
        print('wieksza')
    elif x > s:
        print('mniejsza')
    i += 1
print('trafiono po', i, 'probach')

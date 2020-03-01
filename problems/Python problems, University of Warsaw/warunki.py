x = int(input('Podaj liczbe calkowita: '))
if x < 0 or x > 120:
    print('nieprawidlowy wiek')
elif x == 0:
    print('niemowle')
elif x < 18:
    print('dziecko')
else:
    print('dorosly')

y = int(input('Podaj liczbe calkowita: '))
print(y%7 == 0)

import math

def pierwiastki(a, b, c):
    if a == 0:
        print('Błędne dane: a==0')
        return
    d = b*b - 4*a*c
    if d < 0:
        print('Równanie nie ma pierwiastków')
        return
    s_d = math.sqrt(b*b - 4*a*c)
    print((-b + s_d)/(2*a))
    print((-b - s_d)/(2*a))

def silnia(n):
    if n > 0:
        return n * silnia(n-1)
    elif n==0:
        return 1
    else:
        return None

def pierwiastki_val(a, b, c):
    if a == 0:
        print('Błędne dane: a==0')
        return None
    d = b*b - 4*a*c
    if d < 0:
        print('Równanie nie ma pierwiastków')
        return None
    s_d = math.sqrt(b*b - 4*a*c)
    return (-b + s_d)/(2*a), (-b - s_d)/(2*a)

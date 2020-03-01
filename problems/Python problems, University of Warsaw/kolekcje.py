def sumacyfr(n):
    suma = 0
    for c in str(n):
        suma += int(c)
    return suma

def sumacyfr2(n):
    return sum(int(c) for c in str(n))

def generator(n):
    return [sumacyfr(x) for x in range(n) if x%3 != 0]

def znajdzN(M):
    N = 0
    suma = 0
    while len(str(suma)) <= M:
        N += 1
        suma += N**3
    return N

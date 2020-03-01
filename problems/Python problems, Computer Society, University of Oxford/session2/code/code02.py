def double(x):
    return multiply(x, 2)
def multiply(x, y):
    return x*y

#print(double(3))

def palindrome(n):
    if n > 0:
        print(n)
        palindrome(n-1)
        print(n)
    else:
        print(0)

#palindrome(3)

def fib(n):
    if n < 2:
        return n
    else:
        return fib(n-1)+fib(n-2)
    
for i in range(1, 10):
    print(fib(i))


def fib2(n):
    a = 0
    b = 1
    while n != 0:
        c = a+b
        a = b
        b = c
        n = n-1
    return a

for i in range(0, 100):
    print(fib2(i))

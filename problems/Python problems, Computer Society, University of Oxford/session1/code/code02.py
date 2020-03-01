import math

number = int(input("Choose a number: "))
n = int(math.log2(100))+1

low = 1
high = 100

for i in range(0, n):
    guess = int((low + high)/2)
    print(low, high, guess, ' ')
    if guess < number:
        low = guess+1
    elif guess > number:
        high = guess-1
    if guess == number:
        print("Done! ", guess)
        break
    

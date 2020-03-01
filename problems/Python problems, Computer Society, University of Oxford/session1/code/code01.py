#name = input("What has a head and a tail but no legs?\n")
#if name == "A coin":
#    print("Well done!")
#else:
#    print("incorrect!")

#var = int(input("74 + 36"))
#if var == 74 + 36:
#    print("Well done!")
#else:
#    print("incorrect!")

import random
number = random.randint(0, 100)
for n in range(0, 7):
    guess  = int(input("What's your guess?"))
    if guess > number:
        print("Too high!")
    elif guess < number:
        print("Too low!")
    else:
        print("Just right!")
        break


#reverse the process (binary search)
